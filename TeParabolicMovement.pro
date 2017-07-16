#-------------------------------------------------
#
# Project created by QtCreator 2017-07-16T08:00:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeParabolicMovement
TEMPLATE = app
DEFINES += DEBUG

SOURCES += main.cpp\
        widget.cpp \
    tescene.cpp \
    tethread.cpp \
    teball.cpp

HEADERS  += widget.h \
    tescene.h \
    tethread.h \
    teball.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++14


