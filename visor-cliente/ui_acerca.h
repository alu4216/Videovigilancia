/********************************************************************************
** Form generated from reading UI file 'acerca.ui'
**
** Created: Sat May 3 14:10:07 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACERCA_H
#define UI_ACERCA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Acerca
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_texto;
    QHBoxLayout *horizontalLayout_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Acerca)
    {
        if (Acerca->objectName().isEmpty())
            Acerca->setObjectName(QString::fromUtf8("Acerca"));
        Acerca->resize(403, 291);
        Acerca->setMaximumSize(QSize(500, 300));
        horizontalLayout = new QHBoxLayout(Acerca);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Acerca);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_texto = new QLabel(Acerca);
        label_texto->setObjectName(QString::fromUtf8("label_texto"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_texto->sizePolicy().hasHeightForWidth());
        label_texto->setSizePolicy(sizePolicy1);
        label_texto->setScaledContents(true);
        label_texto->setWordWrap(true);
        label_texto->setMargin(1);

        verticalLayout->addWidget(label_texto);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(100, -1, -1, -1);
        buttonBox = new QDialogButtonBox(Acerca);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy2);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 10);

        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Acerca);
        QObject::connect(buttonBox, SIGNAL(accepted()), Acerca, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Acerca, SLOT(reject()));

        QMetaObject::connectSlotsByName(Acerca);
    } // setupUi

    void retranslateUi(QDialog *Acerca)
    {
        Acerca->setWindowTitle(QApplication::translate("Acerca", "Acerca de Cliente", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_texto->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Acerca: public Ui_Acerca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACERCA_H
