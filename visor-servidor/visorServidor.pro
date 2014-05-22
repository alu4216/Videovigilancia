#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T12:39:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visor_servidor
TEMPLATE = app


SOURCES += main.cpp\
        viewerwindow.cpp \
    acerca.cpp \
    preferenciadialog.cpp \
    capturebuffer.cpp \
    capturared.cpp \
    clientsocket.cpp \
    bddialog.cpp \
    sslserver.cpp \
    thread.cpp

HEADERS  += viewerwindow.h \
    preferenciadialog.h \
    acerca.h \
    capturebuffer.h \
    capturared.h \
    clientsocket.h \
    bddialog.h \
    sslserver.h \
    thread.h


FORMS    += viewerwindow.ui \
    acerca.ui \
    preferenciadialog.ui \
    capturared.ui \
    bddialog.ui \
    capturared.ui

####################################################################################

unix {
    # Esta configuración específica de Linux y UNIX
    # Variables
    isEmpty(PREFIX) {
        PREFIX = /usr/local
    }
    MOC_DIR= ./moc
    OBJECTS_DIR=./object
    SCRITP_DIR= ./scritp

    BINDIR  = $$PREFIX/bin
    DATADIR = /etc/visor
    CONFDIR = /etc/xdg
    SCRIPT = /etc/init.d

isEmpty(VARDIR) {
        VARDIR  = /var/lib/$${TARGET}
    }

    DEFINES += APP_DATADIR=\\\"$$DATADIR\\\"
    DEFINES += APP_VARDIR=\\\"$$VARDIR\\\"
    DEFINES += APP_CONFFILE=\\\"$$CONFDIR/$${TARGET}.ini\\\"

    # Install
    #
    INSTALLS += target config vardir script

    ## Instalar ejecutable
    target.path = $$BINDIR

    ## Instalar archivo de configuración
    config.path = $$CONFDIR
    config.files += $${TARGET}.ini

    ## Crear directorio de archivos variables
    vardir.path = $$VARDIR
    vardir.commands = :

    ## Meter script en una carpeta
    script.path = $$SCRIPT
    script.files += $${TARGET}.sh
}

