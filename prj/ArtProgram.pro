TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -fpermissive

#target path
TARGET  = app

#DEFINES += ...

CONFIG(debug, debug|release) {
        DESTDIR += ../Debug
        OBJECTS_DIR += ./DOut
}

CONFIG(release, debug|release) {
        DESTDIR +=../Release
        OBJECTS_DIR += ./ROut
}

INCLUDEPATH =           \
    ../app/             \

SOURCES += ../app/main.cpp \
    ../app/find_2_appear_once_number.cpp \
    ../app/find_max_commonfactor.cpp \
    ../app/interview.cpp \
    ../app/base_function.cpp \
    ../app/ring_queue.c \
    ../app/dp_bag.cpp \
    ../app/dt3106_ini.cpp \
    ../app/iniControl.cpp \
    ../app/atomict1.cpp

HEADERS += ../app/app.h \
    ../app/find_2_appear_once_number.h \
    ../app/find_max_commonfactor.h \
    ../app/list.h \
    ../app/interview.h \
    ../app/base_function.h \
    ../app/ring_queue.h \
    ../app/dp_bag.h \
    ../app/dt3106_ini.h \
    ../app/iniControl.h \
    ../app/atomict1.h

