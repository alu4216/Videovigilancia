#ifndef MYDAEMON_H
#define MYDAEMON_H

#include <QObject>
#include <QSslSocket>
#include <QTcpServer>
#include <QSocketNotifier>
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>
#include <QApplication>

int setupUnixSignalHandlers();

class MyDaemon : public QObject
{
    Q_OBJECT

    public:
        MyDaemon(QObject *parent = 0);
        ~MyDaemon();

        // Manejador de la señal SIGTERM
        // Debe ser static para poder pasar el método como
        // manejador al invocar signal()
        static void hupSignalHandler(int);
        static void termSignalHandler(int);
        static void intSignalHandler(int);

        //void setSslSocket(QSslSocket *);

    public slots:
        // Slot donde atender la señal POSIX SIGTERM cuando la
        // convirtamos en una señal de Qt
        void handleSigTerm();
        void handleSigHup();
        void handleSigInt();

    private:
        // Pareja de sockets. Un par por señal a manejar.
        // En este caso es para la señal SIGTERM
        static int sigTermSd[2];
        static int sigHupSd[2];
        static int sigIntSd[2];
        //QSslSocket * sslSocket_;
        // Objeto para monitorizar la pareja de sockets
        // sigTermSd[2]
        QSocketNotifier *sigTermNotifier;
        QSocketNotifier *sigHupNotifier;
        QSocketNotifier *sigIntNotifier;
};


#endif // MYDAEMON_H
