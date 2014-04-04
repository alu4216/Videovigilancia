#include "clientsocket.h"

//Constructor
ClientSocket::ClientSocket(QTcpSocket * tcpSocket,QObject *parent) :
    QObject(parent),tcpSocket_(tcpSocket)
{
    leer_cabecera_=false;
    leer_imagen_=false;
    leer_timestamp_=true;
    leer_size_string_=false;
    connect(tcpSocket_,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(tcpSocket_,SIGNAL(disconnected()),this,SLOT(deleteLater()));
}
//Destructor
ClientSocket::~ClientSocket()
{
    delete tcpSocket_;
}
//Leer datos del socket
void ClientSocket::readData()
{

    int *size;
    qint64 *tam;
    if(leer_timestamp_==true)//Leer tiempo
    {
        if(tcpSocket_->bytesAvailable()>=8)
        {
            data_=tcpSocket_->read(8);
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
        if((tcpSocket_->bytesAvailable())>=4)//Si existe los suficientes datos
        {
            data_=tcpSocket_->read(4);
            size=reinterpret_cast<int*>(data_.data());
            imagen_size_=*size;
            data_.clear();
            qDebug()<<"TAMAÑO IMAGEN: "<<imagen_size_;

            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=true;
            leer_timestamp_=false;
            leer_size_string_=false;

        }
    }//Estado leer imagen
    if(leer_imagen_ ==true)
    {
        if((tcpSocket_->bytesAvailable())>=imagen_size_)
        {
            data_=tcpSocket_->read(imagen_size_);
            QImage image;
            image.loadFromData(data_,"JPEG");
            qDebug()<<"IMAGEN "<<image;
            data_.clear();
            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=true;

            //Aquí se debería crear un hilo nuevo para guardar la imagen??? Cuando se envíen sólo las imágenes que han cambiado no hará falta
            guardarImagen(timestamp_, image);


            emit s_mostrar_captura(image);
        }
    }

    if(leer_size_string_==true)//Leer tamaño cadena
    {
        if(tcpSocket_->bytesAvailable()>=4)
        {
            data_=tcpSocket_->read(4);
            size=reinterpret_cast<int*>(data_.data());
            string_size_=*size;
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
        if(tcpSocket_->bytesAvailable()>=string_size_)
        {
            data_=tcpSocket_->read(string_size_);
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
bool ClientSocket::guardarImagen(qint64 timestamp, QImage imagen){
    qint32 szHx = 16;
    qint32 s1 = 4;
    qint32 s2 = 8;
    qint32 sI = 11;
    QString tt=QString::number(timestamp,szHx);
    tt.insert(s1, QString("/"));
    tt.insert(s2, QString("/"));
    tt.push_front("./");
    QString ttImage = tt;
    ttImage.push_back(".JPEG");
    tt.truncate(sI);
    qDebug() << tt;
    qDebug() << QDir::currentPath();
    //QString path = QString("%1/%2/").arg(tt).arg();
    QDir carpetaNueva;
    carpetaNueva.mkpath(tt);
    imagen.save(ttImage);
}
