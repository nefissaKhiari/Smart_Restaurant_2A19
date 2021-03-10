#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <qmessagebox.h>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabemploye->setModel(tmpemploye.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;

}






void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabemploye->setModel(tmpemploye.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM EMPLOYE");
    ui->idsup->setModel(model);


    ui->idmodifier->setModel(model);

}



void MainWindow::on_modifier_clicked()
{
    int id=ui->idmodifier->currentText().toInt();
    QString nom=ui->nommodifier->text();
    QString prenom=ui->prenommodifier->text();
    QString adresse=ui->adressemodifier->text();
    int telephone=ui->telmodifier->text().toInt();
    Employe tmpemploye(id,nom,prenom,adresse,telephone);
    bool test=tmpemploye.modifier(id);
    if(test){
        ui->tabemploye->setModel(tmpemploye.afficher());

        QMessageBox::information(nullptr,"modification employe","employe modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","employe non modifie");

    }

void MainWindow::on_ajout_clicked()
{
    int id=ui->idajout->text().toInt();
        QString nom=ui->nomajout->text();
        QString prenom=ui->prenomajout->text();
        QString adresse=ui->adresseajout->text();
        int telephone=ui->telephoneajout->text().toInt();

        Employe tmpemploye(id,nom,prenom,adresse,telephone);
        bool test=tmpemploye.ajouter();
        if(test){
            ui->tabemploye->setModel(tmpemploye.afficher());
            QMessageBox::information(nullptr,"Ajout employe","employe ajouté avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","employe non ajouté");

}

void MainWindow::on_sup_clicked()
{
    int id=ui->idsup->currentText().toInt();
    bool test=tmpemploye.supprimer(id);
    if(test){
        ui->tabemploye->setModel(tmpemploye.afficher());
        QMessageBox::information(nullptr,"suppression employe","employe supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","employe non supprimer");
}
