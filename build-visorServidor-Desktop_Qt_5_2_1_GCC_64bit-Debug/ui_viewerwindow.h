/********************************************************************************
** Form generated from reading UI file 'viewerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERWINDOW_H
#define UI_VIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
    QAction *actionCaptura_de_Red;
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
    QMenu *menuAcciones;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *ViewerWindow)
    {
        if (ViewerWindow->objectName().isEmpty())
            ViewerWindow->setObjectName(QStringLiteral("ViewerWindow"));
        ViewerWindow->resize(536, 306);
        actionSalir = new QAction(ViewerWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionAbrirImagen = new QAction(ViewerWindow);
        actionAbrirImagen->setObjectName(QStringLiteral("actionAbrirImagen"));
        actionAbrirVideo = new QAction(ViewerWindow);
        actionAbrirVideo->setObjectName(QStringLiteral("actionAbrirVideo"));
        actionAcercaDe = new QAction(ViewerWindow);
        actionAcercaDe->setObjectName(QStringLiteral("actionAcercaDe"));
        actionCapturar = new QAction(ViewerWindow);
        actionCapturar->setObjectName(QStringLiteral("actionCapturar"));
        actionPreferencias = new QAction(ViewerWindow);
        actionPreferencias->setObjectName(QStringLiteral("actionPreferencias"));
        actionAjustes_Conexion = new QAction(ViewerWindow);
        actionAjustes_Conexion->setObjectName(QStringLiteral("actionAjustes_Conexion"));
        actionCaptura_de_Red = new QAction(ViewerWindow);
        actionCaptura_de_Red->setObjectName(QStringLiteral("actionCaptura_de_Red"));
        centralWidget = new QWidget(ViewerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        push_Start = new QPushButton(centralWidget);
        push_Start->setObjectName(QStringLiteral("push_Start"));
        push_Start->setMaximumSize(QSize(125, 25));
        QIcon icon;
        QString iconThemeName = QStringLiteral("play");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
        }
        push_Start->setIcon(icon);

        gridLayout->addWidget(push_Start, 2, 0, 1, 1);

        push_Stop = new QPushButton(centralWidget);
        push_Stop->setObjectName(QStringLiteral("push_Stop"));
        push_Stop->setMaximumSize(QSize(125, 25));

        gridLayout->addWidget(push_Stop, 2, 1, 1, 1);

        Push_Pausa = new QPushButton(centralWidget);
        Push_Pausa->setObjectName(QStringLiteral("Push_Pausa"));
        Push_Pausa->setMaximumSize(QSize(125, 25));

        gridLayout->addWidget(Push_Pausa, 2, 2, 1, 1);

        Salir = new QPushButton(centralWidget);
        Salir->setObjectName(QStringLiteral("Salir"));
        Salir->setMaximumSize(QSize(125, 25));

        gridLayout->addWidget(Salir, 2, 3, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
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
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 536, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAbrir = new QMenu(menuArchivo);
        menuAbrir->setObjectName(QStringLiteral("menuAbrir"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        menu_Preferencias = new QMenu(menuBar);
        menu_Preferencias->setObjectName(QStringLiteral("menu_Preferencias"));
        menuAcciones = new QMenu(menuBar);
        menuAcciones->setObjectName(QStringLiteral("menuAcciones"));
        ViewerWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(ViewerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ViewerWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(ViewerWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        mainToolBar = new QToolBar(ViewerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar_2 = new QToolBar(ViewerWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(ViewerWindow);
        toolBar_3->setObjectName(QStringLiteral("toolBar_3"));
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menu_Preferencias->menuAction());
        menuBar->addAction(menuAcciones->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(menuAbrir->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCapturar);
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
        menuAcciones->addSeparator();
        menuAcciones->addAction(actionCaptura_de_Red);

        retranslateUi(ViewerWindow);

        QMetaObject::connectSlotsByName(ViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerWindow)
    {
        ViewerWindow->setWindowTitle(QApplication::translate("ViewerWindow", "Ventana Servidor", 0));
        actionSalir->setText(QApplication::translate("ViewerWindow", "Salir", 0));
        actionSalir->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+O", 0));
        actionAbrirImagen->setText(QApplication::translate("ViewerWindow", "AbrirImagen", 0));
        actionAbrirVideo->setText(QApplication::translate("ViewerWindow", "AbrirVideo", 0));
        actionAcercaDe->setText(QApplication::translate("ViewerWindow", "AcercaDe", 0));
        actionCapturar->setText(QApplication::translate("ViewerWindow", "Capturar", 0));
        actionPreferencias->setText(QApplication::translate("ViewerWindow", "Preferencias", 0));
        actionAjustes_Conexion->setText(QApplication::translate("ViewerWindow", "Ajustes Conexi\303\263n", 0));
        actionCaptura_de_Red->setText(QApplication::translate("ViewerWindow", "Captura de Red", 0));
        checkBox->setText(QApplication::translate("ViewerWindow", "CheckBox", 0));
        push_Start->setText(QApplication::translate("ViewerWindow", "Start", 0));
        push_Stop->setText(QApplication::translate("ViewerWindow", "Stop", 0));
        Push_Pausa->setText(QApplication::translate("ViewerWindow", "Pausa", 0));
        Salir->setText(QApplication::translate("ViewerWindow", "Salir", 0));
        label->setText(QString());
        menuArchivo->setTitle(QApplication::translate("ViewerWindow", "&Archivo", 0));
        menuAbrir->setTitle(QApplication::translate("ViewerWindow", "Abrir", 0));
        menuAyuda->setTitle(QApplication::translate("ViewerWindow", "A&yuda", 0));
        menu_Preferencias->setTitle(QApplication::translate("ViewerWindow", "&Editar", 0));
        menuAcciones->setTitle(QApplication::translate("ViewerWindow", "Acciones", 0));
        toolBar->setWindowTitle(QApplication::translate("ViewerWindow", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("ViewerWindow", "toolBar_2", 0));
        toolBar_3->setWindowTitle(QApplication::translate("ViewerWindow", "toolBar_3", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewerWindow: public Ui_ViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERWINDOW_H
