#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include <qmessagebox.h>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabproduits->setModel(tmpproduit.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pbajouter_clicked()
{ int id=ui->id->text().toInt();
    QString nom_produit=ui->lenom_produit->text();
    QString categorie=ui->lecategorie->text();
    double prix=ui->leprix->text().toDouble();

    Produits tmpproduit(id,nom_produit,categorie,prix);
    bool test=tmpproduit.ajouter();
    if(test){
        ui->tabproduits->setModel(tmpproduit.afficher());
        QMessageBox::information(nullptr,"Ajout produit","Produit ajouté avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Produit non ajouté");
}

void MainWindow::on_supp_clicked()
{
    int id=ui->list_supp->currentText().toInt();
    bool test=tmpproduit.supprimer(id);
    if(test){
        ui->tabproduits->setModel(tmpproduit.afficher());
        QMessageBox::information(nullptr,"suppression produit","Produit supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Produit non supprimer");
}



void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabproduits->setModel(tmpproduit.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM PRODUITS");
    ui->list_supp->setModel(model);


    ui->idmod->setModel(model);

}



void MainWindow::on_modifier_clicked()
{
    int id=ui->idmod->currentText().toInt();
    QString nom_produit=ui->nommod->text();
    QString categorie=ui->categoriemod->text();
    double prix=ui->prixmod->text().toDouble();
    Produits tmpproduit(id,nom_produit,categorie,prix);
    bool test=tmpproduit.modifier(id);
    if(test){
        ui->tabproduits->setModel(tmpproduit.afficher());

        QMessageBox::information(nullptr,"modification produit","Produit modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Produit non modifie");

    }


