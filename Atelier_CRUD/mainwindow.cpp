#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QHeaderView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QtWidgets>
#include "ajouterplat.h"


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
    QString nomp=ui->PLAT_dispo->currentText();

    Commande c(num,date,idemploye,nomp);

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
    ui->Tab->setModel(x.AfficherCommande());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NUMC FROM COMMANDES");
    ui->NUMCsupp->setModel(model);

}

void MainWindow::on_Supprimer_clicked()
{


           int num=ui->NUMCsupp->currentText().toInt();
           bool test=x.SupprimerCommande(num);

           if(test){
               QMessageBox::information(nullptr,"suppression Commande","Commande supprimer avec succés");
               ui->Tab->setModel(x.AfficherCommande());
               QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("SELECT NUMC FROM COMMANDES");
               ui->NUMCsupp->setModel(model);

           }
           else
                   QMessageBox::warning(nullptr,"Error","Commande non supprimer");
}

void MainWindow::on_pushButton_4_clicked()
{

    ajouterplat Ajouterplat;
    Ajouterplat.setModal(true);
    Ajouterplat.exec();
}



void MainWindow::on_pushButton_midifier_clicked()
{
        int num=ui->lineEdit_Num_2->text().toInt();
        QString date=ui->dateedit->text();
        QString nomp=ui->nomplatdisp->currentText();
        int idemploye=ui->lineEdit_Idemploye_2->text().toInt();
       Commande c(num,date,idemploye,nomp);
        bool test=c.modifierCommande();
        if(test){
            ui->Tab->setModel(c.AfficherCommande());

            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT NUMC FROM COMMANDES");
            ui->NUMCsupp->setModel(model);

            QMessageBox::information(nullptr,"modification Commande","Commande modifie avec succés");
}
}
void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    showEventHelper();
}

void MainWindow::showEventHelper()
{
    ui->Tab->setModel(x.AfficherCommande());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NUMC FROM COMMANDES");
    ui->NUMCsupp->setModel(model);
    QTableView * view = new QTableView();
    view->verticalHeader()->hide();

}

