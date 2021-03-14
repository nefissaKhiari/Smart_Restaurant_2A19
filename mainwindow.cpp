#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plat.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // BEGIN : CC : Matnajem t7ot ken des nombres fl lineEdit mta3 ID
    ui->id_LE->setValidator(new QIntValidator(1, 99999, this));
    // END : CC

    // BEGIN : Afiichage list id
    ui->idList_CB->setModel(P.listId());
    // END : Afiichage list id

    // BEGIN : Affichage : naffichiw fel table view
    ui->plat_tab->setModel(P.afficher());
    // END : Affichage


}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouter_B_clicked()
{
    int id = ui->id_LE->text().toInt();
    QString nom = ui->nom_LE->text();
    QString ingredient = ui->ingredient_LE->text();
    QString categorie = ui->categorie_LE->text();
      int prix = ui->Prix_LE->text().toInt();
    Plat P(id, nom, ingredient,categorie,prix);
    if(P.ajouter()) {
        QMessageBox::information(nullptr, QObject::tr("Done"),
                    QObject::tr("Added successefully.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
        ui->idList_CB->setModel(P.listId());
        ui->plat_tab->setModel(P.afficher());
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"),
                    QObject::tr("Adding failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    }
}

void MainWindow::on_delete_B_clicked()
{
    P.setId(ui->id_LEdelete->text().toInt());
    //bool test=P.supprimer(P.getId());
    if(P.supprimer(P.getId())) {
        QMessageBox::information(nullptr, QObject::tr("Done"),
                    QObject::tr("Deleted successefully.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
        ui->idList_CB->setModel(P.listId());
        ui->plat_tab->setModel(P.afficher());
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"),
                    QObject::tr("Deleting failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    }
}



void MainWindow::on_ListDelete_B_clicked()
{
   Plat P;
    P.setId(ui->idList_CB->currentText().toInt());
    //bool test=P.supprimer(E.getId());
    if(P.supprimer(P.getId())) {
        QMessageBox::information(nullptr, QObject::tr("Done"),
                    QObject::tr("Deleted successefully.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
        ui->idList_CB->setModel(P.listId());
        ui->plat_tab->setModel(P.afficher());
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"),
                    QObject::tr("Deleting failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    }
}

void MainWindow::on_ListEdit_B_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->idList_CB->currentText().toInt());
    qry.prepare("SELECT * FROM plats where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {
            ui->id_LE_Edit->setText(qry.value(0).toString());
            ui->nom_LE_Edit->setText(qry.value(1).toString());
             ui->ingredient_LE_Edit->setText(qry.value(2).toString());
                ui->categorie_LE_Edit->setText(qry.value(3).toString());
                ui->prix_LE_Edit->setText(qry.value(4).toString());

        }
    }
    ui->tabWidget->setCurrentIndex(0);

    /* ---------------------------------
    Etudiant E3;
    QSqlQueryModel* test = E3.afficherById(ui->idList_CB->currentText().toInt());

    QString id_string = QString::number(ui->idList_CB->currentText().toInt());
    if(test) {
        while(test->query.next()) {
            ui->nom_LE_Edit->setText(test.value(1).toString());
            ui->prenom_LE_Edit->setText(qry.value(2).toString());
        }
    }
    --------------------------------- */
}

void MainWindow::on_BackToConfig_B_clicked()
{
    ui->nom_LE_Edit->setText("");
    ui->ingredient_LE_Edit->setText("");
     ui->categorie_LE_Edit->setText("");
      ui->prix_LE_Edit->setText("");
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_ConfrimEdit_B_clicked()
{
    Plat P2;
    P2.setId(ui->id_LE_Edit->text().toInt());
    P2.setNom(ui->nom_LE_Edit->text());
    P2.setIngredient(ui->ingredient_LE_Edit->text());
     P2.setCategorie(ui->categorie_LE_Edit->text());
     P2.setPrix(ui->prix_LE_Edit->text().toInt());
    if(P2.modifier()) {
        QMessageBox::information(nullptr, QObject::tr("Done"),
                    QObject::tr("Edited successefully.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
        ui->idList_CB->setModel(P2.listId());
        ui->plat_tab->setModel(P2.afficher());
        ui->id_LE_Edit->setText("");
        ui->nom_LE_Edit->setText("");
        ui->ingredient_LE_Edit->setText("");
        ui->categorie_LE_Edit->setText("");
        ui->prix_LE_Edit->setText("");
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"),
                    QObject::tr("Editing failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    }
}

