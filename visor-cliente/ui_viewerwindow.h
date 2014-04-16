/********************************************************************************
** Form generated from reading UI file 'viewerwindow.ui'
**
** Created: Tue Apr 8 14:10:07 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERWINDOW_H
#define UI_VIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QGui/QAction>
#include <QGui/QApplication>
#include <QGui/QButtonGroup>
#include <QGui/QCheckBox>
#include <QGui/QGridLayout>
#include <QGui/QHeaderView>
#include <QGui/QLabel>
#include <QGui/QMainWindow>
#include <QGui/QMenu>
#include <QGui/QMenuBar>
#include <QGui/QPushButton>
#include <QGui/QStatusBar>
#include <QGui/QToolBar>
#include <QGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewerWindow
{
public:
    QAction *actionSalir;
    QAction *actionAbrirImagen;
    QAction *actionAbrirVideo;
    QAction *actionAcercaDe;
    QAction *actionCapturar;
    QAction *actionPreferencias;
    QAction *actionAjustes_Conexion;
    QAction *actionComenzar_a_enviar;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QPushButton *push_Start;
    QPushButton *push_Stop;
    QPushButton *Push_Pausa;
    QPushButton *Salir;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAbrir;
    QMenu *menuAyuda;
    QMenu *menu_Preferencias;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *ViewerWindow)
    {
        if (ViewerWindow->objectName().isEmpty())
            ViewerWindow->setObjectName(QString::fromUtf8("ViewerWindow"));
        ViewerWindow->resize(536, 306);
        actionSalir = new QAction(ViewerWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionAbrirImagen = new QAction(ViewerWindow);
        actionAbrirImagen->setObjectName(QString::fromUtf8("actionAbrirImagen"));
        actionAbrirVideo = new QAction(ViewerWindow);
        actionAbrirVideo->setObjectName(QString::fromUtf8("actionAbrirVideo"));
        actionAcercaDe = new QAction(ViewerWindow);
        actionAcercaDe->setObjectName(QString::fromUtf8("actionAcercaDe"));
        actionCapturar = new QAction(ViewerWindow);
        actionCapturar->setObjectName(QString::fromUtf8("actionCapturar"));
        actionPreferencias = new QAction(ViewerWindow);
        actionPreferencias->setObjectName(QString::fromUtf8("actionPreferencias"));
        actionAjustes_Conexion = new QAction(ViewerWindow);
        actionAjustes_Conexion->setObjectName(QString::fromUtf8("actionAjustes_Conexion"));
        actionComenzar_a_enviar = new QAction(ViewerWindow);
        actionComenzar_a_enviar->setObjectName(QString::fromUtf8("actionComenzar_a_enviar"));
        centralWidget = new QWidget(ViewerWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        push_Start = new QPushButton(centralWidget);
        push_Start->setObjectName(QString::fromUtf8("push_Start"));
        push_Start->setMaximumSize(QSize(125, 25));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("play");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        push_Start->setIcon(icon);

        gridLayout->addWidget(push_Start, 2, 0, 1, 1);

        push_Stop = new QPushButton(centralWidget);
        push_Stop->setObjectName(QString::fromUtf8("push_Stop"));
        push_Stop->setMaximumSize(QSize(125, 25));

        gridLayout->addWidget(push_Stop, 2, 1, 1, 1);

        Push_Pausa = new QPushButton(centralWidget);
        Push_Pausa->setObjectName(QString::fromUtf8("Push_Pausa"));
        Push_Pausa->setMaximumSize(QSize(125, 25));

        gridLayout->addWidget(Push_Pausa, 2, 2, 1, 1);

        Salir = new QPushButton(centralWidget);
        Salir->setObjectName(QString::fromUtf8("Salir"));
        Salir->setMaximumSize(QSize(125, 25));

        gridLayout->addWidget(Salir, 2, 3, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(50000, 10000));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        ViewerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ViewerWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 536, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuAbrir = new QMenu(menuArchivo);
        menuAbrir->setObjectName(QString::fromUtf8("menuAbrir"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menu_Preferencias = new QMenu(menuBar);
        menu_Preferencias->setObjectName(QString::fromUtf8("menu_Preferencias"));
        ViewerWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(ViewerWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ViewerWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(ViewerWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        mainToolBar = new QToolBar(ViewerWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar_2 = new QToolBar(ViewerWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(ViewerWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menu_Preferencias->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(menuAbrir->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCapturar);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionComenzar_a_enviar);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);
        menuArchivo->addSeparator();
        menuAbrir->addAction(actionAbrirImagen);
        menuAbrir->addSeparator();
        menuAbrir->addAction(actionAbrirVideo);
        menuAbrir->addSeparator();
        menuAyuda->addAction(actionAcercaDe);
        menuAyuda->addSeparator();
        menu_Preferencias->addAction(actionPreferencias);
        menu_Preferencias->addSeparator();
        menu_Preferencias->addAction(actionAjustes_Conexion);
        menu_Preferencias->addSeparator();

        retranslateUi(ViewerWindow);

        QMetaObject::connectSlotsByName(ViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerWindow)
    {
        ViewerWindow->setWindowTitle(QApplication::translate("ViewerWindow", " Ventana Cliente", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("ViewerWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionSalir->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionAbrirImagen->setText(QApplication::translate("ViewerWindow", "AbrirImagen", 0, QApplication::UnicodeUTF8));
        actionAbrirVideo->setText(QApplication::translate("ViewerWindow", "AbrirVideo", 0, QApplication::UnicodeUTF8));
        actionAcercaDe->setText(QApplication::translate("ViewerWindow", "AcercaDe", 0, QApplication::UnicodeUTF8));
        actionCapturar->setText(QApplication::translate("ViewerWindow", "Capturar", 0, QApplication::UnicodeUTF8));
        actionPreferencias->setText(QApplication::translate("ViewerWindow", "Preferencias", 0, QApplication::UnicodeUTF8));
        actionAjustes_Conexion->setText(QApplication::translate("ViewerWindow", "Ajustes Conexi\303\263n", 0, QApplication::UnicodeUTF8));
        actionComenzar_a_enviar->setText(QApplication::translate("ViewerWindow", "Comenzar a enviar", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ViewerWindow", "CheckBox", 0, QApplication::UnicodeUTF8));
        push_Start->setText(QApplication::translate("ViewerWindow", "Start", 0, QApplication::UnicodeUTF8));
        push_Stop->setText(QApplication::translate("ViewerWindow", "Stop", 0, QApplication::UnicodeUTF8));
        Push_Pausa->setText(QApplication::translate("ViewerWindow", "Pausa", 0, QApplication::UnicodeUTF8));
        Salir->setText(QApplication::translate("ViewerWindow", "Salir", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        menuArchivo->setTitle(QApplication::translate("ViewerWindow", "&Archivo", 0, QApplication::UnicodeUTF8));
        menuAbrir->setTitle(QApplication::translate("ViewerWindow", "Abrir", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("ViewerWindow", "A&yuda", 0, QApplication::UnicodeUTF8));
        menu_Preferencias->setTitle(QApplication::translate("ViewerWindow", "&Editar", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("ViewerWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("ViewerWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("ViewerWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewerWindow: public Ui_ViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERWINDOW_H
