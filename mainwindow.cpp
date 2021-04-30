#include "mainwindow.h"
#include "ui_mainwindow.h"
<<<<<<< HEAD

#include "produits.h"
#include "fournisseur.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QIntValidator>



using namespace qrcodegen;
=======
#include "livraisons.h"
#include "vehicule.h"
#include <qmessagebox.h>
#include <QString>
#include <QIntValidator>
#include<QPdfWriter>
#include <QMessageBox>
#include <QDebug>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QDialog>
#include <QTextDocument>


>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
<<<<<<< HEAD
    ui->setupUi(this);
    animation =new QPropertyAnimation(ui->pushButton,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->pushButton->geometry());
    animation->setEndValue(QRect(500,200,200,100));
      animation ->start();

    animation =new QPropertyAnimation(ui->pushButton_4,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->pushButton_4->geometry());
    animation->setEndValue(QRect(200,500,200,100));
    animation ->start();
    ui->tabWidget->setCurrentIndex(0);
    QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
    tabBar->hide();

    ui->tabproduits->setModel(tmpproduit.afficher());
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());

}

=======
   ui->setupUi(this);

   QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("SELECT ID FROM LIVRAISONS");
   ui->idsupp->setModel(model);
   ui->idmod->setModel(model);
   ui->tabvehicule->setModel(tmpv.afficher1());
   QSqlQueryModel * mod= new QSqlQueryModel();
   mod->setQuery("SELECT ID FROM VEHICULE");
   ui->idvsupp->setModel(mod);
   ui->idvmod->setModel(mod);
    ui->idv_2->setModel(mod);
    ui->idve->setModel(mod);
    ui->idv->setValidator( new QIntValidator(0, 10000, this) );
     ui->idajout->setValidator( new QIntValidator(0, 10000, this) );
      ui->livreurajout->setValidator( new QIntValidator(0, 10000, this) );
          ui->idmod->setValidator( new QIntValidator(0, 10000, this) );
          ui->livreurmod->setValidator( new QIntValidator(0, 10000, this) );

  ui->tablivraison->setModel(tmplivraisons.afficher());



}
>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4

MainWindow::~MainWindow()
{
    delete ui;

}

<<<<<<< HEAD
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
=======



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
>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4
}



<<<<<<< HEAD



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
    ui->tabWidget->setCurrentIndex(3);
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

void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tabWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_7_clicked()
{ui->tabWidget->setCurrentIndex(2);

}

void MainWindow::on_excelfournii_clicked()
{
    Fournisseur f;
              QSqlQueryModel * model=new QSqlQueryModel();
              model=f.Find_fournisseur();
              QString textData= "id_fournisseur ; nom_fournisseur ; prenom_fournisseur ; tel ; id_produit \n";
              int rows=model->rowCount();
              int columns=model->columnCount();
              for (int i = 0; i < rows; i++)
              {
                  for (int j = 0; j < columns; j++)
                  {
                      textData += model->data(model->index(i,j)).toString();
                      textData +=" ; ";
                  }
                  textData += "\n";
              }
              QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
              if (!fileName.isEmpty())
                  if (QFileInfo(fileName).suffix().isEmpty())
                      fileName.append(".csv");
              QFile csvfile(fileName);
              if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
              {
                  QTextStream out(&csvfile);
                  out<<textData;
              }
              csvfile.close();
}

void MainWindow::on_pushButton_2_clicked()
{

    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabfournisseur->model()->rowCount();
                const int columnCount = ui->tabfournisseur->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>liste fournisseur<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ****LISTE DES fournisseurs **** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabfournisseur->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabfournisseur->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabfournisseur->isColumnHidden(column)) {
                            QString data =ui->tabfournisseur->model()->data(ui->tabfournisseur->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

           QPrinter printer;

                QPrintDialog *test = new QPrintDialog(&printer, NULL);
                if (test->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;


}

=======
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
     ui->idv_2->setModel(mod);
     ui->idve->setModel(mod);
     ui->idv->setValidator( new QIntValidator(0, 10000, this) );
      ui->idajout->setValidator( new QIntValidator(0, 10000, this) );
       ui->livreurajout->setValidator( new QIntValidator(0, 10000, this) );
           ui->idmod->setValidator( new QIntValidator(0, 10000, this) );
           ui->livreurmod->setValidator( new QIntValidator(0, 10000, this) );




}





void MainWindow::on_ajout_clicked()
{
       int ID=ui->idajout->text().toInt();
       int ID_LIVREUR=ui->livreurajout->text().toInt();
       int ID_V= ui->idv_2->currentText().toInt();


       livraisons tmplivraisons(ID,ID_LIVREUR, ID_V);
       bool test =tmplivraisons.ajouter();


        if(test){
            QMessageBox::information(nullptr,"Ajout livreur","livreur ajouté avec succés");
            ui->tablivraison->setModel(tmplivraisons.afficher());
            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT ID FROM LIVRAISONS");
            ui->idsupp->setModel(model);
            ui->idmod->setModel(model);
            QSqlQueryModel * mod= new QSqlQueryModel();
            ui->idv_2->setModel(mod);
        }
        else{
                QMessageBox::warning(nullptr,"Error","livraison non ajouter");
}
}


void MainWindow::on_mod_clicked()
{
    int ID=ui->idmod->currentText().toInt();

    int ID_LIVREUR=ui->livreurmod->text().toInt();
    int ID_V= ui->idve->currentText().toInt();

   livraisons tmplivraison (ID,ID_LIVREUR,ID_V);
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



void MainWindow::on_trii_clicked()
{
   ui->tablivraison->setModel(tmplivraisons.trii());

}

void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tablivraison->model()->rowCount();
                    const int columnCount = ui->tablivraison->model()->columnCount();

                    out <<"<html>\n"
                          "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"



                        << "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"



                        "<table style=\"text-align: center; font-size: 30px;\" border=1>\n "
                          "</br> </br>";
                    // headers
                    out << "<thead><tr bgcolor=#d6e5ff>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tablivraison->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tablivraison->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tablivraison->isColumnHidden(column)) {
                                QString data =ui->tablivraison->model()->data(ui->tablivraison->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;

                    QPrintDialog *test = new QPrintDialog(&printer, NULL);
                    if (test->exec() == QDialog::Accepted) {
                        document->print(&printer);
                    }

                    delete document;
}

void MainWindow::on_pushButton_4_clicked()
{

     ui->tabvehicule->setModel(tmpv.tri());
}

void MainWindow::on_pushButton_5_clicked()
{

    ui->tabvehicule->setModel(tmpv.tri());
}




void MainWindow::on_pushButton_clicked()
{

}
>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4
