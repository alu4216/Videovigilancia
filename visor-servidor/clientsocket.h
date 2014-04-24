#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QSslSocket>
#include <QBuffer>
#include <QImage>
#include <QMessageBox>
#include <QtEndian>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>

//#include "viewerwindow.h"
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QSslSocket * sslSocket_,QObject *parent = 0);
    void guardarImagen(qint64, QImage);
    ~ClientSocket();


public slots:
    void readData();
    void mostrarErrores(QAbstractSocket::SocketError);

private:
    QSslSocket *sslSocket_;
    QByteArray data_;
    qint64 timestamp_;
    QString string_;
    int imagen_size_;
    int string_size_;
    long idDb_;
    QLabel label_;
    QWidget * widget_;
    QGridLayout * layout_;
    bool leer_cabecera_;
    bool leer_imagen_;
    bool leer_timestamp_;
    bool leer_size_string_;
    bool leer_string_;
    bool mostrarImagen_;
    QSqlDatabase db_ = QSqlDatabase::addDatabase("QSQLITE");

};

#endif // CLIENTSOCKET_H
