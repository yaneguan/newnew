#-------------------------------------------------
#
# Project created by QtCreator 2021-03-15T17:04:22
#
#-------------------------------------------------

QT       += core gui

QMAKE_LFLAGS_RELEASE += /MAP
QMAKE_CFLAGS_RELEASE += /Zi
QMAKE_LFLAGS_RELEASE += /debug /opt:ref

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h
