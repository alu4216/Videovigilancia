/********************************************************************************
** Form generated from reading UI file 'capturebuffer.ui'
**
** Created: Tue Apr 8 14:10:07 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTUREBUFFER_H
#define UI_CAPTUREBUFFER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptureBuffer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CaptureBuffer)
    {
        if (CaptureBuffer->objectName().isEmpty())
            CaptureBuffer->setObjectName(QString::fromUtf8("CaptureBuffer"));
        CaptureBuffer->resize(800, 600);
        centralwidget = new QWidget(CaptureBuffer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CaptureBuffer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CaptureBuffer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        CaptureBuffer->setMenuBar(menubar);
        statusbar = new QStatusBar(CaptureBuffer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CaptureBuffer->setStatusBar(statusbar);

        retranslateUi(CaptureBuffer);

        QMetaObject::connectSlotsByName(CaptureBuffer);
    } // setupUi

    void retranslateUi(QMainWindow *CaptureBuffer)
    {
        CaptureBuffer->setWindowTitle(QApplication::translate("CaptureBuffer", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CaptureBuffer: public Ui_CaptureBuffer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTUREBUFFER_H
