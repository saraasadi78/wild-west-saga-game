#-------------------------------------------------
#
# Project created by QtCreator 2020-01-02T12:32:15
#
#-------------------------------------------------

QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wwsmenu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    job.cpp \
    state.cpp \
    setting.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    game.h \
    job.h \
    state.h \
    setting.h \
    dialog.h

FORMS    += mainwindow.ui \
    game.ui \
    state.ui \
    setting.ui \
    dialog.ui

RESOURCES += \
    res.qrc
