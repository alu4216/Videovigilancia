/********************************************************************************
** Form generated from reading UI file 'capturared.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURARED_H
#define UI_CAPTURARED_H

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

class Ui_CapturaRed
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushComenzar;
    QPushButton *pushCambiar;
    QPushButton *pushCerrar;

    void setupUi(QDialog *CapturaRed)
    {
        if (CapturaRed->objectName().isEmpty())
            CapturaRed->setObjectName(QStringLiteral("CapturaRed"));
        CapturaRed->resize(342, 112);
        CapturaRed->setMinimumSize(QSize(342, 112));
        CapturaRed->setMaximumSize(QSize(342, 112));
        label = new QLabel(CapturaRed);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 121, 41));
        lineEdit = new QLineEdit(CapturaRed);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 10, 161, 21));
        pushComenzar = new QPushButton(CapturaRed);
        pushComenzar->setObjectName(QStringLiteral("pushComenzar"));
        pushComenzar->setGeometry(QRect(130, 60, 80, 23));
        pushCambiar = new QPushButton(CapturaRed);
        pushCambiar->setObjectName(QStringLiteral("pushCambiar"));
        pushCambiar->setGeometry(QRect(30, 60, 80, 23));
        pushCerrar = new QPushButton(CapturaRed);
        pushCerrar->setObjectName(QStringLiteral("pushCerrar"));
        pushCerrar->setGeometry(QRect(230, 60, 80, 23));

        retranslateUi(CapturaRed);
        QObject::connect(pushCerrar, SIGNAL(clicked()), CapturaRed, SLOT(close()));

        QMetaObject::connectSlotsByName(CapturaRed);
    } // setupUi

    void retranslateUi(QDialog *CapturaRed)
    {
        CapturaRed->setWindowTitle(QApplication::translate("CapturaRed", "Captura de red Servidor", 0));
        label->setText(QApplication::translate("CapturaRed", "Puerto por defecto:", 0));
        pushComenzar->setText(QApplication::translate("CapturaRed", "Comenzar", 0));
        pushCambiar->setText(QApplication::translate("CapturaRed", "Cambiar", 0));
        pushCerrar->setText(QApplication::translate("CapturaRed", "Cerrar", 0));
    } // retranslateUi

};

namespace Ui {
    class CapturaRed: public Ui_CapturaRed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURARED_H
