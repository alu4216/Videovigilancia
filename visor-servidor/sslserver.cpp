#include "sslserver.h"

//Constructor
SslServer::SslServer(QObject *parent) :
    QTcpServer(parent)
{
    QSettings settings;
    settings.setValue("SSl/key","../SSL/server.key");
    settings.setValue("SSL/certificado","../SSL/server.crt");
}
//Destructor
SslServer::~SslServer()
{
    clients_.clear();
}
//Sobrecargamos el método incomingConnecction
void SslServer::incomingConnection(qintptr socketDescriptor)
{
    QSslSocket* sslSocket = new QSslSocket();
    QSettings settings;
    if(sslSocket->setSocketDescriptor(socketDescriptor))
    {
        QString key;
        QString cert;
        //rutas de certificado y de la llave
        cert = settings.value("SSL/certificado").toString();
        key = settings.value("SSl/key").toString();

        //leer clave
        QFile file_key(key);
        if(file_key.open(QIODevice::ReadOnly))
        {
            key_ = file_key.readAll();
            file_key.close();
            qDebug()<<key_;
        }
        else //fallo de lectura de la clave
            qDebug() <<"Error key: "<< file_key.errorString();

        //leer certificado
        QFile file_cert(cert);
        if(file_cert.open(QIODevice::ReadOnly))
        {
            certificate_ = file_cert.readAll();
            file_cert.close();
            qDebug()<<certificate_;
        }
        else //fallo de lectura del certificado
            qDebug() <<"Error cert: "<< file_cert.errorString();

        //Configuración del cifrado
        QSslKey ssl_key(key_,QSsl::Rsa);
        QSslCertificate ssl_cert(certificate_);
        sslSocket->setPrivateKey(ssl_key);
        sslSocket->setLocalCertificate(ssl_cert);
        sslSocket->setPeerVerifyMode(QSslSocket::VerifyNone);
        sslSocket->setProtocol(QSsl::SslV3);
        sslSocket->startServerEncryption();

        //Ignorar errores producidos
        QList<QSslError> errors;
        errors.append(QSslError::SelfSignedCertificate);
        errors.append(QSslError::CertificateUntrusted);
        sslSocket->ignoreSslErrors(errors);

        //Create new client with the established connection
        ClientSocket *client=new ClientSocket(sslSocket,this);
        clients_.append(client);
    }
    else
        delete sslSocket;
}
