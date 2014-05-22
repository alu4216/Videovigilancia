#include "viewerwindow.h"
#include <QApplication>
#include "pwd.h"
#include "grp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Josue");
    QCoreApplication::setApplicationName("Servidor-Visor");

    bool daemon = false;
    if(argc >= 3)
    {
        qDebug()<<"ENTRO A DEMONIO";
        daemon = true;
        pid_t pid;

        // Nos clonamos a nosotros mismos creando un proceso hijo
        pid = fork();

        // Si pid es < 0, fork() falló
        if (pid < 0)
        {
            // Mostrar la descripción del error y terminar
            std::cerr << strerror(errno) << std::endl;
            exit(10);
        }

        // Si pid es > 0, estamos en el proceso padre
        if (pid > 0)
        {
            // Terminar el proceso

            exit(0);
        }
        // Cambiar umask
        umask(0);

        // Abrir una conexión al demonio syslog
        openlog(argv[0], LOG_NOWAIT | LOG_PID, LOG_USER);

        // Intentar crear una nueva sesión
        if (setsid() < 0)
        {
            syslog(LOG_ERR, "No fue posible crear una nueva sesión\n");
            exit(11);
        }

        // Cambiar directorio de trabajo
        if ((chdir("/")) < 0)
        {
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
        Q_UNUSED(fd0);
        Q_UNUSED(fd1);
        Q_UNUSED(fd2);

        //Cambiar el usuario efectivo del proceso a 'midemonio'
        QSettings settings;
        //QSettings settings(APP_CONFFILE, QSettings::IniFormat);

        passwd* user=getpwnam(settings.value("USUARIO").toString().toLocal8Bit());
        if(user==NULL)
        {
            syslog(LOG_ERR, "No existe el usuario/\n");
            exit(13);
        }
        seteuid(user->pw_uid);

        //Cambiar el grupo efectivo del proceso a 'midemonio'
        group* group=getgrnam(settings.value("USUARIO").toString().toLocal8Bit());
        if(group==NULL)
        {
            syslog(LOG_ERR, "No existe el grupo/\n");
            exit(14);
        }
        setegid(group->gr_gid);

        //Enviar un mensaje al demonio syslog
        syslog(LOG_NOTICE, "Demonio iniciado con éxito\n");

        // Hacer archivo con PID
        std::fstream out( (QString("/var/run/") + argv[0] + ".pid").toStdString().c_str());
        out << pid;
        out.close();

    }
    else
        std::cout << "Parametro incorrecto" << std::endl;

    // Inicio del programa
    ViewerWindow w;
    if(argc >= 2)
    {
        if(*argv[1]=='v')
            w.show();
    }
    int d = a.exec();

    if(daemon)
    {
        // Eliminar archivo con PID
        remove((QString("/var/run/") + argv[0] + ".pid").toStdString().c_str());
        // Cuando el demonio termine, cerrar la conexión con el servicio syslog
        closelog();
    }
    return d;
}
