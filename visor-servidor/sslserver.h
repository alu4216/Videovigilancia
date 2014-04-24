#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <QTcpServer>
#include <QSettings>
#include <QSslSocket>
#include <QFile>
#include <QSslCertificate>
#include <QSslKey>
#include "clientsocket.h"
class SslServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit SslServer(QObject *parent = 0);
    ~SslServer();
    void incomingConnection(qintptr);

signals:

public slots:

private:

    QByteArray key_;
    QByteArray certificate_;
    QList<ClientSocket*> clients_;

};

#endif // SSLSERVER_H
