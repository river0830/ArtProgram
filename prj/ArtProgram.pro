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
    ../app/find_2_appear_once_number.cpp \
    ../app/find_max_commonfactor.cpp

HEADERS += ../app/app.h \
    ../app/find_2_appear_once_number.h \
    ../app/find_max_commonfactor.h \
    ../app/list.h

