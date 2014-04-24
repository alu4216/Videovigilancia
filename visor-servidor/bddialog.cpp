#include "bddialog.h"
#include "ui_bddialog.h"

BDDialog::BDDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BDDialog)
{
    ui->setupUi(this);
    db_.setDatabaseName("data.sqlite");
    if (!db_.open()) {
        QMessageBox::critical(NULL, tr("Error"),
            tr("No se pudo acceder a los datos."));
    }
    QStringList  listaTablas = db_.tables();
    qDebug() << "Número de tablas creadas: " << listaTablas.size();
    for (int i = 0; i < listaTablas.size(); i++){
        qDebug() << "Tabla[" << i << "] => "<< listaTablas[i];
    }

    QSqlQuery query;
    query.exec("SELECT id FROM Datos");
    while (query.next()) {
        QString nombre = query.value(0).toString();
        ui->listWidget->addItem(nombre);
    }

}

BDDialog::~BDDialog()
{
    delete ui;
}

void BDDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString text = item->text();
    qDebug() << "Label de el elemento de lista: "<< text;
    //peticion.push_back(text);
    QSqlQuery query;
    query.prepare(QString("SELECT id, ruta, host FROM Datos WHERE timestamp == %1").arg(text));
    //query.bindValue(":texto", text);
    query.exec();
    while(query.next()){
        QString ruta = query.value(1).toString();
        QString id = query.value(0).toString();
        QString host = query.value(2).toString();
        qDebug() << "ID: "<< id;
        //if(id == text){
            qDebug() << ruta;
            QImage imagen = QImage(ruta);
            QPixmap pixmap;
            pixmap=pixmap.fromImage(imagen);
            ui->label->setPixmap(pixmap);
            ui->hostLabel->setText(host);
            ui->timestampLabel->setText(id);
        //}
    }
}
