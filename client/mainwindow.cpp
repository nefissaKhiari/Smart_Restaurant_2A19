#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "carte_fidelite.h"
#include "QString"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Affichage tab client
    ui->tableView_client ->setModel(tmpC.afficher());
    ui->tableView_client ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Carte_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(1);

}





void MainWindow::on_pushButton_Client_clicked()
{
       ui->stackedWidgetClient->setCurrentIndex(3);
}


void MainWindow::on_gerer_CF_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(2);

}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(0);

}

void MainWindow::on_re_2_1_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(1);

}

void MainWindow::on_re_3_0_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(0);

}

void MainWindow::on_re_4_3_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(3);

}

void MainWindow::on_gerer_client_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(4);

}

void MainWindow::on_annuler_client_clicked()
{

    ui->stackedWidgetClient->setCurrentIndex(4);
}

void MainWindow::on_pushButton_2_clicked()
{

    ui->stackedWidgetClient->setCurrentIndex(5);
}

void MainWindow::on_ajouter_client_clicked()
{
    client C;

       C.setNom(ui->nom_client->text());
       C.setAge(ui->age_client->text());
       C.setPrenom(ui->prenom_client->text());
       C.setAdresse(ui->adresse->text());
       C.setID(ui->id_client->text());
    C.ajouter();
    ui->nom_client->clear();
    ui->age_client->clear();
    ui->adresse->clear();
    ui->prenom_client->clear();
    ui->id_client->clear();
    ui->stackedWidgetClient->setCurrentIndex(4);
}



void MainWindow::on_supp_client_clicked()
{

    ui->stackedWidgetClient->setCurrentIndex(6);

}

void MainWindow::on_supprimer_client_clicked()
{
    QString ID;
        client C;
     ID=ui->ident_clie_supp->text();

     C.Supprimer (ID);
     ui->stackedWidgetClient->setCurrentIndex(4);

}



void MainWindow::on_re_7_3_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(3);

}

void MainWindow::on_consulter_client_clicked()
{
client C;
ui->stackedWidgetClient->setCurrentIndex(7);

    ui->affichage_client->setModel(C.afficher());
    ui->affichage_client->resizeRowsToContents();
    ui->affichage_client->resizeColumnsToContents();
    ui->affichage_client->show();

}

void MainWindow::on_re_6_4_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(4);

}
