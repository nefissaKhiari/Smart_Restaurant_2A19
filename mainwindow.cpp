#include "mainwindow.h"
#include "ui_mainwindow.h"
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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
