#-------------------------------------------------
#
# Project created by QtCreator 2017-08-14T08:51:33
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MTD
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    pixlabelwidget.cpp \
    recordupdatewidgets.cpp \
    resultupdatewidgets.cpp \
    savepicturewidgets.cpp \
    scrollimagewidget.cpp \
    splitscreenlabelwidget.cpp \
    userinfowidgets.cpp \
    ccapturescreenlabel.cpp \
    ccapurescreenhelper.cpp

HEADERS += \
        widget.h \
    common.h \
    pixlabelwidget.h \
    pixmapitemdele.h \
    recordupdatewidgets.h \
    resultupdatewidgets.h \
    savepicturewidgets.h \
    scrollimagewidget.h \
    splitscreenlabelwidget.h \
    userinfowidgets.h \
    ccapturescreenlabel.h \
    ccapurescreenhelper.h

FORMS += \
        widget.ui \
    recordupdatewidgets.ui \
    resultupdatewidgets.ui \
    savepicturewidgets.ui \
    userinfowidgets.ui \

RESOURCES += \
    image.qrc


SUBDIRS += \
    MTD.pro

#添加Camera库
win32: LIBS += -L$$PWD/lib/ -llibMTDCameraCore

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/lib

#添加数据库
win32: LIBS += -L$$PWD/lib/ -llibMTDMed

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/lib
