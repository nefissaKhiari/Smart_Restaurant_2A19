QT       += core gui sql printsupport multimedia charts multimediawidgets
QT       += network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += SMTP_BUILD

SOURCES += \
    QrCode.cpp \
    arduino.cpp \
    board_widget.cpp \
    carte_fidelite.cpp \
    client.cpp \
    commande.cpp \
    connection.cpp \
    employe.cpp \
    equipements.cpp \
    excel.cpp \
    fournisseur.cpp \
    livraisons.cpp \
    login.cpp \
    main.cpp \
    menu.cpp \
    notepad.cpp \
    notifications.cpp \
    panier.cpp \
    plats.cpp \
    produits.cpp \
    puzzle_board.cpp \
    qcustomplot.cpp \
    restaurant.cpp \
    smtp.cpp \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimecontentformatter.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimemultipart.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/quotedprintable.cpp \
    src/smtpclient.cpp \
    supplement.cpp \
    vehicule.cpp \
    widget.cpp

HEADERS += \
    QrCode.hpp \
    arduino.h \
    board_widget.h \
    carte_fidelite.h \
    client.h \
    commande.h \
    connection.h \
    employe.h \
    equipements.h \
    excel.h \
    fournisseur.h \
    livraisons.h \
    login.h \
    menu.h \
    notepad.h \
    notifications.h \
    panier.h \
    plats.h \
    produits.h \
    puzzle_board.h \
    qcustomplot.h \
    restaurant.h \
    smtp.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h \
    supplement.h \
    vehicule.h \
    widget.h

FORMS += \
    login.ui \
    notepad.ui \
    restaurant.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    TB_Puzzle.pro \
    TB_Puzzle.pro \
    gestionplats-menu.pro \
    gestionproduit-fournisseur.pro \
    notepad.pro

RESOURCES += \
    images.qrc \
    qml.qrc \
    res.qrc \
    resource.qrc \
    resourcee.qrc \
    resourcee.qrc \
    translator.qrc

DISTFILES += \
    Combinear.qss \
    Gestionproduit.pro.user \
    english.qm \
    gestionproduit-fournisseur.pro.user \
    m.mp3 \
    notepad.pro.user \
    notif.png \
    src/Nouveau document texte.txt
