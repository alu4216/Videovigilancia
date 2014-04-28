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
    sslserver.cpp

HEADERS  += viewerwindow.h \
    preferenciadialog.h \
    acerca.h \
    capturebuffer.h \
    capturared.h \
    clientsocket.h \
    bddialog.h \
    sslserver.h


FORMS    += viewerwindow.ui \
    acerca.ui \
    preferenciadialog.ui \
    capturared.ui \
    bddialog.ui \
    capturared.ui
