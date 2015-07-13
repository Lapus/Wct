#-------------------------------------------------
#
# Project created by QtCreator 2015-03-01T11:16:43
#QMAKE_LFLAGS+=-m32
#QMAKE_CXXFLAGS += -m32
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wcteditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    highlighter.cpp

HEADERS  += mainwindow.h \
    highlighter.h


FORMS    += mainwindow.ui

RC_FILE = main.rc
