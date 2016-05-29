#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T16:58:37
#
#-------------------------------------------------

QT       -= core gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    field.cpp \
    vocabulary.cpp \
    playingfield.cpp

HEADERS += \
    field.h \
    vocabulary.h \
    playingfield.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
