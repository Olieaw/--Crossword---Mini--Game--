#-------------------------------------------------
#
# Project created by QtCreator 2016-04-02T15:13:47
#
#-------------------------------------------------

QT       -= core gui

TARGET = Core
TEMPLATE = lib
CONFIG += staticlib

SOURCES += core.cpp

HEADERS += core.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/./release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/./debug/ -lCore
else:unix: LIBS += -L$$OUT_PWD/./ -lCore

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/./release/libCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/./debug/libCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/./release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/./debug/Core.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/./libCore.a
