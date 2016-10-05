#-------------------------------------------------
#
# Project created by QtCreator 2016-10-05T14:19:24
#
#-------------------------------------------------

QT       -= core gui

TARGET = core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += vocalbulary.cpp \
    field.cpp

HEADERS += vocalbulary.h \
    field.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
