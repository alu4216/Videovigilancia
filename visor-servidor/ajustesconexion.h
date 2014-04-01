#ifndef AJUSTESCONEXION_H
#define AJUSTESCONEXION_H

#include <QDialog>
#include <QSettings>
namespace Ui {
class AjustesConexion;
}

class AjustesConexion : public QDialog
{
    Q_OBJECT

public:
    explicit AjustesConexion(QWidget *parent = 0);
    ~AjustesConexion();

private slots:
    void ajustes_s();

    void porDefecto_s();

private:
    Ui::AjustesConexion *ui;
};

#endif // AJUSTESCONEXION_H
