#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T00:39:14
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginwindow.cpp \
    publicwindow.cpp \
    managerwindow.cpp

HEADERS  += mainwindow.h \
    loginwindow.h \
    publicwindow.h \
    managerwindow.h

FORMS    += mainwindow.ui \
    loginwindow.ui \
    publicwindow.ui \
    managerwindow.ui
