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
    ui->listWidget->clear();
    query.exec("SELECT timestamp FROM Datos");
    while (query.next())
    {
        QString nombre = query.value(0).toString();
        QDateTime x = QDateTime::fromMSecsSinceEpoch(query.value(0).toLongLong());
        ui->listWidget->addItem(QString("[%1]|%2").arg(x.toString(), nombre));
    }
    lista_.clear();
    for (int i = 0; i < ui->listWidget->count(); i++)
    {
        lista_.push_back(ui->listWidget->item(i)->text());
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
    ui->listWidget_2->clear();
    QString text = item->text();
    QStringList lS = text.split("|");
    QString text2 = lS[1];
    QSqlQuery query;
    query.prepare(QString("SELECT timestamp, ruta, host, id FROM Datos WHERE timestamp == %1").arg(text2));
    query.exec();
    while(query.next())
    {
        QString ruta = query.value(1).toString();
        QString timestamp = query.value(0).toString();
        QString host = query.value(2).toString();
        QString id = query.value(3).toString();
        ruta=ruta +".JPEG";
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
        query2.prepare(QString("SELECT id, x, y, alto, ancho FROM Rect WHERE id == %1").arg(id2));
        query2.exec();
        while (query2.next())
        {
            ui->listWidget_2->addItem(QString("ID: %1\t X: %2\t Y: %3\t H: %4\t W: %5").arg(query2.value(0).toString(), query2.value(1).toString(), query2.value(2).toString(), query2.value(3).toString(), query2.value(4).toString()));
        }
    }
}

void BDDialog::on_lineEdit_textChanged(const QString &arg1)
{
   ui->listWidget->clear();
   for (int i = 0; i < lista_.size(); i++)
   {
       if(lista_[i].contains(arg1)==true){
           ui->listWidget->addItem(lista_[i]);
       }
   }
}
