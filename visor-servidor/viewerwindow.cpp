#include "viewerwindow.h"
#include "ui_viewerwindow.h"

//Constructor
ViewerWindow::ViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewerWindow)
{
    ui->setupUi(this);
    db_= QSqlDatabase::addDatabase("QSQLITE");
    //variables de configuración del programa
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    indice_ = settings.value("indice").toInt();
    check_ = settings.value("check").toInt();
    ui->checkBox->setChecked(check_);

    //variables usadas en funciones
    camera_ = NULL;
    movie_ = NULL;
    preferencias_ = NULL;
    captureBuffer_ = NULL;
    dialog_ = NULL;
    sslServer_= NULL;
    capturaRed_= NULL;
    devices_ = QCamera::availableDevices();
    capture_s();
    qDebug()<<"ENTRO A viewer";
    //Asignación del nombre de la base de datos y creación de la tabla
    QString string=APP_DATADIR;
    string+="/data.sqlite";
    db_.setDatabaseName(string);
    if (!db_.open()) {
        QMessageBox::critical(NULL, tr("Error"),
                              tr("No se pudo acceder a los datos."));
    }
    QSqlQuery query;
    query.exec("create table if not exists Datos"
               "(id integer primary key autoincrement, "
               "host varchar(100), "
               "timestamp long, "
               "ruta varchar(200))");
    QSqlQuery query2;
    query2.exec("create table if not exists Rect"
                "(id integer, "
                "x long, "
                "y long, "
                "alto long, "
                "ancho long, "
                "idioteque integer primary key)");
}
//Destructor
ViewerWindow::~ViewerWindow()
{
    delete ui;
    delete dialog_;
    delete preferencias_;
    delete camera_;
    delete captureBuffer_;
    delete capturaRed_;
    delete sslServer_;
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
    //QFileDialog::getOpenFileName es un método estático por lo tanto no instanciamos un objeto
    //del tipo QFileDialog
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
//Abrir vídeo
void ViewerWindow::on_actionAbrirVideo_triggered()
{
    if(movie_!= NULL)
    {
        delete movie_;
        movie_= NULL;
    }
    if(camera_!= NULL)
    {
        camera_->stop();
        delete camera_;
        camera_= NULL;
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
    if(movie_!= NULL)
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
    if(movie_!= NULL)
    {
        delete movie_;
        movie_= NULL;
    }
    camera_ = new QCamera(devices_[indice_]);
    captureBuffer_ = new CaptureBuffer();
    camera_->setViewfinder(captureBuffer_);
    camera_->start();

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
    if(camera_!= NULL)
    {
        camera_->stop();
        delete camera_;
    }
    on_actionCapturar_triggered();
}
//Ventana de captura de red. Preferencias de la captura de red
void ViewerWindow::on_actionCaptura_de_Red_triggered()
{
    capturaRed_= new CapturaRed();
    capturaRed_->show();
    connect(capturaRed_,SIGNAL(s_capture()),this,SLOT(capture_s()));
}
//Inicio de la captura de red
void ViewerWindow::capture_s()
{
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    int puerto=settings.value("Puertos/puerto",15000).toInt();
    sslServer_= new SslServer();
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // Si no se encuentra ninguna aceptada, se utiliza la del localhost(127.0.0.1)
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    //Escucha peticiones
    if (!sslServer_->listen(QHostAddress::Any, puerto))
    {
        QMessageBox::critical(this, tr("Servidor"),
                              tr("Imposible iniciars conexión: %1.")
                              .arg(sslServer_->errorString()));
        close();
        return;
    }
    ui->label->setText(tr("El servidor está corriendo en la: \n\nIP: %1\nPuerto: %2\n\n"
                          "Envia imágenes ahora.").arg(ipAddress).arg(puerto));

}
//Muestra el guión de las consultas a la base de datos
void ViewerWindow::on_actionBase_de_datos_triggered()
{
    bddialog_ = new BDDialog();
    bddialog_->show();
}
