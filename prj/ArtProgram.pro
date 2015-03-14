TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -fpermissive

#target path
DESTDIR = ../Bin
TARGET  = app

#DEFINES += ...

INCLUDEPATH =           \
    ../app/             \

SOURCES += ../app/main.cpp \
    ../app/find_2_appear_once_number.cpp

HEADERS += ../app/app.h \
    ../app/find_2_appear_once_number.h

