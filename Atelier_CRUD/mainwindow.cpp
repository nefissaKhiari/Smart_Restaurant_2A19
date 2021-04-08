#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "supplement.h"
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QHeaderView>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include <QtWidgets>



MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);


}

MainWindow::~MainWindow()
{

    delete ui;

}
void MainWindow::UpdateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->lbl_time_2->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->lbl_time_3->setText(QTime::currentTime().toString("hh:mm:ss"));


}
void MainWindow::on_pushButton_5_clicked()
{


    int idp=ui->ID_Employe->text().toInt();

    Commande c(idp);

    bool test=c.ajouter();
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
this->RefreshTables();


}


void MainWindow::on_Supprimer_clicked()
{


           QMessageBox msg;
           QItemSelectionModel *select = ui->Tab->selectionModel();
           if (!select->hasSelection()){
                msg.setText("Please select a plate");

                msg.setIcon(msg.Critical);
                msg.exec();
                return;
           }
           QString IdCom=select->selectedRows().at(0).data().toString();
           msg.setText(IdCom);
           msg.exec();
           int Num = QString (IdCom).toInt();
           Commande c;
           bool test=c.SupprimerCommande(Num);
           if (test)
               {
               QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                  QObject::tr("Suppression effectuée avec succès\n"
                                                              "click cancel to exit."),QMessageBox::Cancel);
               }
           else
               QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("suppression non effectué.\n"
                                                 "click Cancel to exit."),QMessageBox::Cancel);
       this->RefreshTables();

       }


void MainWindow::on_pushButton_4_clicked()
{

        QMessageBox msg;
QItemSelectionModel *select = ui->Tab->selectionModel();
    QString idrow=select->selectedRows().at(0).data().toString();
        msg.setText(idrow);
        msg.exec();
}



void MainWindow::on_pushButton_midifier_clicked()
{
        int num=ui->NUMCmodif->currentText().toInt();
        int idemploye=ui->lineEdit_Idemploye_2->text().toInt();
       Commande c(idemploye);
        bool test=c.modifierEmployer(num);
        if(test){
            this->RefreshTables();
            QMessageBox::information(nullptr,"modification Commande","Commande modifie avec succés");
}
}
void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    showEventHelper();
}

void MainWindow::RefreshTables(){
    ui->Tab->setModel(x.AfficherCommande());
    ui->Tab2->setModel(x.AfficherPlat());
    ui->Tab3_2->setModel(t.AfficherSupplement());
    ui->Tab3->setModel(t.AfficherSupplement());


    /**********tri_tab_com*************/
            QSqlQueryModel * myModel1=new QSqlQueryModel(ui->Tab);
            QSqlQuery select2;
            if (!select2.exec("select * from COMMANDES")) {
                QMessageBox msg;
                msg.setText("sorted");

                msg.setIcon(msg.Critical);
                msg.exec();
            }
            else {
                myModel1->setQuery(select2);
                QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(myModel1); // create proxy
                proxyModel->setSourceModel(myModel1);
                ui->Tab->setSortingEnabled(true); // enable sortingEnabled
                ui->Tab->setModel(proxyModel);
            }

    /**********tri_tab_com*************/
            /**********tri_tab_plates*************/
                    QSqlQueryModel * myModel2=new QSqlQueryModel(ui->Tab2);
                    QSqlQuery select1;
                    if (!select1.exec("select * from PLATES")) {
                        QMessageBox msg;
                        msg.setText("Not sorted");

                        msg.setIcon(msg.Critical);
                        msg.exec();
                    }
                    else {

                        myModel2->setQuery(select1);
                        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(myModel2); // create proxy
                        proxyModel->setSourceModel(myModel2);
                        ui->Tab2->setSortingEnabled(true); // enable sortingEnabled
                        ui->Tab2->setModel(proxyModel);
                    }

            /**********tri_tab_plates*************/

/**********tri_tab_sup*************/
        QSqlQueryModel * myModel7=new QSqlQueryModel(ui->Tab3_2);
        QSqlQuery select7;
        if (!select7.exec("select * from SUPPLEMENT")) {
            QMessageBox msg;
            msg.setText("sorted");

            msg.setIcon(msg.Critical);
            msg.exec();
        }
        else {
            myModel7->setQuery(select7);
            QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(myModel7); // create proxy
            proxyModel->setSourceModel(myModel7);
            ui->Tab3_2->setSortingEnabled(true); // enable sortingEnabled
            ui->Tab3_2->setModel(proxyModel);
        }

/**********tri_tab_sup*************/



        /**********tri_tab_sup2*************/
                QSqlQueryModel * myModel9=new QSqlQueryModel(ui->Tab3);
                QSqlQuery select9;
                if (!select9.exec("select * from SUPPLEMENT")) {
                    QMessageBox msg;
                    msg.setText("sorted");

                    msg.setIcon(msg.Critical);
                    msg.exec();
                }
                else {
                    myModel9->setQuery(select9);
                    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(myModel9); // create proxy
                    proxyModel->setSourceModel(myModel9);
                    ui->Tab3->setSortingEnabled(true); // enable sortingEnabled
                    ui->Tab3->setModel(proxyModel);
                }

        /**********tri_tab_sup2*************/

    ui->Tab3->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->Tab3_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->Tab->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->Tab2->setSelectionBehavior(QAbstractItemView::SelectRows);
    /************************************/
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT NUMC FROM COMMANDES");
    ui->NUMCmodif->setModel(model);
    ui->IDSmodif->setModel(model);
    /*******************************************/

    QTableView * view = new QTableView();
    view->verticalHeader()->hide();

}
void MainWindow::showEventHelper()
{
   this->RefreshTables();
}

void MainWindow::on_getid_clicked()
{
    QMessageBox msg;
    QItemSelectionModel *select = ui->Tab2->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select a plate");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString IdPlat=select->selectedRows().at(0).data().toString();

    int qty=ui->qtyplat->text().toInt();
    int platid = QString (IdPlat).toInt();
    Commande c;
    bool test=c.ajouterPlat(platid,qty);
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
this->RefreshTables();

}

void MainWindow::on_UpdateQuantity_clicked()
{
    QMessageBox msg;
    QItemSelectionModel *select = ui->Tab2->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select a plate");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString IDplat=select->selectedRows().at(0).data().toString();

    int qty=ui->lineEdit_QTY->text().toInt();
    int num=ui->NUMCmodif->currentText().toInt();
    int platid = QString (IDplat).toInt();
    Commande c;
    bool test=c.modifierQTY(num,platid,qty);
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
this->RefreshTables();

}

void MainWindow::on_ADD_supp_clicked()
{
    QString nomsup=ui->lineEdit_nom_supp->text();
    QString typesup=ui->lineEdit_Type_supp->text();
    int prixsup=ui->lineEdit_prix_supp->text().toInt();
    supplement s(nomsup,typesup,prixsup);

    bool test=s.ajouterSup();
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
    this->RefreshTables();
}

void MainWindow::on_Delete_sup_clicked()
{
    QMessageBox msg;
    QItemSelectionModel *select = ui->Tab3_2->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select something");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString IdSup=select->selectedRows().at(0).data().toString();
    int idsup = QString (IdSup).toInt();
    supplement c;
    bool test=c.SupprimerSupp(idsup);
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Suppression effectuée avec succès\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("suppression non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
this->RefreshTables();


}

void MainWindow::on_Modifier_Nom_sup_clicked()
{
    QMessageBox msg;
    QString nomsup=ui->lineEdit_nom_sup->text();
    QString typesup=ui->lineEdit_type_sup->text();
    int prixsup=ui->lineEdit_prix_sup->text().toInt();
    QItemSelectionModel *select = ui->Tab3_2->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select something");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString IdSup=select->selectedRows().at(0).data().toString();
    int idsup = QString (IdSup).toInt();
    supplement c(nomsup,typesup,prixsup);
    bool test=c.modifierSupplement(idsup);
    if (test)
        {
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                           QObject::tr("Modification effectuée avec succès\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);
        }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Modification non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);
this->RefreshTables();



}




void MainWindow::on_ADD_supp_4_clicked()
{
    QMessageBox msg;
    QItemSelectionModel *select = ui->Tab3->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select a Something");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString idsup=select->selectedRows().at(0).data().toString();

    int qty=ui->qtysupp->text().toInt();
    int supid = QString (idsup).toInt();
    supplement c;
    bool test=c.AjouterSuppcom(supid,qty);
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
this->RefreshTables();
}

void MainWindow::on_UpdateQuantity_2_clicked()
{
    QMessageBox msg;
    QItemSelectionModel *select = ui->Tab3->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select something");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString idsup=select->selectedRows().at(0).data().toString();
    msg.setText(idsup);
    msg.exec();
    int qty=ui->lineEdit_QTY_2->text().toInt();
    int num=ui->IDSmodif->currentText().toInt();
    int supid = QString (idsup).toInt();
    supplement c;
    bool test=c.modifierQTYsup(num,supid,qty);
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
this->RefreshTables();

}


void MainWindow::on_serchsup_textEdited(const QString &arg1)
{

    ui->Tab3_2->setModel(t.chercher(ui->serchsup->text()));
}





void MainWindow::on_serchcom_textEdited(const QString &arg1)
{
    ui->Tab->setModel(x.chercherCom(ui->serchcom->text()));
}
