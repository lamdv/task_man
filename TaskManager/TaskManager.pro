#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T02:18:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaskManager
TEMPLATE = app


SOURCES += main.cpp\
        taskmanager.cpp \
    warning.cpp \
    Process.cpp

HEADERS  += taskmanager.h \
    warning.h \
    Process.h

FORMS    += taskmanager.ui \
    warning.ui
