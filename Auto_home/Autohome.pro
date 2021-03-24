#-------------------------------------------------
#
# Project created by QtCreator 2018-04-19T20:29:29
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Autohome
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    regst.cpp \
    userspace.cpp \
    option.cpp

HEADERS  += widget.h \
    regst.h \
    userspace.h \
    option.h

FORMS    += widget.ui

RESOURCES += \
    res.qrc
