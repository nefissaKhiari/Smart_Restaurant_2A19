#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livraisons.h"
#include "vehicule.h"
#include <qmessagebox.h>
#include <QString>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   ui ->tablivraison->setModel(tmplivraisons.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;

}




void MainWindow::on_supp_clicked()
{
    QString ID=ui->idsupp->currentText();
    bool test=tmplivraisons.supprimer(ID);
    if(test){
        QMessageBox::information(nullptr,"suppression livraison","livraison supprimer avec succés");
        ui->tablivraison->setModel(tmplivraisons.afficher());
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT ID FROM LIVRAISONS");
        ui->idsupp->setModel(model);
        ui->idmod->setModel(model);
    }
    else
            QMessageBox::warning(nullptr,"Error","livraison non supprimer");
}



void MainWindow::on_tabWidget_currentChanged(int)
{
    ui->tablivraison->setModel(tmplivraisons.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM LIVRAISONS");
    ui->idsupp->setModel(model);
    ui->idmod->setModel(model);
    ui->tabvehicule->setModel(tmpv.afficher1());
    QSqlQueryModel * mod= new QSqlQueryModel();
    mod->setQuery("SELECT ID FROM VEHICULE");
    ui->idvsupp->setModel(mod);
    ui->idvmod->setModel(mod);

}





void MainWindow::on_ajout_clicked()
{
    int ID=ui->idajout->text().toInt();
       int DATE_L=ui->dateajout->text().toInt();
       int ID_LIVREUR=ui->livreurajout->text().toInt();


       livraisons tmplivraisons(ID,DATE_L,ID_LIVREUR);
       bool test =tmplivraisons.ajouter();


        if(test){
            QMessageBox::information(nullptr,"Ajout livreur","livreur ajouté avec succés");
            ui->tablivraison->setModel(tmplivraisons.afficher());
            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT ID FROM LIVRAISONS");
            ui->idsupp->setModel(model);
            ui->idmod->setModel(model);
        }
        else{
                QMessageBox::warning(nullptr,"Error","livraison non ajouter");
}
}


void MainWindow::on_mod_clicked()
{
    int ID=ui->idmod->currentText().toInt();
    int DATE_L=ui->datemod->text().toInt();
    int ID_LIVREUR=ui->livreurmod->text().toInt();

   livraisons tmplivraison (ID,DATE_L,ID_LIVREUR);
    bool test=tmplivraison.modifier();
    if(test){
        ui->tablivraison->setModel(tmplivraison.afficher());

        QMessageBox::information(nullptr,"modification livraison","livraison modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","livraison non modifie");
}

void MainWindow::on_modv_clicked()
{

    int id_vehicule=ui->idvmod->currentText().toInt();
    QString modele=ui->modelemod->text();
    QString etat=ui->etatmod->text();

    Vehicule tmpv (id_vehicule,modele,etat);
    bool test=tmpv.modifier1(id_vehicule);
    if(test){


        QMessageBox::information(nullptr,"modification vehicule","vehicule modifie avec succés");
        ui->tabvehicule->setModel(tmpv.afficher1());
        QSqlQueryModel * mod= new QSqlQueryModel();
        mod->setQuery("SELECT ID FROM VEHICULE");
        ui->idvsupp->setModel(mod);
        ui->idvmod->setModel(mod);

    }
    else
            QMessageBox::warning(nullptr,"Error","vehicule non modifie");

}

void MainWindow::on_suppv_clicked()
{

    QString id_vehicule=ui->idvsupp->currentText();
    bool test=tmpv.supprimer1(id_vehicule);
    if(test){

        QMessageBox::information(nullptr,"suppression vehicule","vehicule supprimer avec succés");
        ui->tabvehicule->setModel(tmpv.afficher1());
        QSqlQueryModel * mod= new QSqlQueryModel();
        mod->setQuery("SELECT ID FROM VEHICULE");
        ui->idvsupp->setModel(mod);
        ui->idvmod->setModel(mod);
    }
    else
            QMessageBox::warning(nullptr,"Error","vehicule non supprimer");
}

void MainWindow::on_ajoutv_clicked()
{
        int ID=ui->idv->text().toInt();
        QString MODELLE=ui->modele->text();
        QString ETAT=ui->etat->text();


       Vehicule vehicule(ID,MODELLE,ETAT);
       bool test =vehicule.ajouter();


        if(test){
            QMessageBox::information(nullptr,"Ajout vehicule","vehicule ajouté avec succés");
            ui->tabvehicule->setModel(tmpv.afficher1());
            QSqlQueryModel * mod= new QSqlQueryModel();
            mod->setQuery("SELECT ID FROM VEHICULE");
            ui->idvsupp->setModel(mod);
            ui->idvmod->setModel(mod);

        }
        else{
                QMessageBox::warning(nullptr,"Error","vehicule non ajouter");
}
}





void MainWindow::on_recherche_textEdited(const QString &arg1)
{
    livraisons L;
    ui->tablivraison->setModel(L.rechercher(ui->recherche->text()));
}
