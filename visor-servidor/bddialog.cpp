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
    query.exec("SELECT timestamp FROM Datos");
    while (query.next())
    {
        QString nombre = query.value(0).toString();
        //QDateTime x = QDateTime::fromString(nombre, "dd/MM/yy");
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
    query.prepare(QString("SELECT timestamp, ruta, host, id FROM Datos WHERE timestamp == %1").arg(text));
    query.exec();
    while(query.next())
    {
        QString ruta = query.value(1).toString();
        QString timestamp = query.value(0).toString();
        QString host = query.value(2).toString();
        QString id = query.value(3).toString();
        ruta=ruta +".JPEG";
        qDebug() << "ID: "<< id;
        qDebug() << ruta;

        QImage imagen = QImage(ruta);
        QPixmap pixmap;
        pixmap=pixmap.fromImage(imagen);
        ui->label->setPixmap(pixmap);
        host.push_front("HOST: ");
        ui->hostLabel->setText(host);
        timestamp.push_front("TIMESTAMP: ");
        ui->timestampLabel->setText(timestamp);
        QString id2 = id;
        id.push_front("ID: ");
        ui->labelID->setText(id);
        QSqlQuery query2;
        qDebug() << "ID 2" << id2;
        query2.prepare(QString("SELECT id, x, y FROM Rect WHERE id == %1").arg(id2));
        query2.exec();
        qDebug() << "ID 2" << id2;
        while (query2.next())
        {
            ui->listWidget_2->addItem(QString("ID: %1\t X: %2\t Y: %3").arg(query2.value(0).toString(), query2.value(1).toString(), query2.value(2).toString()));
        }
    }
}
