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
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
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
    sslSocket_ = NULL;
    estado_=false;
    devices_ = QCamera::availableDevices();

    //iniciar el servicio del demonio para el cliente:
    setupUnixSignalHandlers();

    settings.setValue("HOSTNAME", QHostInfo::localHostName());
    qRegisterMetaType< QVector<QRect> >("QVector<QRect>");// Registra QVector<QRect> como tipo en qt
    // para reconocerlo al hacer connect

    // Pasar la petición de procesar el frame
    connect(this, SIGNAL(Procesar_Imagen(const QImage &)),
            &imageProcesor_,SLOT(Procesador_imagen(const QImage &)));
    // Ser notificado cuando el frame ha sido procesado
    connect(&imageProcesor_, SIGNAL(Mandar_imagen(const QImage &,const QVector<QRect> &)),
            this,SLOT(image_s(const QImage&,const QVector<QRect> &)));

    imageProcesor_.moveToThread(&hilo_);// Migrar la instancia de imageProcesor al hilo de trabajo
    hilo_.start();// Iniciar el hilo de trabajo

    on_actionComenzar_a_enviar_triggered();
}
//Destructor
ViewerWindow::~ViewerWindow()
{
    delete ui;
    delete dialog_;
    delete preferencias_;
    delete camera_;
    delete captureBuffer_;
    delete sslSocket_;
    delete conexion_;
    imageProcesor_.cierre(true);
    hilo_.exit();
    hilo_.wait();
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

    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this,"Abrir archivo","El archivo no puedo ser abierto.");
        }
        else
        {
            QPixmap pixmap(fileName);
            ui->label->setPixmap(pixmap);
        }
    }
}
//Conectar al servidor
void ViewerWindow::on_actionAbrirVideo_triggered()
{
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    QString ip = settings.value("Network/ip",QString("127.0.0.1")).toString();
    int puerto = settings.value("Network/puerto",15000).toInt();

    if(sslSocket_==NULL)
    {
        sslSocket_ = new QSslSocket(this);
        //m_.setSslSocket(sslSocket_);
    }
    else
    {
        sslSocket_->disconnect();
        delete sslSocket_;
        sslSocket_ = new QSslSocket(this);
    }

    sslSocket_->setProtocol(QSsl::SslV3);
    sslSocket_->connectToHostEncrypted(ip,puerto);
    sslSocket_->ignoreSslErrors();
    connect(sslSocket_,SIGNAL(connected()),this,SLOT(abrirVideo()));
}
//Abrir vídeo
void ViewerWindow::abrirVideo()
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
    if (!movie_->isValid())
    {
        QMessageBox::critical(this, tr("Error"),tr("No se pudo abrir el archivo o el formato"
                                                   " es inválido"));
        return;
    }
    else
    {
        if(ui->checkBox->checkState()==2)
            movie_->start();

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
    //le manda al hilo la imagen para procesarla
    QImage img =movie_->currentImage();
    emit Procesar_Imagen(img);
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
    qDebug() << "entra en onactioncapturar";
    if(movie_!=NULL)
    {
        delete movie_;
        movie_=NULL;
    }
    if(captureBuffer_==NULL) captureBuffer_ = new CaptureBuffer();
    if(camera_==NULL)
    {
        camera_ = new QCamera(devices_[indice_]);
        camera_->setViewfinder(captureBuffer_);
        camera_->start();
    }
    qDebug()<<"conectado con el servidor";
    //Conectar señales
    connect(captureBuffer_,SIGNAL(s_image(const QImage&)),&imageProcesor_,SLOT(Procesador_imagen(const QImage &)));
    connect(ui->push_Start,SIGNAL(clicked()),camera_,SLOT(start()));
    connect(ui->push_Stop,SIGNAL(clicked()),camera_,SLOT(stop()));
}
//Procesar los frame recibidos por la cam para mostrarlos y modificarlo(pintar sobre ellos)
void ViewerWindow::image_s(const QImage &image,const QVector<QRect> &rectangulo)
{
    //Procesar la image para poder pintar sobre ella la hora
    QTime time = QTime::currentTime();
    QString timeString = time.toString();
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    QString name=settings.value("Network/Camara","INFO").toString();
    QPixmap pixmap;
    pixmap=pixmap.fromImage(image);
    QPainter paint(&pixmap);
    paint.setPen(Qt::green);
    paint.drawText(0,0,pixmap.width(),pixmap.height(),Qt::AlignRight |Qt::AlignBottom ,timeString,0);
    paint.drawText(0,0,pixmap.width(),pixmap.height(),Qt::AlignLeft,name,0);

    ui->label->setPixmap(pixmap);//mostrar imagen en el servidor
    if(sslSocket_!=NULL)
        send_data(pixmap,rectangulo);
}
//Enviar datos por el socket cifrado
void ViewerWindow::send_data(const QPixmap &pixmap,const QVector<QRect> &rectangulo)
{
    if (rectangulo.size() > 0)
    {
        if(sslSocket_->state()!=3) //reconectar camara al servidor
            reconectar();
        else //Lineas de código para enviar frame y metadatos al servidor
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
            //QSettings settings(APP_CONFFILE, QSettings::IniFormat);

            //Struct de información total a enviar
            Package package;
            package.size=bytes.size();//Tamaño de la imagen en bytes
            package.image=bytes;//Imagen
            package.timestamp=QDateTime::currentMSecsSinceEpoch();//Tiempo
            package.name=QHostInfo::localHostName();
            package.size_string=package.name.size();//Tamaño de la cadena
            package.size_vector=rectangulo.size();

            //Fuerzo los bytes de los enteros a enviar a LittleEndian
            package.size=qToLittleEndian(package.size);
            package.timestamp=qToLittleEndian(package.timestamp);
            package.size_string=qToLittleEndian(package.size_string);
            package.size_vector=qToLittleEndian(package.size_vector);

            //Reconversión de la cadena para enviar como ByteArray
            QByteArray array=package.name.toLatin1();//Conversión de la cadena para enviarla

            qDebug()<<package.size<<" "<<package.timestamp<< " "<<package.name<<
                      " "<<package.size_string<< " "<<array.size()<<" " <<package.image;
            qDebug()<<"\n----------------------------------------------------------------";

            //Lienas de código para enviar frame y metadatos al servidor
            sslSocket_->write(reinterpret_cast<char*>(&package.timestamp),sizeof(package.timestamp));
            sslSocket_->write(reinterpret_cast<char*>(&package.size),sizeof(package.size));
            sslSocket_->write(package.image,package.size);
            sslSocket_->write(reinterpret_cast<char*>(&package.size_string),sizeof(package.size_string));
            sslSocket_->write(array,array.size());
            sslSocket_->write(reinterpret_cast<char*>(&package.size_vector),sizeof(package.size_vector));
            for(int i=0; i<package.size_vector;i++)
            {
                QRect aux=rectangulo[i];
                qint32 x,y,ancho,alto;
                x=aux.x();
                y=aux.y();
                ancho=aux.width();
                alto=aux.height();
                x=qToLittleEndian(x);
                y=qToLittleEndian(y);
                ancho=qToLittleEndian(ancho);
                alto=qToLittleEndian(alto);
                qDebug()<<"CUADRADOS\n";
                qDebug()<<"X "<<x;
                qDebug()<<"Y "<<y;
                qDebug()<<"ANCHO "<<ancho;
                qDebug()<<"ALTO "<<alto;
                sslSocket_->write(reinterpret_cast<char*>(&x),sizeof(x));
                sslSocket_->write(reinterpret_cast<char*>(&y),sizeof(y));
                sslSocket_->write(reinterpret_cast<char*>(&ancho),sizeof(ancho));
                sslSocket_->write(reinterpret_cast<char*>(&alto),sizeof(alto));
            }
        }
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
//Conectar con el servidor y activar el envío de datos(camara)
void ViewerWindow::on_actionComenzar_a_enviar_triggered()
{
    qDebug() << "Comenzar a enviar";
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    QString ip = settings.value("Network/ip",QString("127.0.0.1")).toString();
    int puerto = settings.value("Network/puerto",15000).toInt();

    if(sslSocket_==NULL)
    {
        sslSocket_ = new QSslSocket(this);
        //m_.setSslSocket(sslSocket_);
    }
    else
    {
        sslSocket_->disconnect();
        delete sslSocket_;
        sslSocket_ = new QSslSocket(this);
    }
    sslSocket_->setProtocol(QSsl::SslV3);
    sslSocket_->connectToHostEncrypted(ip,puerto);
    sslSocket_->ignoreSslErrors();

    connect(sslSocket_,SIGNAL(encrypted()),this,SLOT(on_actionCapturar_triggered()));
}
//Reconectar con el servidor automáticamente
void ViewerWindow::reconectar()
{
    sslSocket_->disconnect();
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    QString ip = settings.value("Network/ip",QString("127.0.0.1")).toString();
    int puerto = settings.value("Network/puerto",15000).toInt();
    sslSocket_->setProtocol(QSsl::SslV3);
    sslSocket_->connectToHostEncrypted(ip,puerto);
    sslSocket_->ignoreSslErrors();
    connect(sslSocket_,SIGNAL(encrypted()),this,SLOT(on_actionCapturar_triggered()));
}
