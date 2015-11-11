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
    ../app/find_max_commonfactor.cpp \
    ../app/interview.cpp \
    ../app/base_function.cpp

HEADERS += ../app/app.h \
    ../app/find_2_appear_once_number.h \
    ../app/find_max_commonfactor.h \
    ../app/list.h \
    ../app/interview.h \
    ../app/base_function.h

