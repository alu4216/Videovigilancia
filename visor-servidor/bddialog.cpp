#include "bddialog.h"
#include "ui_bddialog.h"

//Constructor
BDDialog::BDDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BDDialog)
{
    ui->setupUi(this);
    db_.setDatabaseName("data.sqlite");
    if (!db_.open())
    {
        QMessageBox::critical(NULL, tr("Error"),
                              tr("No se pudo acceder a los datos."));
    }
    QSqlQuery query;
    query.exec("SELECT id FROM Datos");
    while (query.next())
    {
        QString nombre = query.value(0).toString();
        ui->listWidget->addItem(nombre);
    }

}
//Destructor
BDDialog::~BDDialog()
{
    delete ui;
}
//Listar
void BDDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString text = item->text();
    QSqlQuery query;
    query.prepare(QString("SELECT id, ruta, host FROM Datos WHERE timestamp == %1").arg(text));
    query.exec();
    while(query.next())
    {
        QString ruta = query.value(1).toString();
        QString id = query.value(0).toString();
        QString host = query.value(2).toString();
        qDebug() << "ID: "<< id;
        qDebug() << ruta;
        QImage imagen = QImage(ruta);
        QPixmap pixmap;
        pixmap=pixmap.fromImage(imagen);
        ui->label->setPixmap(pixmap);
        ui->hostLabel->setText(host);
        ui->timestampLabel->setText(id);
    }
}
