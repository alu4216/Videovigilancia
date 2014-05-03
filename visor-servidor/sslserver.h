#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <QTcpServer>
#include <QSettings>
#include "thread.h"

class SslServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit SslServer(QObject *parent = 0);
    ~SslServer();
    void incomingConnection(qintptr);

private:

};

#endif // SSLSERVER_H
