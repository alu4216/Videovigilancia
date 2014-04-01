#include "ajustesconexion.h"
#include "ui_ajustesconexion.h"

//Constructor
AjustesConexion::AjustesConexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjustesConexion)
{
    ui->setupUi(this);
    connect(ui->pushGuardar,SIGNAL(clicked()),this,SLOT(ajustes_s()));
    connect(ui->pushPorDefecto,SIGNAL(clicked()),this,SLOT(porDefecto_s()));
}

//Destructor
AjustesConexion::~AjustesConexion()
{
    delete ui;
}

//Ajustes de de conexión. Elección de puerto e ip a enviar
void AjustesConexion::ajustes_s()
{
    QSettings settings;
    int puerto= ui->lineEdit_puerto->text().toInt();
    QString ip=ui->lineEdit_ip->text();
    settings.setValue("Network/puerto",puerto);
    settings.setValue("Network/ip",ip);
    close();
}

//Ajustes de conexión por defecto. Valores por defecto
void AjustesConexion::porDefecto_s()
{
    QSettings settings;
    settings.setValue("Network/puerto",15000);
    settings.setValue("Network/ip",QString("127.0.0.1"));
    close();
}
