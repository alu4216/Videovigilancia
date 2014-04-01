#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T12:39:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visor
TEMPLATE = app


SOURCES += main.cpp\
        viewerwindow.cpp \
    acerca.cpp \
    preferenciadialog.cpp \
    capturebuffer.cpp \
    capturared.cpp \
    clientsocket.cpp

HEADERS  += viewerwindow.h \
    preferenciadialog.h \
    acerca.h \
    capturebuffer.h \
    capturared.h \
    clientsocket.h

FORMS    += viewerwindow.ui \
    acerca.ui \
    preferenciadialog.ui \
    capturared.ui
