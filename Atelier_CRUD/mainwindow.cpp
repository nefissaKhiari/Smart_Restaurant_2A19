#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tab->setModel(x.AfficherCommande());
}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::on_pushButton_clicked()
{
    int num=ui->lineEdit_Num->text().toInt();
    QString date=ui->lineEdit_date->text();
    int idemploye=ui->lineEdit_Idemploye->text().toInt();

    Commande c(num,date,idemploye);

    bool test=c.ajouter();
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Ajout effectué\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_Supprimer_clicked()
{
    Commande C;
    QMessageBox msgBox;
    C.setNum(ui->NUMCsupp->text().toInt());

       bool test=C.SupprimerCommande(C.getNum());



       if(test)
          { msgBox.setText("Suppression avec succes.");
       ui->Tab->setModel(C.AfficherCommande());
       }
       else
           msgBox.setText("Echec de suppression");
           msgBox.exec();
}
