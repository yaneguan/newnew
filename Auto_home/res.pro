#-------------------------------------------------
#
# Project created by QtCreator 2018-04-10T11:18:36
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = res
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    userspace.cpp \
    option.cpp \
    regst.cpp

HEADERS  += widget.h \
    userspace.h \
    option.h \
    regst.h

FORMS    += widget.ui

RESOURCES += \
    res_.qrc
