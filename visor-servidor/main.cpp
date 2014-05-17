/*#include "viewerwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Josue");
    QCoreApplication::setApplicationName("Servidor-Visor");
    ViewerWindow w;
    w.show();

    return a.exec();
}
/////////////////////////////////////////////*/

#include "viewerwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    bool daemon = false;
    if(argc >= 2)
    {
       daemon = true;
       pid_t pid;

       // Nos clonamos a nosotros mismos creando un proceso hijo
       pid = fork();

       // Si pid es < 0, fork() falló
       if (pid < 0) {
         // Mostrar la descripción del error y terminar
         std::cerr << strerror(errno) << std::endl;
         exit(10);
       }

       // Si pid es > 0, estamos en el proceso padre
       if (pid > 0) {
         // Terminar el proceso
         exit(0);
       }

       // Abrir una conexión al demonio syslog
       openlog(argv[0], LOG_NOWAIT | LOG_PID, LOG_USER);

       // Intentar crear una nueva sesión

       if (setsid() < 0) {
         syslog(LOG_ERR, "No fue posible crear una nueva sesión\n");
         exit(11);
       }

       // Cambiar directorio de trabajo
       if ((chdir("/")) < 0) {
         syslog(LOG_ERR, "No fue posible cambiar el directorio de trabajo a /\n");
         exit(12);
       }

       // Cerrar los descriptores de la E/S estándar
        close(STDIN_FILENO);            // fd 0
        close(STDOUT_FILENO);           // fd 1
        close(STDERR_FILENO);           // fd 2


       // Abrir nuevos descriptores de E/S
        int fd0 = open("/dev/null", O_RDONLY);  // fd0 == 0
        int fd1 = open("/dev/null", O_WRONLY);  // fd0 == 1
        int fd2 = open("/dev/null", O_WRONLY);  // fd0 == 2

       //Cambiar el usuario efectivo del proceso a 'midemonio'
        //QSettings settings;
        //QSettings settings(APP_CONFFILE, QSettings::IniFormat);
        //passwd* user=getpwnam("midemonio");
        //passwd* user=getpwnam(settings.value("HOSTNSME"));
        //seteuid(user->pw_uid);

       //Cambiar el grupo efectivo del proceso a 'midemonio'
        //group* group=getgrnam("midemonio");
        //setegid(group->gr_gid);

       // Cambiar umask
        umask(0);

       //Enviar un mensaje al demonio syslog
        syslog(LOG_NOTICE, "Demonio iniciado con éxito\n");

       // Hacer archivo con PID
        std::fstream out( (QString("/var/run/") + argv[0] + ".pid").toStdString().c_str());
        out << pid;
        out.close();

      }
        else{
         std::cout << "Parametro incorrecto" << std::endl;
         exit(0);
      }



    // Inicio del programa

    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Josue");
    QCoreApplication::setApplicationName("Servidor-Visor");
    //ViewerWindow w;
    //w.show();
    //Consola cmd;
    //setupUnixSignalHandlers();

    int ret = a.exec();

    if(daemon){
        // Eliminar archivo con PID
        remove((QString("/var/run/") + argv[0] + ".pid").toStdString().c_str());
        // Cuando el demonio termine, cerrar la conexión con el servicio syslog
        closelog();
    }

    return ret;
}
