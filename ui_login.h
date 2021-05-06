/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *mdp;
    QLineEdit *user;
    QPushButton *pushButton_connect;
    QPushButton *quitter;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(140, 120, 401, 401));
        frame->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(3, 163, 179, 255), stop:1 rgba(255, 255, 255, 255));"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        mdp = new QLineEdit(frame);
        mdp->setObjectName(QStringLiteral("mdp"));
        mdp->setGeometry(QRect(120, 190, 181, 31));
        user = new QLineEdit(frame);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(120, 130, 181, 31));
        pushButton_connect = new QPushButton(frame);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(110, 290, 81, 31));
        quitter = new QPushButton(frame);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(230, 290, 81, 31));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 140, 91, 16));
        label->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 200, 101, 20));
        label_2->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 75 11pt \"MS Shell Dlg 2\";"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(280, 40, 120, 80));
        frame_2->setStyleSheet(QStringLiteral("image: url(:/resource/login (2).png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "MainWindow", Q_NULLPTR));
        mdp->setPlaceholderText(QApplication::translate("login", "motdepasse...", Q_NULLPTR));
        user->setText(QString());
        user->setPlaceholderText(QApplication::translate("login", "votre nom..", Q_NULLPTR));
        pushButton_connect->setText(QApplication::translate("login", "connecter", Q_NULLPTR));
        quitter->setText(QApplication::translate("login", "quitter", Q_NULLPTR));
        label->setText(QApplication::translate("login", " nom utilisateur", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "mot de passe", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
