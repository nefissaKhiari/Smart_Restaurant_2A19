#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QQuickItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();


    auto obj = ui->quickWidget->rootObject();
    connect(this,SIGNAL(setCenter(Qvariant,Qvariant)),obj,SLOT(setCenter(Qvariant,Qvariant)));
    emit setCenter(13.000,13.000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

