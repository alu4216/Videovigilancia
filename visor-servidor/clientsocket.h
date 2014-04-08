#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QBuffer>
#include <QImage>
#include <QMessageBox>
#include <QtEndian>
#include <QDir>


class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QTcpSocket * tcpSocket,QObject *parent = 0);
     bool guardarImagen(qint64, QImage);
    ~ClientSocket();

signals:
    void s_mostrar_captura(const QImage&);
public slots:
    void readData();
    void mostrarErrores(QAbstractSocket::SocketError);
private:
    QTcpSocket *tcpSocket_;
    QByteArray data_;
    qint64 timestamp_;
    QString string_;
    int imagen_size_;
    int string_size_;

    bool leer_cabecera_;
    bool leer_imagen_;
    bool leer_timestamp_;
    bool leer_size_string_;
    bool leer_string_;
};

#endif // CLIENTSOCKET_H
