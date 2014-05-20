#include "sslserver.h"
#include <syslog.h>

//Constructor
SslServer::SslServer(QObject *parent) :
    QTcpServer(parent)
{

    syslog(LOG_ERR, "ENTRO A sslserver\n");
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    QString string = APP_DATADIR;
    string+="/SSL/server.key";
    settings.setValue("SSl/key",string);
    QString string2 = APP_DATADIR;
    string2+="/SSL/server.crt";
    settings.setValue("SSL/certificado",string2);
}
//Destructor
SslServer::~SslServer()
{

}
//Sobrecargamos el método incomingConnecction
void SslServer::incomingConnection(qintptr socketDescriptor)
{
    syslog(LOG_ERR, "ENTRO A CONEXIONES\n");
    Thread * hilo=new Thread(socketDescriptor,this);
    connect(hilo, SIGNAL(finished()), hilo, SLOT(deleteLater()));
    hilo->start();
}
