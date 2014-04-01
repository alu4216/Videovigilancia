#include "viewerwindow.h"
#include "ui_viewerwindow.h"


//Constructor
ViewerWindow::ViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewerWindow)
{
    ui->setupUi(this);

    //variables de configuración del programa
    QSettings settings;
    indice_ = settings.value("indice").toInt();
    check_ = settings.value("check").toInt();
    ui->checkBox->setChecked(check_);
    settings.setValue("Network/Camara","Informática");
    //variables usadas en funciones
    camera_ = NULL;
    movie_ = NULL;
    preferencias_ = NULL;
    captureBuffer_ = NULL;
    dialog_ = NULL;
    conexion_=NULL;
    tcpsocket_ = NULL;
    devices_ = QCamera::availableDevices();
}
//Destructor
ViewerWindow::~ViewerWindow()
{
    delete ui;
    delete dialog_;
    delete preferencias_;
    delete camera_;
    delete captureBuffer_;
    delete tcpsocket_;
    delete conexion_;
}
//Cerrar el programa
void ViewerWindow::on_Salir_clicked()
{
    qApp->quit();
}
//Cerrar el programa
void ViewerWindow::on_actionSalir_triggered()
{
    qApp->quit();
}
//Abrir una imagen,mostrarla.
void ViewerWindow::on_actionAbrirImagen_triggered()
{
    if(movie_!=NULL)
    {
        delete movie_;
        movie_=NULL;
    }
    if(camera_!=NULL)
    {
        camera_->stop();
        delete camera_;
        camera_=NULL;
    }
    QString fileName=QFileDialog::getOpenFileName(this,"abrir archivo de imagen", QString());

    if(!fileName.isEmpty()) {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this,"Abrir archivo","El archivo no puedo ser abierto.");
        }
        else {
            QPixmap pixmap(fileName);
            ui->label->setPixmap(pixmap);
        }
    }
}
//Abrir vídeo
void ViewerWindow::on_actionAbrirVideo_triggered()
{
    if(movie_!=NULL)
    {
        delete movie_;
        movie_=NULL;
    }
    if(camera_!=NULL)
    {
        camera_->stop();
        delete camera_;
        camera_=NULL;
    }

    movie_= new QMovie();
    QString fileName=QFileDialog::getOpenFileName(this,"abrir archivo de video",QString(),"video(*.mjpeg)");
    movie_->setFileName(fileName);

    if (!movie_->isValid()) {
        QMessageBox::critical(this, tr("Error"),tr("No se pudo abrir el archivo o el formato"
                                                   " es inválido"));
        return;
    }
    else {
        if(ui->checkBox->checkState()==2) movie_->start();

        //coneccionóde señales
        connect(movie_, SIGNAL(updated(const QRect&)),this, SLOT(movie_frame(const QRect&)));
        connect(ui->push_Start, SIGNAL(clicked()), movie_, SLOT(start()));
        connect(ui->push_Stop, SIGNAL(clicked()), movie_, SLOT(stop()));
        connect(ui->Push_Pausa,SIGNAL(clicked()),this,SLOT(on_Push_Pausa_clicked()));
    }
}
//Pausar el vídeo o captura de imagenes
void ViewerWindow::on_Push_Pausa_clicked()
{
    if(movie_!=NULL)
        movie_->setPaused(true);
}
//Mosrar frame a frame el vídeo
void ViewerWindow::movie_frame(const QRect& )
{
    QPixmap pixmap = movie_->currentPixmap();
    ui->label->setPixmap(pixmap);
}
//Guardar el estado del checbox del formulario
void ViewerWindow::on_checkBox_stateChanged(int arg1)
{
    QSettings  settings;
    settings.setValue("check",arg1);
}
//Ventana de acerca de... Info de programa
void ViewerWindow::on_actionAcercaDe_triggered()
{
    dialog_ = new Acerca();
    dialog_->imagen();
    dialog_->exec();
}
//Capturar imagenes de la cámra
void ViewerWindow::on_actionCapturar_triggered()
{
    if(movie_!=NULL)
    {
        delete movie_;
        movie_=NULL;
    }

    camera_ = new QCamera(devices_[indice_]);
    captureBuffer_ = new CaptureBuffer();
    camera_->setViewfinder(captureBuffer_);
    camera_->start();
    //Conectar señales
    connect(captureBuffer_,SIGNAL(s_image(QImage)),this,SLOT(image_s(QImage)));
    connect(ui->push_Start,SIGNAL(clicked()),camera_,SLOT(start()));
    connect(ui->push_Stop,SIGNAL(clicked()),camera_,SLOT(stop()));

}
//Procesar los frame recibidos por la cam para mostrarlos y modificarlo(pintar sobre ellos)
void ViewerWindow::image_s(const QImage &image)
{
    //Procesar la image para poder pintar sobre ella la hora
    QTime time = QTime::currentTime();
    QString timeString = time.toString();
    QPixmap pixmap;
    pixmap=pixmap.fromImage(image);
    QPainter paint(&pixmap);
    paint.setPen(Qt::green);
    paint.drawText(0,0,pixmap.width(),pixmap.height(),Qt::AlignRight |Qt::AlignBottom ,timeString,0);
    ui->label->setPixmap(pixmap);

    if(tcpsocket_!=NULL)//Si hay una conexión abierta
    {
    //Procesar la imagen para enviarla por la red
    QBuffer buffer;//crea un buffer interno de tipo byte array donde guardar los bytes de las imagenes
    QImageWriter imageWriter(&buffer,"JPG"); // Nos permite utilizar una serie de manejadores
    // Y escribira los datos sobre buffer
    QImage imageSend; //creación de la imagen a enviar
    imageSend=pixmap.toImage(); // converción del pixmap pintando a una Qimagen
    imageWriter.setFormat("JPG"); // tipo de formato
    imageWriter.setCompression(70); // compresión del la imagen
    imageWriter.write(imageSend); // imagen sobre la cual aplicar las opciones anteriores y guardarla en buffer
    QByteArray bytes = buffer.buffer(); //acceder a los bytes almacenados en el buffer

    QSettings settings;
    //Struct de información total a enviar
    Package package;
    package.size=bytes.size();//Tamaño de la imagen en bytes
    package.image=bytes;//Imagen
    package.timestamp=QDateTime::currentMSecsSinceEpoch();//Tiempo
    package.name=settings.value("Network/Camara","INFO").toString();//Cadena a enviar
    package.size_string=package.name.size();//Tamaño de la cadena

    QByteArray array=package.name.toLatin1();//Conversión de la cadena para enviarla

    qDebug()<<package.size<<" "<<package.timestamp<< " "<<package.name<<
             " "<<package.size_string<< " "<<array.size()<<" " <<package.image;
    qDebug()<<"\n----------------------------------------------------------------";

    tcpsocket_->write(reinterpret_cast<char*>(&package.size),4);
    tcpsocket_->write(package.image,package.size);
    tcpsocket_->write(reinterpret_cast<char*>(&package.timestamp),8);
    tcpsocket_->write(reinterpret_cast<char*>(&package.size_string),4);
    tcpsocket_->write(array,array.size());

    }
}
//Ventana de preferencias de cámara.Seleccionar la cámara a utilizar
void ViewerWindow::on_actionPreferencias_triggered()
{
    preferencias_=new PreferenciaDialog(devices_);
    preferencias_->show();
    connect(preferencias_,SIGNAL(s_camera(int)),this,SLOT(actualizar_s(int)));
}
//Actualizar la cámara utilizada en el momento actual
void ViewerWindow::actualizar_s(int i)
{
    indice_=i;
    if(camera_!=NULL)
    {
        camera_->stop();
        delete camera_;
    }
    on_actionCapturar_triggered();
}

//Selección de la ip y puerto del servidor
void ViewerWindow::on_actionAjustes_Conexion_triggered()
{
    conexion_= new AjustesConexion();
    conexion_->show();
}
//Conectar con el servidor y activar el envío de datos
void ViewerWindow::on_actionComenzar_a_enviar_triggered()
{
    QSettings settings;
    QString ip = settings.value("Network/ip",QString("127.0.0.1")).toString();
    int puerto = settings.value("Network/puerto",15000).toInt();
    tcpsocket_ = new QTcpSocket(this);
    tcpsocket_->connectToHost(ip,puerto);
    connect(tcpsocket_,SIGNAL(connected()),this,SLOT(on_actionCapturar_triggered()));
}
