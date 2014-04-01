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
#include <QDateTime>


#include "acerca.h"
#include "preferenciadialog.h"
#include "capturebuffer.h"
#include "ajustesconexion.h"



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
    void on_actionAjustes_Conexion_triggered();
    void on_actionComenzar_a_enviar_triggered();

private:
    Ui::ViewerWindow * ui;
    QMovie * movie_;
    Acerca * dialog_;
    PreferenciaDialog * preferencias_;
    QCamera * camera_;
    CaptureBuffer * captureBuffer_;
    QTcpSocket * tcpsocket_;
    AjustesConexion * conexion_;
    QList<QByteArray> devices_;
    int check_;
    int indice_;
    int puerto_;
    QString ip_;
    struct Package
    {
        qint64 timestamp;
        QString name;
        int size;
        int size_string;
        QByteArray image;
    };
   //QList <Package>lista;
};

#endif // VIEWERWINDOW_H
