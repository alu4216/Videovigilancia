#include "sslserver.h"
#include <syslog.h>

//Constructor
SslServer::SslServer(QObject *parent) :
    QTcpServer(parent)
{

    syslog(LOG_ERR, "ENTRO A sslserver\n");
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    settings.setValue("SSl/key","/tmp/SSL/server.key");
    settings.setValue("SSL/certificado","/tmp/SSL/server.crt");
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
