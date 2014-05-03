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
#include <QPainter>
#include <QVector>
#include <QRect>
#include <QSqlRecord>
#include <QDateTime>
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
    QImage image_;
    int imagen_size_;
    int string_size_;
    int rectangulo_size_;
    int ancho_;
    int alto_;
    int x_;
    int y_;
    long idDb_;
    int contador_;
    QLabel label_;
    QWidget * widget_;
    QGridLayout * layout_;
    bool leer_cabecera_;
    bool leer_imagen_;
    bool leer_timestamp_;
    bool leer_size_string_;
    bool leer_string_;
    bool mostrarImagen_;
    bool leer_n_rectangulo_;
    bool leer_rectangulos_;
    QSqlDatabase db_;
    QVector<QRect> rectangulo_;

};

#endif // CLIENTSOCKET_H
