#-------------------------------------------------
#
# Project created by QtCreator 2013-07-01T22:40:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIdemo1
TEMPLATE = app


SOURCES += main.cpp\
        maingui.cpp \
    dialoggui.cpp \
    qzigbeethread.cpp \
    posix_qextserialport.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    entrancedialog.cpp \
    qmessagethread.cpp \
    gprsdialog.cpp \
    sosdialog.cpp \
    sos_settings_dialog.cpp \
    smoke_alert_dialog.cpp

HEADERS  += maingui.h \
    dialoggui.h \
    qzigbeethread.h \
    posix_qextserialport.h \
    qextserialbase.h \
    qextserialport.h \
    entrancedialog.h \
    qmessagethread.h \
    gprsdialog.h \
    sosdialog.h \
    sos_settings_dialog.h \
    smoke_alert_dialog.h

FORMS    += maingui.ui \
    dialoggui.ui \
    entrancedialog.ui \
    gprsdialog.ui \
    sosdialog.ui \
    sos_settings_dialog.ui \
    smoke_alert_dialog.ui

RESOURCES += \
    resource.qrc
