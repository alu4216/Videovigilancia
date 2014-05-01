#ifndef BDDIALOG_H
#define BDDIALOG_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QListWidgetItem>
#include <QDateTime>

namespace Ui {
class BDDialog;
}

class BDDialog : public QWidget
{
    Q_OBJECT

public:
    explicit BDDialog(QWidget *parent = 0);
    ~BDDialog();

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::BDDialog *ui;
    QSqlDatabase db_ = QSqlDatabase::addDatabase("QSQLITE");
    QList<QString> lista_;
};

#endif // BDDIALOG_H
