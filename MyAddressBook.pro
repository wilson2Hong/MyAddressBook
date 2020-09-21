#-------------------------------------------------
#
# Project created by QtCreator 2020-07-30T10:17:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyAddressBook
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    person.cpp \
    list.cpp

HEADERS  += mainwindow.h \
    node.h \
    person.h \
    list.h

FORMS    += mainwindow.ui
