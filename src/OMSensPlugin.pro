#-------------------------------------------------
#
# Project created by QtCreator 2019-02-15T13:25:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = $$qtLibraryTarget(OMSensPlugin)
TEMPLATE = lib

SOURCES += main.cpp\
        Widget.cpp

HEADERS  += Widget.h

DESTDIR = ../bin

UI_DIR = ../generatedfiles/ui

MOC_DIR = ../generatedfiles/moc

RCC_DIR = ../generatedfiles/rcc

RESOURCES += \
    resources.qrc
