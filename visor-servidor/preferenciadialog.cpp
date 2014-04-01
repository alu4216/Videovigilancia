#include "preferenciadialog.h"
#include "ui_preferenciadialog.h"

//Constructor
//Seleccionar un dispositivo de cámara de la lista.
PreferenciaDialog::PreferenciaDialog(const QList<QByteArray> &devices,QWidget * parent) :
    QDialog(parent),
    ui(new Ui::PreferenciaDialog)
{
    ui->setupUi(this);
    qDebug() << "Capturando de... "
             << QCamera::deviceDescription(devices[0]);
    qDebug()<< "Tamaño de...."
            <<devices.size();
    QSettings settings;
    int i=0;
    do {
        ui->comboBox->addItem(QCamera::deviceDescription(devices[i]));
        i++;
    }while(i<devices.size());

    ui->comboBox->setCurrentIndex(settings.value("indice").toInt());
}
//Destructor
PreferenciaDialog::~PreferenciaDialog()
{
    delete ui;
}
//Actualizar el dispositivo usado
void PreferenciaDialog::on_pushOk_clicked()
{
    indice_=ui->comboBox->currentIndex();
    QSettings settings;
    settings.value("indice",indice_);
    emit s_camera(indice_);
    close();
}
//Cerrar
void PreferenciaDialog::on_pushCerrar_clicked()
{
    close();
}
