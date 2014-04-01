#include "viewerwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Josue");
    QCoreApplication::setApplicationName("Cliente-Visor");
    ViewerWindow w;
    w.show();

    return a.exec();
}
