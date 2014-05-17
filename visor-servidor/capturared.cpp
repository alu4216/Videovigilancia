#include "capturared.h"
#include "ui_capturared.h"

//Constructor
//Configura puerto de conexión
CapturaRed::CapturaRed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CapturaRed)
{
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    ui->setupUi(this);
    QString puerto=settings.value("Puertos/puerto",15000).toString();
    ui->lineEdit->setText(puerto);
}
//Destructor
CapturaRed::~CapturaRed()
{
    delete ui;
}
//Comenzar a escuchar las conexiones entrantes
void CapturaRed::on_pushComenzar_clicked()
{
    emit s_capture();
    close();
}
//Cambiar el puerto de escucha
void CapturaRed::on_pushCambiar_clicked()
{
    QSettings settings;
    //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
    int puerto= ui->lineEdit->text().toInt();
    settings.setValue("Puertos/puerto",puerto);
}
