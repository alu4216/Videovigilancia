#include "viewerwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << "Datos de entrada: " << *argv[1];

    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Josue");
    QCoreApplication::setApplicationName("Cliente-Visor");
    ViewerWindow w;
    if(argc > 1){
        if(*argv[1] == 'v') {
            w.show();
        }
    }
    return a.exec();
}
