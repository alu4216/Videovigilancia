#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QSslSocket>
#include <QFile>
#include <QSslCertificate>
#include <QSslKey>
#include <QFile>
#include <QSettings>
#include "clientsocket.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr socketDescriptor,QObject *parent = 0);
    void run();
    ~Thread();
signals:

public slots:

private:
    qintptr socketDescriptor_;
    QByteArray key_;
    QByteArray certificate_;
    QList<ClientSocket*> clients_;

};

#endif // THREAD_H
