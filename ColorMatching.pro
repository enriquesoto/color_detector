#-------------------------------------------------
#
# Project created by QtCreator 2014-04-07T08:41:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorMatching
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colordetector.cpp \
    colorDetectController.cpp

HEADERS  += mainwindow.h \
    colordetector.h \
    colorDetectController.h

FORMS    += mainwindow.ui

PKGCONFIG += opencv
CONFIG += link_pkgconfig
