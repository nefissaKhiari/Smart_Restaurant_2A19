#include "gestionplatsmenu.h"
#include "ui_gestionplatsmenu.h"
#include "plats.h"
#include <QPrinter>
#include<QPrintDialog>
#include "menu.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
#include<QTimer>
#include<QDateTime>
#include "smtp.h"
#include <QFileDialog>
#include <QDialog>
#include <QTextDocument>
#include<QPdfWriter>
#include <QDebug>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>


#include<excel.h>



Gestionplatsmenu::Gestionplatsmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestionplatsmenu)
{
    ui->setupUi(this);

       ui->idplats->setModel(P.listId());

    // BEGIN : Afiichage list id
    ui->idList_CB->setModel(P.listId());
    // END : Afiichage list id

    // BEGIN : Affichage : naffichiw fel table view
    ui->plat_tab->setModel(P.afficher());
    // END : Affichage


    // BEGIN : Afiichage list id
    ui->idListME_CB->setModel(M.listId1());
    // END : Afiichage list id

    // BEGIN : Affichage : naffichiw fel table view
    ui->menu_tab->setModel(M.afficher1());
    // END : Affichage
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    QDate date = QDate ::currentDate();
    QString datee=date.toString();
    ui->DateTime_->setText(datee);

}

Gestionplatsmenu::~Gestionplatsmenu()
{
    delete ui;
}


void Gestionplatsmenu:: showTime()
{
    QTime time = QTime::currentTime();

    QString time_text=time.toString("hh : mm : ss");
    if((time.second() % 2) == 0 )
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    ui->Digital_clock->setText(time_text);



}
void Gestionplatsmenu::INFORMER(QLabel *label, QString message, int duration){
    label->setVisible(true);
    label->setText(message);
    QTimer::singleShot(duration, ui->labelmessage, &QLabel::hide);
    QTimer::singleShot(duration, ui->labelmessage2, &QLabel::hide);


}


void Gestionplatsmenu::on_ajouter_B_clicked()
{

    QString nom = ui->nom_LE->text();
    QString ingredient = ui->ingredient_LE->text();
    QString categorie = ui->categorie_LE->text();
    QString prix = ui->prix_LE->text();
    Plats P( nom,ingredient, categorie,prix );
    bool test = P.ajouter();
    if (test)

    {
        ui->plat_tab->setModel(P.afficher()) ;
        INFORMER(ui->labelmessage," PlAT AJOUTE AVEC SUCCES ",3000);
    }
    else

    {INFORMER(ui->labelmessage,"PlAT NON AJOUTE ",3000);
    }
  }
void Gestionplatsmenu::on_ListDelete_B_clicked()
{
    Plats P;
    P.setId(ui->idList_CB->currentText().toInt());
    bool test=P.supprimer(P.getId());
    if (test)

    {
        ui->plat_tab->setModel(P.afficher()) ;
        INFORMER(ui->labelmessage," PlAT Supprimmer AVEC SUCCES ",3000);
    }
    else

    {INFORMER(ui->labelmessage,"PlAT NON AJOUTE ",3000);
    }

}
void Gestionplatsmenu::on_ConfrimEdit_B_clicked()
{
    Plats P1;
 P1.setId(ui->idList_CB->currentText().toInt());
    P1.setNom(ui->nom_LE_Edit->text());
    P1.setIngredient(ui->ingredient_LE_Edit->text());
     P1.setCategorie(ui->categorie_LE_Edit->text());
      P1.setPrix(ui->prix_LE_Edit->text());
      bool test=P1.modifier();

      if(test)
      {
         ui->plat_tab->setModel(P.afficher()) ;
          INFORMER(ui->labelmessage,"MODIFICATION APPLIQUE ",3000);

      }
      else
      {
            INFORMER(ui->labelmessage,"MODIFICATION  non APPLIQUE ",3000);
      }

}

void Gestionplatsmenu::on_ListEdit_B_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->idList_CB->currentText().toInt());
    qry.prepare("SELECT * FROM plats where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {

            ui->nom_LE_Edit->setText(qry.value(1).toString());
            ui->ingredient_LE_Edit->setText(qry.value(2).toString());
            ui->categorie_LE_Edit->setText(qry.value(3).toString());
            ui->prix_LE_Edit->setText(qry.value(4).toString());
        }
    }
    ui->tabWidget->setCurrentIndex(1);
}

void Gestionplatsmenu::on_ListEditME_B_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->idListME_CB->currentText().toInt());
    qry.prepare("SELECT * FROM menu where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {

            ui->nomME_LE_Edit->setText(qry.value(1).toString());
            ui->prixME_LE_Edit->setText(qry.value(2).toString());
              ui->descME_LE_Edit->setText(qry.value(3).toString());
              ui->idplat_LE_Edit->setText(qry.value(4).toString());
        }
    }
    ui->tabWidget->setCurrentIndex(1);
}

void Gestionplatsmenu::on_ListDeleteME_B_clicked()
{
    Menu M;
    M.setId(ui->idListME_CB->currentText().toInt());
    //bool test=M.supprimer1(M.getId());
    if(M.supprimer1(M.getId())) {
        QMessageBox::information(nullptr, QObject::tr("Done"),
                    QObject::tr("Deleted successefully.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
        ui->idListME_CB->setModel(M.listId1());
        ui->menu_tab->setModel(M.afficher1());
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Nope"),
                    QObject::tr("Deleting failed.\n"
                                "Click Ok to exit."), QMessageBox::Ok);
    }

}


void Gestionplatsmenu::on_ajouterME_B_clicked()
{
   int id_plat= ui->idplats->currentText().toInt();
    QString nom = ui->nomME_LE->text();
    QString prix = ui->prixME_LE->text();
    QString description = ui->descME_LE->text();
   Menu M( nom, prix ,description,id_plat );
   bool test = M.ajouter1();
   if (test)

   {
       ui->menu_tab->setModel(M.afficher1()) ;
       INFORMER(ui->labelmessage2," menu AJOUTE AVEC SUCCES ",3000);
   }
   else

   {INFORMER(ui->labelmessage2,"menu NON AJOUTE ",3000);
   }
}

void Gestionplatsmenu::on_ConfrimEditME_B_clicked()
{
    Menu M1 ;
    M1.setId(ui->idListME_CB->currentText().toInt());
    M1.setNom(ui->nomME_LE_Edit->text());
      M1.setPrix(ui->prixME_LE_Edit->text());
      M1.setDescription(ui->descME_LE_Edit->text());
      bool test = M.modifier1();
      if (test)

      {
          ui->menu_tab->setModel(M.afficher1()) ;
          INFORMER(ui->labelmessage2," menu modifier AVEC SUCCES ",3000);
      }
      else

      {INFORMER(ui->labelmessage2,"menu NON AJOUTE ",3000);
      }
}

void Gestionplatsmenu::on_bouton_imprimer_clicked()
{
    /* QPrinter printer;
     printer.setPrinterName("printer");
     QPrintDialog dialog(&printer,this);
     if(dialog.exec()==QDialog::Rejected) return;
     ui->textEdit->print(&printer);*/
         QPrinter printer;
         QPrintDialog *printDialog = new QPrintDialog(&printer, this);
         printDialog->setWindowTitle("Imprimer Document");
         printDialog->exec();
}

void Gestionplatsmenu::on_bouton_imprimer_2_clicked()
{
    /* QPrinter printer;
     printer.setPrinterName("printer");
     QPrintDialog dialog(&printer,this);
     if(dialog.exec()==QDialog::Rejected) return;
     ui->textEdit->print(&printer);*/
         QPrinter printer;
         QPrintDialog *printDialog = new QPrintDialog(&printer, this);
         printDialog->setWindowTitle("Imprimer Document");
         printDialog->exec();
}




void Gestionplatsmenu::on_boutonchercher_clicked()
{
    QString nom =ui->cherchparnom->text();
    QString ingredient = ui->cherchparingredient->text();
    QString categorie = ui->cherchparcategorie->text();
    QString prix = ui->chercherparprix->text();
    if (nom != ""){
   ui->plat_tab->setModel(P.chercherplat(nom)) ;}
    if (ingredient != ""){
   ui->plat_tab->setModel(P.chercherplat1(ingredient)) ;}
    if (categorie!= ""){
   ui->plat_tab->setModel(P.chercherplat2(categorie)) ;}
    if (prix!= ""){
       ui->plat_tab->setModel(P.chercherplat3(prix)) ;}
}

void Gestionplatsmenu::on_boutonafficher_clicked()
{
    ui->plat_tab->setModel(P.afficher()) ;

}




void Gestionplatsmenu::on_trinom_clicked()
{
        ui->plat_tab->setModel(P.afficherTrinom());
}

void Gestionplatsmenu::on_triingredient_clicked()
{
        ui->plat_tab->setModel(P.afficherTriingredient());
}

void Gestionplatsmenu::on_tricategorie_clicked()
{
        ui->plat_tab->setModel(P.afficherTricategorie());
}

void Gestionplatsmenu::on_exporter_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->plat_tab->model()->rowCount();
                        const int columnCount = ui->plat_tab->model()->columnCount();

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Liste des plats </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->plat_tab->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->plat_tab->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0 ; column < columnCount; column++) {
                                if (!ui->plat_tab->isColumnHidden(column)) {
                                    QString data = ui->plat_tab->model()->data(ui->plat_tab->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table> </center>\n"
                            "</body>\n"
                            "</html>\n";

                  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                   QPrinter printer (QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                  /* printer.setPaperSize(QPrinter::A4);*/
                  printer.setOutputFileName(fileName);

                   QTextDocument doc;
                    doc.setHtml(strStream);
                    /*doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number*/
                    doc.print(&printer);

}



void Gestionplatsmenu::on_exporter_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    EXCEL obj(fileName, "mydata", ui->plat_tab);

    //colums to export

    obj.addField(1, "nom", "char(20)");
    obj.addField(2, "ingredient", "char(20)");
    obj.addField(3, "categorie", "char(20)");
     obj.addField(4, "prix", "char(20)");

    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }



}





