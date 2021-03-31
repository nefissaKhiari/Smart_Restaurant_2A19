#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_statistiques.h"
#include "produits.h"
#include "fournisseur.h"
#include <qmessagebox.h>
#include <QIntValidator>
using namespace qrcodegen;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tabproduits->setModel(tmpproduit.afficher());
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());

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


void MainWindow::on_tabWidgett_currentChanged(int index)
{
    {
        ui->tabproduits->setModel(tmpproduit.afficher());
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT ID FROM PRODUITS");
        ui->list_supp->setModel(model);
        ui->idmod->setModel(model);

        ui->tabfournisseur->setModel(tmpfournisseur.afficher());
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("SELECT id_fournisseur FROM FOURNISSEUR");
        ui->idfmod->setModel(model1);
        ui->idfrssup->setModel(model1);


    }
}


/*fourniii*/






void MainWindow::on_ajoutfrs_clicked()
{
    { int id_fournisseur=ui->idfrs->text().toInt();
        QString nom_fournisseur=ui->nomfrs->text();
        QString prenom_fournisseur=ui->prenomfrs->text();
        int tel=ui->telfrs->text().toInt();
        int id_produit=ui->fkfrs->text().toInt();

        Fournisseur tmpfournisseur(id_fournisseur,nom_fournisseur,prenom_fournisseur,tel,id_produit);
        bool test=tmpfournisseur.ajouter();
        if(test){
            ui->tabfournisseur->setModel(tmpfournisseur.afficher());
            QMessageBox::information(nullptr,"Ajout fournisseur","fournisseur ajouté avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","fournisseur non ajouté");}
}

void MainWindow::on_frsmod_2_clicked()
{
    int id_fournisseur=ui->idfmod->currentText().toInt();
    QString nom_fournisseur=ui->frsmod->text();
    QString prenom_fournisseur=ui->prenomfrsmod->text();
    int tel=ui->telfrs->text().toInt();
       int id_produit=ui->fgmod->text().toInt();
    Fournisseur tmpfournisseur(id_fournisseur,nom_fournisseur,prenom_fournisseur,tel,id_produit);
    bool test=tmpfournisseur.modifier(id_fournisseur);
    if(test){
        ui->tabfournisseur->setModel(tmpfournisseur.afficher());

        QMessageBox::information(nullptr,"modification d'un fournisseur","fournisseur modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","fournisseur non modifie");

}













void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->tabproduits->setModel(tmpproduit.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM PRODUITS");
    ui->list_supp->setModel(model);
    ui->idmod->setModel(model);

    ui->tabfournisseur->setModel(tmpfournisseur.afficher());
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("SELECT id_fournisseur FROM FOURNISSEUR");
    ui->idfmod->setModel(model1);
    ui->idfrssup->setModel(model1);

}

void MainWindow::on_QRcode_clicked()
{
    int tabprod=ui->tabproduits->currentIndex().row();
    QVariant idd=ui->tabproduits->model()->data(ui->tabproduits->model()->index(tabprod,0));
    int id= idd.toInt();
    QSqlQuery qry;
    qry.prepare("select * from produits where id=:id");
    qry.bindValue(":id",id);
    qry.exec();
    QString produit,cateogrie,price,ids;
    while(qry.next()){
        produit=qry.value(1).toString();
        cateogrie=qry.value(2).toString();
        price=qry.value(3).toString();
    }
    ids=QString::number(id);
    ids="ID: "+ids+" Nom: "+produit+" Categorie: "+cateogrie+" Prix: "+price;
    QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);

    // Read the black & white pixels
    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabel->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_frssupp_clicked()
{
    int id_fournisseur=ui->idfrssup->currentText().toInt();
    bool test=tmpfournisseur.supprimer(id_fournisseur);
    if(test){
        ui->tabfournisseur->setModel(tmpfournisseur.afficher());
        QMessageBox::information(nullptr,"suppression fournisseur","fournisseur supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","fournisseur non supprimer");

}

void MainWindow::on_stat_clicked()
{
    Produits p;


    p.stat(ui->widget);

}

void MainWindow::on_search_textEdited(const QString &arg1)
{
    Fournisseur f;
    ui->tabfournisseur->setModel(f.chercher(ui->search->text()));
}

void MainWindow::on_tri_clicked()
{
    ui->tabfournisseur->setModel(tmpfournisseur.tri());

}
