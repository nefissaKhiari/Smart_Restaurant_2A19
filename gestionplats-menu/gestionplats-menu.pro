
QT       += core gui sql network
QT       += core gui printsupport
QT += core  network
CONFIG +=

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    excel.cpp \
    main.cpp \
    gestionplatsmenu.cpp \
    menu.cpp \
    plats.cpp \
    smtp.cpp

HEADERS += \
    connection.h \
    excel.h \
    gestionplatsmenu.h \
    menu.h \
    plats.h \
    smtp.h

FORMS += \
    gestionplatsmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
