#ifndef CAPTURARED_H
#define CAPTURARED_H

#include <QDialog>
#include <QSettings>
#include <QDebug>
namespace Ui {
class CapturaRed;
}

class CapturaRed : public QDialog
{
    Q_OBJECT

public:
    explicit CapturaRed(QWidget *parent = 0);
    ~CapturaRed();
signals:
    void s_capture();

private slots:
    void on_pushComenzar_clicked();
    void on_pushCambiar_clicked();

private:
    Ui::CapturaRed *ui;
};

#endif // CAPTURARED_H
