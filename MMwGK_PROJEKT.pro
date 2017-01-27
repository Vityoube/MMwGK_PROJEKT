#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T00:12:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMwGK_PROJEKT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    openglwidget.cpp \
    fish.cpp

HEADERS  += mainwindow.h \
    openglwidget.h \
    fish.h

FORMS    += mainwindow.ui
LIBS    +=  -lfreeimage

DISTFILES += \
    fish_texture.jpg
