#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T12:39:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets

CONFIG +=qt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visor_cliente
TEMPLATE = app


SOURCES += main.cpp\
        viewerwindow.cpp \
    acerca.cpp \
    preferenciadialog.cpp \
    capturebuffer.cpp \
    ajustesconexion.cpp \
    deteccion.cpp \
    mydaemon.cpp


HEADERS  += viewerwindow.h \
    preferenciadialog.h \
    acerca.h \
    capturebuffer.h \
    ajustesconexion.h \
    deteccion.h \
    mydaemon.h


FORMS    += viewerwindow.ui \
    acerca.ui \
    preferenciadialog.ui \
    ajustesconexion.ui

include(QtOpenCV.pri)

add_opencv_modules(core video imgproc)


INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_video


####################################################################################

unix {
    # Esta configuración específica de Linux y UNIX
    # Variables
    #
    isEmpty(PREFIX) {
        PREFIX = /usr/local
    }
    MOC_DIR= ./moc
    OBJECTS_DIR=./object
    BINDIR  = $$PREFIX/bin
    CONFDIR = /etc/xdg

    DEFINES += APP_CONFFILE=\\\"$$CONFDIR/$${TARGET}.ini\\\"

    # Install
    INSTALLS += target config

    ## Instalar ejecutable
    target.path = $$BINDIR

    ## Instalar archivo de configuración
    config.path = $$CONFDIR
    config.files += $${TARGET}.ini


}
