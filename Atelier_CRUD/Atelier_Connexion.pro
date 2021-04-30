#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    commande.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    supplement.cpp

HEADERS += \
    commande.h \
        mainwindow.h \
    connection.h \
    supplement.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resource/1486395871-menu_80607.png \
    resource/1486506264-hamburger-list-menu-options-bars-stack_81469.png \
    resource/1486564397-menu-green_81507.png \
    resource/4285e494cea303a1be4655ca68266ec1.png \
    resource/back.png \
    resource/background.png \
    resource/browsing.png \
    resource/cancel (1).png \
    resource/check.png \
    resource/chercher.png \
    resource/concept-fond-marbre-gris_23-2148773735.png \
    resource/confirm.png \
    resource/confirmation.png \
    resource/cross .png \
    resource/delete.png \
    resource/dish .png \
    resource/document.png \
    resource/edit .png \
    resource/email.png \
    resource/excel (1).png \
    resource/excel (2).png \
    resource/excel.png \
    resource/login.png \
    resource/menu (1).png \
    resource/menu (2).png \
    resource/menu.png \
    resource/message.png \
    resource/pdf (1).png \
    resource/plate.png \
    resource/plus (1).png \
    resource/plus.png \
    resource/printer.png \
    resource/reception-bell.png \
    resource/remove.png \
    resource/restaura.png \
    resource/restaurant (1).png \
    resource/restaurant.png \
    resource/sort.png \
    resource/tray.png \
    resource/vegetables4_b72-.png \
    resource/xls (1).png
