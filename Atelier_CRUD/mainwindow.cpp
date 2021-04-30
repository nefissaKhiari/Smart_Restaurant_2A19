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
void MainWindow::on_AddCommande_clicked()
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
void MainWindow::on_SupprimerCommande_clicked()
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
    ui->ID_Employe->setValidator( new QIntValidator(0, 1000, this) );
    ui->lineEdit_prix_supp->setValidator( new QIntValidator(0, 100000, this) );
    ui->lineEdit_prix_sup->setValidator( new QIntValidator(0, 100000, this) );
    ui->qtyplat->setValidator( new QIntValidator(0, 1000000, this) );
    ui->lineEdit_Idemploye_2->setValidator( new QIntValidator(0, 1000, this) );
    ui->lineEdit_QTY->setValidator( new QIntValidator(0, 100000, this) );
    ui->lineEdit_QTY_2->setValidator( new QIntValidator(0, 100000, this) );
    ui->qtysupp->setValidator( new QIntValidator(0, 100000, this) );

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

    qint32 qty=ui->lineEdit_QTY->text().toInt();
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


void MainWindow::on_RecuCommande_clicked()
{
    QMessageBox msg1;
    QItemSelectionModel *select1 = ui->Tab->selectionModel();
    if (!select1->hasSelection()){
         msg1.setText("Please select something");

         msg1.setIcon(msg1.Critical);
         msg1.exec();
         return;
    }
    QSqlQuery query ;
    query.prepare("select c.*, p.nom, p.prix, cp.qty, s.nom, s.prix, sc.qty from Commandes c, Plates p, CommandePlat cp,supplement s,suppcom sc where cp.numc = c.numc and cp.id_plat = p.idp and sc.numc = c.numc and sc.ids= s.ids and cp.numc = :numc and sc.numc = :numc");
    QItemSelectionModel *select = ui->Tab->selectionModel();
    QString idcom=select->selectedRows().at(0).data().toString();
    query.bindValue(":numc", idcom);
    query.exec();
    //BarCode
    QStringList args = {idcom};
    args << "D:/Facture/barcode.jpg";
    QProcess::execute(QString("libs\\barcode\\barcode.exe"),args);

    // date, totale
    QMessageBox msg;
    msg.setText(QString("Reçu Imprimer"));
    msg.exec();
    QString html =
    "<center><style>table { border: 5px solid black; }</style><div align=right>"
       "Tunis le, %1"
    "</div>"
    "<div align=left>"
       "Smart Restaurant<br>"
       "Esprit<br>"

    "</div>"
    "<h1 align=center>Facture</h1>"
    "<p align=justify>"
     "<table width=400>"
            "<tr>"
            "<th width=50>Plate</th>"
            "<th width=50>Unique Price</th>"
            "<th width=50>Quantity</th>"

            "<th width=50>Supplement</th>"
            "<th width=50>Unique Price</th>"
            "<th width=50>Quantity</th>"
            "<th width=50>Total</th>"


         "</tr>"
            "%2"

            "</table>"
    "</p>"
    "<div align=right>Total: %3</div><center> <img src=\"data:image/png;base64,%4\" width=\"200\", height=\"80\"/>";

    QString row =  "<tr>"
                     "<td style='border: 1px solid #000000 '>%1</td>"
                     "<td>%2</td>"
                     "<td>%3</td>"
                     "<td>%4</td>"
                        "<td>%5</td>"
                        "<td>%6</td>"
                            "<td>%7</td>"


                  "</tr>";
    QString rows = "";
    int numc, idemp, prixtot;
    QString date;
    while(query.next()){
         numc = query.value(0).toInt();
         idemp = query.value(1).toInt();
         date = query.value(2).toString();
         prixtot = query.value(3).toInt();

        QString platename = query.value(4).toString();
        int uniqueprice = query.value(5).toInt();
        int qty = query.value(6).toInt();
        QString Supname = query.value(7).toString();
        int uniquepricesup = query.value(8).toInt();
        int qtysup = query.value(9).toInt();


        if (qty > 0)
        rows.append(row.arg(platename).arg(uniqueprice).arg( qty).arg(Supname).arg(uniquepricesup).arg(qtysup).arg(qty * uniqueprice + qtysup * uniquepricesup));
    }


    QTextDocument document;
    document.setDefaultStyleSheet(QString(""

                                          "td, th { text-align: left; border: 2px solid black;} "

                                          "table {margin-right:auto;margin-left:auto;text-align: left; border: 1px solid ;margin-top:60px;width: 80%;}"
                                          ""));


    QPixmap p;
      QImageReader r("D:/Facture/barcode.jpg");
      r.setDecideFormatFromContent(true);
      QImage i = r.read();
      if (!i.isNull())
         p = QPixmap::fromImage(i);


    // add resource
 qDebug() << p.width();
 QImage image = p.toImage();
  QByteArray byteArray;

  QBuffer buffer(&byteArray);

     image.save(&buffer, "JPEG"); // writes the image in JPEG format inside the buffer

     QString iconBase64 = QString::fromLatin1(byteArray.toBase64().data());
    document.setHtml(html.arg(date).arg(rows).arg( prixtot).arg(iconBase64));

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("D:/Facture/Recu.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    QPdfWriter pdfWriter("D:/test2.pdf");
    pdfWriter.setPageSize(QPagedPaintDevice::A4);
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));
    document.print(&pdfWriter);
    document.print(&printer);
}



