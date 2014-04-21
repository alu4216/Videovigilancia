#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T12:39:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
CONFIG +=qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = visor
TEMPLATE = app


SOURCES += main.cpp\
        viewerwindow.cpp \
    acerca.cpp \
    preferenciadialog.cpp \
    capturebuffer.cpp \
    ajustesconexion.cpp \
    deteccion.cpp

HEADERS  += viewerwindow.h \
    preferenciadialog.h \
    acerca.h \
    capturebuffer.h \
    ajustesconexion.h \
    deteccion.h

FORMS    += viewerwindow.ui \
    acerca.ui \
    preferenciadialog.ui \
    ajustesconexion.ui

include(QtOpenCV.pri)

add_opencv_modules(core video imgproc)

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
