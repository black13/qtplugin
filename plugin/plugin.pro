QT = core gui script widgets testlib

TEMPLATE = lib

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS = $$PWD/plugin.h
SOURCES = $$PWD/plugin.cpp
DEFINES += TEST

win32 {
    CONFIG(debug, release|debug):DESTDIR = ../debug
    CONFIG(release, release|debug):DESTDIR = ../release
}