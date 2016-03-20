#-------------------------------------------------
#
# Project created by QtCreator 2016-03-20T15:00:51
#
#-------------------------------------------------

QT       -= core gui

TARGET = CrosswordAPI
TEMPLATE = lib
CONFIG += staticlib

SOURCES += crosswordapi.cpp

HEADERS += crosswordapi.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
