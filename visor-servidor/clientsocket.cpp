#include "clientsocket.h"
#include <syslog.h>
#include <time.h>
//Constructor
ClientSocket::ClientSocket(QSslSocket *sslSocket, QObject *parent) :
    QObject(parent),sslSocket_(sslSocket)
{
    syslog(LOG_NOTICE, "ENTRO A clientesocket\n");
    db_ = QSqlDatabase::addDatabase("QSQLITE");
    QString string=APP_DATADIR;
    string+="/data.sqlite";
    db_.setDatabaseName(string);
    if (!db_.open())
    {
        QMessageBox::critical(NULL, tr("Error"),
                              tr("No se pudo acceder a los datos."));
    }
    leer_cabecera_=false;
    leer_imagen_=false; //10.213.3.6
    leer_timestamp_=true;
    leer_size_string_=false;
    leer_string_=false;
    leer_n_rectangulo_=false;
    leer_rectangulos_=false;
    contador_=0;

    connect(sslSocket_,SIGNAL(readyRead()),this,SLOT(readData()));
    connect(sslSocket_,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(sslSocket_,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(mostrarErrores(QAbstractSocket::SocketError)));

    widget_=new QWidget();
    layout_= new QGridLayout(widget_);
    layout_->addWidget(&label_);
    label_.setScaledContents(true);
    //Abrir ventana para mostrar imagen
    mostrarImagen_=true;
}
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

    //Leer tiempo
    if(leer_timestamp_==true)
    {
        if(sslSocket_->bytesAvailable()>=8)
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
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
            leer_string_=false;
            leer_n_rectangulo_=false;
            leer_rectangulos_=false;
            clock = QDateTime::currentMSecsSinceEpoch()-clock;
            qDebug() << "Tiempo para leer el timestamp: " << clock;
        }
    }
    //Estado leer cabecera(tamaño imagen)
    if(leer_cabecera_==true)
    {
        if((sslSocket_->bytesAvailable())>=4)//Si existe los suficientes datos
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
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
            leer_string_=false;
            leer_n_rectangulo_=false;
            leer_rectangulos_=false;
            clock = QDateTime::currentMSecsSinceEpoch()-clock;
            qDebug() << "Tiempo para leer el tamaño de la imagen" << clock;
        }
    }
    //Estado leer imagen
    if(leer_imagen_ ==true)
    {
        if((sslSocket_->bytesAvailable())>=imagen_size_)
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
            data_=sslSocket_->read(imagen_size_);
            QImage image;
            image.loadFromData(data_,"JPEG");
            image_=image;
            data_.clear();
            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=true;
            leer_string_=false;
            leer_n_rectangulo_=false;
            leer_rectangulos_=false;
            clock = QDateTime::currentMSecsSinceEpoch()-clock;
        qDebug() << "Tiempo para leer la imagen" << clock;

        }
    }
    //Leer tamaño cadena
    if(leer_size_string_==true)
    {
        if(sslSocket_->bytesAvailable()>=4)
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
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
            leer_n_rectangulo_=false;
            leer_rectangulos_=false;
            clock = QDateTime::currentMSecsSinceEpoch()-clock;
            qDebug() << "Tiempo para leer el tamaño de la cadena" << clock;
        }
    }
    //Leer cadena
    if(leer_string_==true)
    {
        if(sslSocket_->bytesAvailable()>=string_size_)
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
            data_=sslSocket_->read(string_size_);
            string_=QString::fromLatin1(data_.data(),string_size_);
            qDebug()<<"CADENA: "<<string_;
            qDebug()<<"-------------------------------------------";
            data_.clear();

            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=false;
            leer_string_=false;
            leer_n_rectangulo_=true;
            leer_rectangulos_=false;
            clock = QDateTime::currentMSecsSinceEpoch()-clock;
        qDebug() << "Tiempo para leer la cadena" << clock;
        }
    }
    //Leer número de rectangulos
    if(leer_n_rectangulo_==true)
    {
        if(sslSocket_->bytesAvailable()>=4)
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
            data_=sslSocket_->read(4);
            size=reinterpret_cast<int*>(data_.data());
            rectangulo_size_=*size;
            rectangulo_size_= qFromLittleEndian(rectangulo_size_);
            data_.clear();
            //Estados de la lectura
            leer_cabecera_=false;
            leer_imagen_=false;
            leer_timestamp_=false;
            leer_size_string_=false;
            leer_string_=false;
            leer_n_rectangulo_=false;
            leer_rectangulos_=true;
            clock = QDateTime::currentMSecsSinceEpoch()-clock;
            qDebug() << "Tiempo para leer el numero de rectangulos" << clock;
        }
    }
    //leer rectangulos
    if(leer_rectangulos_==true)
    {
        if(sslSocket_->bytesAvailable()>=16)
        {
            qint64 clock = QDateTime::currentMSecsSinceEpoch();
            if(rectangulo_size_>0)
            {
                data_=sslSocket_->read(4);
                size=reinterpret_cast<int*>(data_.data());
                x_=qFromLittleEndian(*size);
                data_=sslSocket_->read(4);
                size=reinterpret_cast<int*>(data_.data());
                y_=qFromLittleEndian(*size);
                data_=sslSocket_->read(4);
                size=reinterpret_cast<int*>(data_.data());
                ancho_=qFromLittleEndian(*size);
                data_=sslSocket_->read(4);
                size=reinterpret_cast<int*>(data_.data());
                alto_=qFromLittleEndian(*size);
                data_.clear();
                QRect aux(x_,y_,ancho_,alto_);
                rectangulo_.push_back(aux);
            }
            contador_++;

            if(contador_<rectangulo_size_)
            {
                //Estados de la lectura
                leer_cabecera_=false;
                leer_imagen_=false;
                leer_timestamp_=false;
                leer_size_string_=false;
                leer_string_=false;
                leer_n_rectangulo_=false;
                leer_rectangulos_=true;
            }
            else
            {
                //Estados de la lectura
                leer_cabecera_=false;
                leer_imagen_=false;
                leer_timestamp_=true;
                leer_size_string_=false;
                leer_string_=false;
                leer_n_rectangulo_=false;
                leer_rectangulos_=false;
                contador_=0;
                QPixmap pixmap;
                pixmap=pixmap.fromImage(image_);
                QPainter paint(&pixmap);
                paint.setPen(Qt::green);
                int i=0;
                while(rectangulo_.size()>i)
                {
                    QRect rect=rectangulo_.value(i);
                    paint.drawRect(rect);
                    i++;
                }
                clock = QDateTime::currentMSecsSinceEpoch()-clock;
                qDebug() << "Tiempo para leer todos los rectangulos" << clock;
                qint64 clock = QDateTime::currentMSecsSinceEpoch();
                guardarImagen(timestamp_, image_);
                clock = QDateTime::currentMSecsSinceEpoch()-clock;
                qDebug() << "Tiempo para almacenar la imagen y actualizar la base de datos" << clock;
                //termino de guardar la imagen
                rectangulo_.clear();
                if(mostrarImagen_==true)
                {
                    mostrarImagen_=false;
                    widget_->show();

                }
                label_.setPixmap(pixmap);
            }
        }
    }

}
//Mostrar errores de conexión del socket
void ClientSocket::mostrarErrores(QAbstractSocket::SocketError )
{
    QString string=sslSocket_->errorString();
    QMessageBox ventana;
    ventana.setWindowTitle("Mensaje de Error");
    ventana.setText(string);
    ventana.setStandardButtons(QMessageBox::Ok);
    ventana.exec();
    widget_->close();
}
//Guardar imagenes en directores segun el timestamp
void ClientSocket::guardarImagen(qint64 timestamp, QImage imagen){
    syslog(LOG_NOTICE, "ENTRO A guardar imagen\n");
    qint32 szHx = 16;
    qint32 s1 = 4;
    qint32 s2 = 8;
    qint32 sI = 21;
    QString tt=QString::number(timestamp,szHx);
    tt.insert(s1, QString("/"));
    tt.insert(s2, QString("/"));
    QString ttImage2 = tt;
    QString string=APP_DATADIR;
    string+="/";
    tt.push_front(string);
    QString ttImage = tt;
    ttImage.push_back(".JPEG");
    tt.truncate(sI);
    QDir carpetaNueva;
    carpetaNueva.mkpath(tt);
    imagen.save(ttImage);
    ttImage2.push_front("/");
    ttImage2.push_front(QDir::currentPath());
    QSqlQuery query;
    query.prepare("INSERT INTO Datos (host, timestamp, ruta) "
                  "VALUES (:host, :timestamp, :ruta)");
    query.bindValue(":host", string_);
    query.bindValue(":timestamp", timestamp);
    query.bindValue(":ruta", ttImage2);
    query.exec();

    QSqlQuery q("select id from Datos");
    QSqlRecord rec = q.record();
    int nameCol = rec.indexOf("id");
    q.last();
    QString ultimoId = q.value(nameCol).toString();
    for (int i = 0; i < rectangulo_.size(); i++)
    {
        QSqlQuery query2;
        query2.prepare("INSERT INTO Rect (id, x, y, alto, ancho) "
                       "VALUES (:id, :x, :y, :alto, :ancho)");
        query2.bindValue(":id", ultimoId.toInt());
        query2.bindValue(":x", rectangulo_[i].x());
        query2.bindValue(":y", rectangulo_[i].y());
        query2.bindValue(":alto", rectangulo_[i].height());
        query2.bindValue(":ancho", rectangulo_[i].width());
        query2.exec();
    }
}
