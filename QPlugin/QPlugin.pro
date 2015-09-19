#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T11:00:55
#
#-------------------------------------------------

CONFIG      += plugin
TARGET      = $$qtLibraryTarget(baseplugin)

LIBS        += -L.

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

TEMPLATE = lib

EXAMPLE_FILES = qbaseplugin.json

QT += widgets

SOURCES += \
    widget.cpp \
    baseplugin.cpp

HEADERS +=\
    qbaseplugin.h \
    widget.h \
    baseplugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    widget.ui
