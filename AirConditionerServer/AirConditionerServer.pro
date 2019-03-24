#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T20:49:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirConditionerServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    manager.cpp \
    reception.cpp

HEADERS  += mainwindow.h \
    manager.h \
    reception.h

FORMS    += mainwindow.ui
