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
    workwithvocabulary.cpp

HEADERS += \
    workwithvocabulary.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
