#include "sslserver.h"

//Constructor
SslServer::SslServer(QObject *parent) :
    QTcpServer(parent)
{
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    settings.setValue("SSl/key","../SSL/server.key");
    settings.setValue("SSL/certificado","../SSL/server.crt");
}
//Destructor
SslServer::~SslServer()
{

}
//Sobrecargamos el método incomingConnecction
void SslServer::incomingConnection(qintptr socketDescriptor)
{
    Thread * hilo=new Thread(socketDescriptor,this);
    connect(hilo, SIGNAL(finished()), hilo, SLOT(deleteLater()));
    hilo->start();
}
