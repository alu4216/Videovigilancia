/********************************************************************************
** Form generated from reading UI file 'ajustesconexion.ui'
**
** Created: Tue Apr 8 14:10:07 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTESCONEXION_H
#define UI_AJUSTESCONEXION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjustesConexion
{
public:
    QLineEdit *lineEdit_ip;
    QLineEdit *lineEdit_puerto;
    QPushButton *pushGuardar;
    QPushButton *pushPorDefecto;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AjustesConexion)
    {
        if (AjustesConexion->objectName().isEmpty())
            AjustesConexion->setObjectName(QString::fromUtf8("AjustesConexion"));
        AjustesConexion->resize(400, 172);
        AjustesConexion->setMinimumSize(QSize(400, 172));
        AjustesConexion->setMaximumSize(QSize(400, 172));
        lineEdit_ip = new QLineEdit(AjustesConexion);
        lineEdit_ip->setObjectName(QString::fromUtf8("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(200, 50, 191, 23));
        lineEdit_puerto = new QLineEdit(AjustesConexion);
        lineEdit_puerto->setObjectName(QString::fromUtf8("lineEdit_puerto"));
        lineEdit_puerto->setGeometry(QRect(200, 90, 191, 23));
        pushGuardar = new QPushButton(AjustesConexion);
        pushGuardar->setObjectName(QString::fromUtf8("pushGuardar"));
        pushGuardar->setGeometry(QRect(10, 70, 81, 23));
        pushPorDefecto = new QPushButton(AjustesConexion);
        pushPorDefecto->setObjectName(QString::fromUtf8("pushPorDefecto"));
        pushPorDefecto->setGeometry(QRect(300, 130, 91, 23));
        label = new QLabel(AjustesConexion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 50, 71, 16));
        label_2 = new QLabel(AjustesConexion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 90, 57, 15));
        label_3 = new QLabel(AjustesConexion);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 130, 151, 20));

        retranslateUi(AjustesConexion);

        QMetaObject::connectSlotsByName(AjustesConexion);
    } // setupUi

    void retranslateUi(QDialog *AjustesConexion)
    {
        AjustesConexion->setWindowTitle(QApplication::translate("AjustesConexion", "Ajustes de conexi\303\263n Cliente", 0, QApplication::UnicodeUTF8));
        pushGuardar->setText(QApplication::translate("AjustesConexion", "Guardar", 0, QApplication::UnicodeUTF8));
        pushPorDefecto->setText(QApplication::translate("AjustesConexion", "Por defecto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AjustesConexion", "IP Servidor", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AjustesConexion", "Puerto", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AjustesConexion", "Puerto e Ip por defecto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjustesConexion: public Ui_AjustesConexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTESCONEXION_H
