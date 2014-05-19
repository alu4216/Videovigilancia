#include "mydaemon.h"

int MyDaemon::sigHupSd[2];
int MyDaemon::sigTermSd[2];
int MyDaemon::sigIntSd[2];

MyDaemon::MyDaemon(QObject *parent) : QObject(parent)
{
    // Crear la pareja de sockets de UNIX
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigHupSd))
        qFatal("Couldn't create HUP socketpair");
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigTermSd))
        qFatal("Couldn't create TERM socketpair");
    if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigIntSd))
        qFatal("Couldn't create INT socketpair");

    // Crear el objeto para monitorizar uno de los sockets
    // de la pareja.
    sigHupNotifier = new QSocketNotifier(sigHupSd[1],
            QSocketNotifier::Read, this);
    sigTermNotifier = new QSocketNotifier(sigTermSd[1],
            QSocketNotifier::Read, this);
    sigIntNotifier = new QSocketNotifier(sigIntSd[1],
            QSocketNotifier::Read, this);

    // Conectar la señal activated() del objeto QSocketNotifier
    // con el slot handleSigTerm() para manejar la señal. Esta
    // señal será emitida cuando hayan datos para ser leidos en
    // el socket monitorizado.
    connect(sigHupNotifier, SIGNAL(activated(int)), this,
            SLOT(handleSigHup()));
    connect(sigTermNotifier, SIGNAL(activated(int)), this,
            SLOT(handleSigTerm()));
    connect(sigIntNotifier, SIGNAL(activated(int)), this,
            SLOT(handleSigInt()));

    //...
}
MyDaemon::~MyDaemon()
{
    //Nothing
}
// Manejador de la señal POSIX SIGTERM
void MyDaemon::termSignalHandler(int)
{
    char a = 1;
    write(sigTermSd[0], &a, sizeof(a));
}
// Manejador de la señal SIGHUP
void MyDaemon::hupSignalHandler(int)
{
    char a = 1;
    ::write(sigHupSd[0], &a, sizeof(a));
}
// Manejador de la señal SIGTERM
void MyDaemon::intSignalHandler(int)
{
    char a = 1;
    ::write(sigIntSd[0], &a, sizeof(a));
}
//Terminar proceso
void MyDaemon::handleSigTerm()
{
    qDebug("Sigterm");
    sigTermNotifier->setEnabled(false);
    char tmp;
    ::read(sigTermSd[1], &tmp, sizeof(tmp));

    //sslSocket_->disconnect();
    //sslSocket_->deleteLater();
    qDebug("Disconnected");
    //qApp->quit();
    QApplication::quit();
    deleteLater();

    sigTermNotifier->setEnabled(true);
}
//Cerrar conexiones y reiniciar servicio
void MyDaemon::handleSigHup()
{
    qDebug("Sighup");
    sigHupNotifier->setEnabled(false);
    char tmp;
    ::read(sigHupSd[1], &tmp, sizeof(tmp));


    //qApp->quit();
    QApplication::quit();
    //sslSocket_->disconnect();
    //sslSocket_->deleteLater();
    //sslSocket_=new QSslSocket;
    //reconnect();

    sigHupNotifier->setEnabled(true);
}
//Interrumpir proceso a peticion del usuario Ctrl+C
void MyDaemon::handleSigInt()
{
    sigIntNotifier->setEnabled(false);
    char tmp;
    ::read(sigIntSd[1], &tmp, sizeof(tmp));

    qDebug("Sigint");
    //sslSocket_->disconnect();
    //sslSocket_->deleteLater();
    qDebug("Disconnected");
    QApplication::quit();
    //QCoreApplication::quit();
    //deleteLater();

    sigHupNotifier->setEnabled(true);
}

int setupUnixSignalHandlers()
{
    struct ::sigaction hup, term, ints;

    hup.sa_handler = &MyDaemon::hupSignalHandler;
    /*::*/sigemptyset(&hup.sa_mask);
    hup.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGHUP
    if (::sigaction(SIGHUP, &hup, 0) > 0)
        return 1;

    term.sa_handler = &MyDaemon::termSignalHandler;
    /*::*/sigemptyset(&term.sa_mask);
    term.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGTERM
    if (::sigaction(SIGTERM, &term, 0) > 0)
        return 2;

    ints.sa_handler = &MyDaemon::intSignalHandler;
    /*::*/sigemptyset(&ints.sa_mask);
    ints.sa_flags = SA_RESTART;

    // Establecer manejador de la señal SIGINT
    if (::sigaction(SIGINT, &ints, 0) > 0)
        return 3;

    return 0;
}
