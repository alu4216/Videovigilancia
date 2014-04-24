#include "clientsocket.h"

//Constructor
ClientSocket::ClientSocket(QSslSocket *sslSocket_, QObject *parent) :
    QObject(parent),sslSocket_(sslSocket_)
{
    db_.setDatabaseName("data.sqlite");
    if (!db_.open())
    {
        QMessageBox::critical(NULL, tr("Error"),
            tr("No se pudo acceder a los datos."));
    }
    leer_cabecera_=false;
    leer_imagen_=false;
    leer_timestamp_=true;
    leer_size_string_=false;

    connect(sslSocket_,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(sslSocket_,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(sslSocket_,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(mostrarErrores(QAbstractSocket::SocketError)));

    widget_=new QWidget();
    layout_= new QGridLayout(widget_);
    layout_->addWidget(&label_);
    label_.setScaledContents(true);
    mostrarImagen_=true;

}
//Destructor
ClientSocket::~ClientSocket()
{
    delete sslSocket_;
    //delete layout_;
    //delete widget_;
}
//Leer datos del socket
void ClientSocket::readData()
{
    int *size;
    qint64 *tam;
    if(leer_timestamp_==true)//Leer tiempo
    {
        if(sslSocket_->bytesAvailable()>=8)
        {
            data_=sslSocket_->read(8);
            tam=reinterpret_cast<qint64*>(data_.data());
            timestamp_=*tam;
            data_.clear();
            qDebug()<<"TIEMPO"<<timestamp_;

            //Estados de la lectura
            leer_cabecera_=true;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=false;
        }
    }

    //Estado leer cabecera(tamaño imagen)
    if(leer_cabecera_==true)
    {
        if((sslSocket_->bytesAvailable())>=4)//Si existe los suficientes datos
        {
            data_=sslSocket_->read(4);
            size=reinterpret_cast<int*>(data_.data());
            imagen_size_=*size;
            imagen_size_=qFromLittleEndian(imagen_size_);//Reconvierto bytes de LittleEndia al usado en el pc
            data_.clear();
            qDebug()<<"TAMAÑO IMAGEN: "<<imagen_size_;

            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=true;
            leer_timestamp_=false;
            leer_size_string_=false;

        }
    }
    //Estado leer imagen
    if(leer_imagen_ ==true)
    {
        if((sslSocket_->bytesAvailable())>=imagen_size_)
        {
            data_=sslSocket_->read(imagen_size_);
            QImage image;
            image.loadFromData(data_,"JPEG");
            data_.clear();
            QPixmap pixmap;
            pixmap=pixmap.fromImage(image);
            label_.setPixmap(pixmap);
            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=true;

            if(mostrarImagen_==true)//para que se habra la ventana inicialmente solo si
            {                       // hay imagenes que mostrar
                mostrarImagen_=false;
                //Abrir ventana para mostrar imagen
                widget_->show();
            }
            guardarImagen(timestamp_, image);
        }
    }

    if(leer_size_string_==true)//Leer tamaño cadena
    {
        if(sslSocket_->bytesAvailable()>=4)
        {
            data_=sslSocket_->read(4);
            size=reinterpret_cast<int*>(data_.data());
            string_size_=*size;
            string_size_=qFromLittleEndian(string_size_);//Reconvierto bytes de LittleEndia al usado en el pc
            qDebug()<<"TAMAÑO CADENA: "<<string_size_;
            data_.clear();

            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=false;
            leer_string_=true;
        }

    }
    if(leer_string_==true)//Leer cadena
    {
        if(sslSocket_->bytesAvailable()>=string_size_)
        {
            data_=sslSocket_->read(string_size_);
            string_=QString::fromLatin1(data_.data(),string_size_);
            qDebug()<<"CADENA: "<<string_;
            qDebug()<<"-------------------------------------------";
            data_.clear();

            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=true;
            leer_size_string_=false;
            leer_string_=false;
        }
    }
}
//Mostrar errores de conexión del socket
void ClientSocket::mostrarErrores(QAbstractSocket::SocketError )
{
    QString string=sslSocket_->errorString();
    qDebug()<<"Entro a mostrar Errores\n";
    qDebug()<<string;
    QMessageBox ventana;
    ventana.setWindowTitle("Mensaje de Error");
    ventana.setText(string);
    ventana.setStandardButtons(QMessageBox::Ok);
    ventana.exec();
    widget_->close();
}
//Guardar imagenes en directores segun el timestamp
void ClientSocket::guardarImagen(qint64 timestamp, QImage imagen){
    qint32 szHx = 16;
    qint32 s1 = 4;
    qint32 s2 = 8;
    qint32 sI = 11;
    QString tt=QString::number(timestamp,szHx);
    tt.insert(s1, QString("/"));
    tt.insert(s2, QString("/"));
    QString ttImage2 = tt;
    tt.push_front("./");
    QString ttImage = tt;
    ttImage.push_back(".JPEG");
    tt.truncate(sI);
    qDebug() << tt;
    qDebug() << QDir::currentPath();
    QDir carpetaNueva;
    carpetaNueva.mkpath(tt);
    imagen.save(ttImage);
    ttImage2.push_front("/");
    ttImage2.push_front(QDir::currentPath());

    //Almacenar en la base de datos.
    QSqlQuery query;
    query.prepare("INSERT INTO Datos (id, host, timestamp, ruta) "
                  "VALUES (:id, :host, :timestamp, :ruta)");
    query.bindValue(":id", timestamp);
    query.bindValue(":host", string_);
    query.bindValue(":timestamp", timestamp);
    query.bindValue(":ruta", ttImage2);
    query.exec();
}
