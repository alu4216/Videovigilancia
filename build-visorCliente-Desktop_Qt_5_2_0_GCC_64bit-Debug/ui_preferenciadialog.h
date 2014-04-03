/********************************************************************************
** Form generated from reading UI file 'preferenciadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCIADIALOG_H
#define UI_PREFERENCIADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PreferenciaDialog
{
public:
    QComboBox *comboBox;
    QPushButton *pushCerrar;
    QPushButton *pushOk;

    void setupUi(QDialog *PreferenciaDialog)
    {
        if (PreferenciaDialog->objectName().isEmpty())
            PreferenciaDialog->setObjectName(QStringLiteral("PreferenciaDialog"));
        PreferenciaDialog->resize(314, 122);
        PreferenciaDialog->setMinimumSize(QSize(314, 122));
        PreferenciaDialog->setMaximumSize(QSize(314, 122));
        PreferenciaDialog->setSizeGripEnabled(false);
        PreferenciaDialog->setModal(true);
        comboBox = new QComboBox(PreferenciaDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 30, 251, 21));
        pushCerrar = new QPushButton(PreferenciaDialog);
        pushCerrar->setObjectName(QStringLiteral("pushCerrar"));
        pushCerrar->setGeometry(QRect(210, 60, 80, 23));
        pushOk = new QPushButton(PreferenciaDialog);
        pushOk->setObjectName(QStringLiteral("pushOk"));
        pushOk->setGeometry(QRect(120, 60, 80, 23));

        retranslateUi(PreferenciaDialog);

        QMetaObject::connectSlotsByName(PreferenciaDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferenciaDialog)
    {
        PreferenciaDialog->setWindowTitle(QApplication::translate("PreferenciaDialog", "Preferencias Cliente", 0));
        pushCerrar->setText(QApplication::translate("PreferenciaDialog", "Cerrar", 0));
        pushOk->setText(QApplication::translate("PreferenciaDialog", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class PreferenciaDialog: public Ui_PreferenciaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCIADIALOG_H
