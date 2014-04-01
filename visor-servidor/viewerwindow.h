#ifndef VIEWERWINDOW_H
#define VIEWERWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QFileDialog>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QMessageBox>
#include <QPixmap>
#include <QWaitCondition>
#include <QMutex>
#include <QMovie>
#include <QSettings>
#include <QCamera>
#include <QCameraViewfinder>
#include <QPainter>
#include <QDateTime>
#include <QFont>
#include <QTcpSocket>
#include <QBuffer>
#include <QImageWriter>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QDataStream>

#include "acerca.h"
#include "preferenciadialog.h"
#include "capturebuffer.h"
#include "capturared.h"
#include "clientsocket.h"



namespace Ui {
class ViewerWindow;
}

class ViewerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewerWindow(QWidget *parent = 0);
    ~ViewerWindow();

private slots:
    void on_Salir_clicked();
    void on_actionSalir_triggered();
    void on_actionAbrirImagen_triggered();
    void on_actionAbrirVideo_triggered();
    void movie_frame(const QRect& rect);
    void on_checkBox_stateChanged(int arg1);
    void on_actionAcercaDe_triggered();
    void on_Push_Pausa_clicked();
    void on_actionCapturar_triggered();
    void on_actionPreferencias_triggered();
    void actualizar_s(int);
    void image_s(const QImage&);
    void capture_s();
    void on_actionCaptura_de_Red_triggered();
    void conexionSocket_s();
    void mostrar_captura_s(const QImage&);

private:
    Ui::ViewerWindow * ui;
    QMovie * movie_;
    Acerca * dialog_;
    PreferenciaDialog * preferencias_;
    QCamera * camera_;
    CaptureBuffer * captureBuffer_;
    QTcpServer * tcpServer_;
    CapturaRed * capturaRed_;

    QList<QByteArray> devices_;
    QList<ClientSocket*> clients_;
    int check_;
    int indice_;
    int puerto_;
    QString ip_;

};

#endif // VIEWERWINDOW_H
