#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livraisons.h"
#include <qmessagebox.h>
#include <QString>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   ui->tablivraison->setModel(tmplivraisons.afficher());

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
        ui->tablivraison->setModel(tmplivraisons.afficher());
        QMessageBox::information(nullptr,"suppression livraison","livraison supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","livraison non supprimer");
}



void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tablivraison->setModel(tmplivraisons.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM LIVRAISONS");
    ui->idsupp->setModel(model);
    ui->idmod->setModel(model);

}



void MainWindow::on_modifier_clicked()
{
    int ID=ui->idmod->currentText().toInt();
    int DATE_L=ui->datemod->text().toInt();
    int ID_LIVREUR=ui->livreurmod->text().toInt();

    livraisons tmplivraison (ID,DATE_L,ID_LIVREUR);
    bool test=tmplivraison.modifier(ID);
    if(test){
        ui->tablivraison->setModel(tmplivraison.afficher());

        QMessageBox::information(nullptr,"modification livraison","livraison modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","livraison non modifie");

    }



void MainWindow::on_ajout_clicked()
{
    int ID=ui->idajout->text().toInt();
       int DATE_L=ui->dateajout->text().toInt();
       int ID_LIVREUR=ui->livreurajout->text().toInt();


       livraisons tmplivraisons(ID,DATE_L,ID_LIVREUR);
       tmplivraisons.ajouter();


        /*if(test){
           ui->tablivraison->setModel(tmplivraisons.afficher());
            QMessageBox::information(nullptr,"Ajout livreur","livreur ajouté avec succés");
        }
        else{
                QMessageBox::warning(nullptr,"Error","livraison non ajouter");
}*/
}


void MainWindow::on_mod_clicked()
{
    int ID=ui->idmod->currentText().toInt();
    int DATE_L=ui->datemod->text().toInt();
    int ID_LIVREUR=ui->livreurmod->text().toInt();

    livraisons tmplivraison (ID,DATE_L,ID_LIVREUR);
    bool test=tmplivraison.modifier(ID);
    if(test){
        ui->tablivraison->setModel(tmplivraison.afficher());

        QMessageBox::information(nullptr,"modification livraison","livraison modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","livraison non modifie");
}
