/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notepad
{
public:
    QAction *actionNew;
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionSave_AS;
    QAction *actioncut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionRedo;
    QAction *actionUndo;
    QAction *actionabout_notepad;
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *notepad)
    {
        if (notepad->objectName().isEmpty())
            notepad->setObjectName(QStringLiteral("notepad"));
        notepad->resize(674, 519);
        actionNew = new QAction(notepad);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/rec/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionopen = new QAction(notepad);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/rec/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon1);
        actionsave = new QAction(notepad);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rec/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave->setIcon(icon2);
        actionSave_AS = new QAction(notepad);
        actionSave_AS->setObjectName(QStringLiteral("actionSave_AS"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/rec/img/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_AS->setIcon(icon3);
        actioncut = new QAction(notepad);
        actioncut->setObjectName(QStringLiteral("actioncut"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/rec/img/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncut->setIcon(icon4);
        actionCopy = new QAction(notepad);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/rec/img/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(notepad);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/rec/img/paste .png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionRedo = new QAction(notepad);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/rec/img/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon7);
        actionUndo = new QAction(notepad);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/rec/img/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionabout_notepad = new QAction(notepad);
        actionabout_notepad->setObjectName(QStringLiteral("actionabout_notepad"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/rec/img/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionabout_notepad->setIcon(icon9);
        centralwidget = new QWidget(notepad);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit);

        notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(notepad);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 674, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(notepad);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(notepad);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        notepad->addToolBar(Qt::LeftToolBarArea, toolBar);
        toolBar_2 = new QToolBar(notepad);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        notepad->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionopen);
        menuFile->addAction(actionsave);
        menuFile->addAction(actionSave_AS);
        menuEdit->addAction(actioncut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionUndo);
        menuAbout->addAction(actionabout_notepad);
        toolBar_2->addAction(actionNew);
        toolBar_2->addAction(actionopen);
        toolBar_2->addAction(actionsave);
        toolBar_2->addAction(actionSave_AS);
        toolBar_2->addAction(actioncut);
        toolBar_2->addAction(actionCopy);
        toolBar_2->addAction(actionPaste);
        toolBar_2->addAction(actionRedo);
        toolBar_2->addAction(actionUndo);
        toolBar_2->addAction(actionabout_notepad);

        retranslateUi(notepad);

        QMetaObject::connectSlotsByName(notepad);
    } // setupUi

    void retranslateUi(QMainWindow *notepad)
    {
        notepad->setWindowTitle(QApplication::translate("notepad", "notepad", Q_NULLPTR));
        actionNew->setText(QApplication::translate("notepad", "New", Q_NULLPTR));
        actionopen->setText(QApplication::translate("notepad", "open", Q_NULLPTR));
        actionsave->setText(QApplication::translate("notepad", "save", Q_NULLPTR));
        actionSave_AS->setText(QApplication::translate("notepad", "Save as", Q_NULLPTR));
        actioncut->setText(QApplication::translate("notepad", "cut", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("notepad", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("notepad", "Paste", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("notepad", "Redo", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("notepad", "Undo", Q_NULLPTR));
        actionabout_notepad->setText(QApplication::translate("notepad", "about notepad", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("notepad", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("notepad", "Edit", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("notepad", "About", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("notepad", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("notepad", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class notepad: public Ui_notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
