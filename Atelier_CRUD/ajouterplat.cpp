#include "ajouterplat.h"
#include "ui_ajouterplat.h"
#include "plates.h"

ajouterplat::ajouterplat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouterplat)
{
    ui->setupUi(this);
}

ajouterplat::~ajouterplat()
{
    delete ui;
}

void ajouterplat::on_pushButton_4_clicked()
{

}

void ajouterplat::on_pushButton_clicked()
{

    QString nom=ui->lineEdit_Nomplat->text();
    int prix=ui->lineEdit_Prix->text().toInt();


    plates p( nom,prix);
    ui->ID_plat->setModel(p.AfficherIDPlat());

    bool test=p.ajouter();
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

void ajouterplat::on_Supprimer_clicked()
{
    plates p;
    QMessageBox msgBox;
    p.setIDp(ui->IDP_SUP->text().toInt());

       bool test=p.SupprimerPlat(p.getIDp());



       if(test)
          { msgBox.setText("Suppression avec succes.");

       }
       else
           msgBox.setText("Echec de suppression");
           msgBox.exec();
}


void ajouterplat::on_pushButton_2_clicked()
{
                 int IDp=ui->idplat->text().toInt();
                 QString nom=ui->Nomplat->text();
                 int prix=ui->prixplat->text().toInt();

                 plates p(IDp,nom,prix);
                 bool test=p.ModifierPlat(IDp);
                 if(test){
                     ui->Tab->setModel(p.AfficherPlat());

                     QMessageBox::information(nullptr,"modification Plat","Plat modifie avec succés");
                 }
                 else
                         QMessageBox::warning(nullptr,"Error","Plat non modifie");
             }



void ajouterplat::on_pushButton_3_clicked()
{
    plates p;
    ui->Tab->setModel(p.AfficherPlat());
}
