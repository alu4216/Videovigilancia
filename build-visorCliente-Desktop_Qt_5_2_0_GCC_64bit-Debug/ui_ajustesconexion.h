/********************************************************************************
** Form generated from reading UI file 'ajustesconexion.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTESCONEXION_H
#define UI_AJUSTESCONEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

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
            AjustesConexion->setObjectName(QStringLiteral("AjustesConexion"));
        AjustesConexion->resize(400, 172);
        AjustesConexion->setMinimumSize(QSize(400, 172));
        AjustesConexion->setMaximumSize(QSize(400, 172));
        lineEdit_ip = new QLineEdit(AjustesConexion);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(200, 50, 191, 23));
        lineEdit_puerto = new QLineEdit(AjustesConexion);
        lineEdit_puerto->setObjectName(QStringLiteral("lineEdit_puerto"));
        lineEdit_puerto->setGeometry(QRect(200, 90, 191, 23));
        pushGuardar = new QPushButton(AjustesConexion);
        pushGuardar->setObjectName(QStringLiteral("pushGuardar"));
        pushGuardar->setGeometry(QRect(10, 70, 81, 23));
        pushPorDefecto = new QPushButton(AjustesConexion);
        pushPorDefecto->setObjectName(QStringLiteral("pushPorDefecto"));
        pushPorDefecto->setGeometry(QRect(300, 130, 91, 23));
        label = new QLabel(AjustesConexion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 50, 71, 16));
        label_2 = new QLabel(AjustesConexion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 90, 57, 15));
        label_3 = new QLabel(AjustesConexion);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 130, 151, 20));

        retranslateUi(AjustesConexion);

        QMetaObject::connectSlotsByName(AjustesConexion);
    } // setupUi

    void retranslateUi(QDialog *AjustesConexion)
    {
        AjustesConexion->setWindowTitle(QApplication::translate("AjustesConexion", "Ajustes de conexi\303\263n Cliente", 0));
        pushGuardar->setText(QApplication::translate("AjustesConexion", "Guardar", 0));
        pushPorDefecto->setText(QApplication::translate("AjustesConexion", "Por defecto", 0));
        label->setText(QApplication::translate("AjustesConexion", "IP Servidor", 0));
        label_2->setText(QApplication::translate("AjustesConexion", "Puerto", 0));
        label_3->setText(QApplication::translate("AjustesConexion", "Puerto e Ip por defecto", 0));
    } // retranslateUi

};

namespace Ui {
    class AjustesConexion: public Ui_AjustesConexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTESCONEXION_H
