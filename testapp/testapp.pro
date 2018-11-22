QT = core gui script widgets
SOURCES  += tst_app.cpp

INCLUDEPATH += ../plugin

win32 {
    CONFIG(debug, release|debug):LIBS += -L../debug -lplugin
    CONFIG(release, release|debug):LIBS += -L../release -lplugin 
}

