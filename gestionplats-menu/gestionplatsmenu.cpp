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
#include "notifications.h"




#include<excel.h>



Gestionplatsmenu::Gestionplatsmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestionplatsmenu)
{
    ui->setupUi(this);

    ui->tabWidget_2->setCurrentIndex(0);
    QTabBar *tabBar = ui->tabWidget_2->findChild<QTabBar *>();
    tabBar->hide();
    ui->idmenu->setModel(M.listId1());
     ui->idmenu_2->setModel(M.listId1());

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
    QSqlQuery qry;
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    player = new QMediaPlayer(this);
    connect(player, &QMediaPlayer::positionChanged, this,&Gestionplatsmenu::on_positionChanged );
        connect(player, &QMediaPlayer::durationChanged, this,&Gestionplatsmenu::on_durationChanged );


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
    bool overAll = false, nom_B, categorie_B, prix_B;
int id_menu= ui->idmenu->currentText().toInt();
    QString nom = ui->nom_LE->text();

    QString categorie = ui->categorie_LE->text();
    QString prix = ui->prix_LE->text();
     QString type = ui->type->currentText();
     if(nom.length() < 3) {
                   nom_B = false;
                    ui->nomcs->setText("Il faut  au moins 3 charactere ");
                    ui->nomcs->setStyleSheet("QLabel{color: red; font-size: 12px;}");
                }
                else {
                    nom_B = true;
                   nom[0] = nom[0].toUpper();
                    ui->nomcs->setText("Ok");
                    ui->nomcs->setStyleSheet("QLabel{color: green; font-size: 12px;}");
                }
     if(prix.length() <1) {
                   prix_B = false;
                    ui->prixcs->setText("Il faut  maximum1 charactere ");
                    ui->prixcs->setStyleSheet("QLabel{color: red; font-size: 12px;}");
                }
                else {
                    prix_B = true;
                   prix[0] = prix[0].toUpper();
                    ui->prixcs->setText("Ok");
                    ui->prixcs->setStyleSheet("QLabel{color: green; font-size: 12px;}");
                }
     if(categorie.length() >2) {
                   categorie_B = false;
                    ui->categoriecs->setText("Il faut  au moins depasse pas 2 charactere ");
                    ui->categoriecs->setStyleSheet("QLabel{color: red; font-size: 12px;}");
                }
                else {
                    categorie_B = true;
                   categorie[0] = categorie[0].toUpper();
                    ui->categoriecs->setText("Ok");
                    ui->categoriecs->setStyleSheet("QLabel{color: green; font-size: 12px;}");
                }
     (nom_B && prix_B && categorie_B)? overAll = true : overAll = false;
                if(overAll) {
    Plats P( nom, categorie,prix,type,id_menu );

    bool test = P.ajouter();
    if (test)

    {
        ui->plat_tab->setModel(P.afficher()) ;
        Notifications N;
         N.notifications_ajouterplat();
        INFORMER(ui->labelmessage," PlAT AJOUTE AVEC SUCCES ",3000);
    }
    else

    {INFORMER(ui->labelmessage,"PlAT NON AJOUTE ",3000);
    }
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
        Notifications N;
         N.notifications_supprimerplat();
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
    P1.setNom(ui->nom_LE_2->text());

     P1.setCategorie(ui->categorie_LE_2->text());
      P1.setPrix(ui->prix_LE_2->text());
      P1.setType(ui->type_2->currentText());
      P1.setId_menu(ui->idmenu_2->currentText().toInt());
      qDebug() << P1.getType();
      bool test=P1.modifier();

      if(test)
      {
         ui->plat_tab->setModel(P.afficher()) ;
         Notifications N;
          N.notifications_modifierplat();
          INFORMER(ui->labelmessage,"MODIFICATION APPLIQUE ",3000);

      }
      else
      {
            INFORMER(ui->labelmessage,"MODIFICATION  non APPLIQUE ",3000);
      }
  ui->tabWidget_2->setCurrentIndex(1);
}

void Gestionplatsmenu::on_ListEdit_B_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->idList_CB->currentText().toInt());
    qry.prepare("SELECT * FROM plats where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {

            ui->nom_LE_2->setText(qry.value(1).toString());

            ui->categorie_LE_2->setText(qry.value(2).toString());
            ui->prix_LE_2->setText(qry.value(3).toString());
               ui->type_2->setCurrentText(qry.value(4).toString());
               ui->idmenu_2->setCurrentText(qry.value(5).toString());
        }
    }
    ui->tabWidget_2->setCurrentIndex(2);
}

void Gestionplatsmenu::on_ListEditME_B_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->idListME_CB->currentText().toInt());
    qry.prepare("SELECT * FROM menu where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {

            ui->nomME_LE_2->setText(qry.value(1).toString());
            ui->prixME_LE_2->setText(qry.value(2).toString());
              ui->descME_LE_2->setText(qry.value(3).toString());

        }
    }
    ui->tabWidget_2->setCurrentIndex(4);
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




void Gestionplatsmenu::on_ConfrimEditME_B_clicked()
{
    Menu M1 ;
    M1.setId(ui->idListME_CB->currentText().toInt());
    M1.setNom(ui->nomME_LE_2->text());
      M1.setPrix(ui->prixME_LE_2->text());
      M1.setDescription(ui->descME_LE_2->text());
      bool test = M1.modifier1();
      if (test)

      {
          ui->menu_tab->setModel(M.afficher1()) ;
          Notifications N;
           N.notifications_modifiermenu();
          INFORMER(ui->labelmessage2," menu modifier AVEC SUCCES ",3000);
      }
      else

      {INFORMER(ui->labelmessage2,"menu NON AJOUTE ",3000);
      }
       ui->tabWidget_2->setCurrentIndex(3);
}

void Gestionplatsmenu::on_bouton_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->plat_tab->model()->rowCount();
                const int columnCount = ui->plat_tab->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                    << "<title>Plats LIST<title>\n "

                    << "</head>\n"
                    "<body bgcolor=#d6e5ff link=#5000A0>\n"

                    "<h1 style=\"text-align: center;\"><strong> ****LISTE DES PLATS **** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->plat_tab->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->plat_tab->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->plat_tab->isColumnHidden(column)) {
                            QString data =ui->plat_tab->model()->data(ui->plat_tab->model()->index(row, column)).toString().simplified();
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
















void Gestionplatsmenu::on_exporter_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    EXCEL obj(fileName, "mydata", ui->plat_tab);

    //colums to export
 obj.addField(0, "id", "number");
    obj.addField(1, "nom", "char(20)");

    obj.addField(2, "categorie", "char(20)");
     obj.addField(3, "type", "char(20)");
      obj.addField(4, "prix", "char(20)");
      obj.addField(5, "id_menu", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }

}


















void Gestionplatsmenu::on_pushButton_3_clicked()
{
     ui->menu_tab->setModel(M.afficher1()) ;
}

void Gestionplatsmenu::on_exporterM_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->menu_tab->model()->rowCount();
                const int columnCount = ui->menu_tab->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                    << "<title>MENU LIST<title>\n "

                    << "</head>\n"
                    "<body bgcolor=#d6e5ff link=#5000A0>\n"

                    "<h1 style=\"text-align: center;\"><strong> ****LISTE DES MENU **** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->menu_tab->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->menu_tab->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->menu_tab->isColumnHidden(column)) {
                            QString data =ui->menu_tab->model()->data(ui->menu_tab->model()->index(row, column)).toString().simplified();
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

void Gestionplatsmenu::on_exporterXM_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    EXCEL obj(fileName, "mydata", ui->menu_tab);

    //colums to export
 obj.addField(0, "id", "number");
    obj.addField(1, "nom", "char(20)");
    obj.addField(2, "prix", "char(20)");
    obj.addField(3, "description", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }

}



void Gestionplatsmenu::on_bouton_imprimer_3_clicked()
{
    ui->tabWidget_2->setCurrentIndex(5);
}




void Gestionplatsmenu::on_pushButton_5_clicked()
{
     ui->tabWidget_2->setCurrentIndex(3);
}

void Gestionplatsmenu::on_pushButton_6_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);


}

void Gestionplatsmenu::on_bouton_imprimer_4_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}

void Gestionplatsmenu::on_pushButton_clicked()
{
   ui->tabWidget_2->setCurrentIndex(1);
}

void Gestionplatsmenu::on_pushButton_2_clicked()
{
  ui->tabWidget_2->setCurrentIndex(0);
}



void Gestionplatsmenu::on_chercher_textChanged(const QString &arg1)
{
    QString by=ui->listechercher->currentText();
            ui->plat_tab->setModel(P.chercher(arg1,by));

}

void Gestionplatsmenu::on_trier_clicked()
{
    QString Tri = ui->listtrier->currentText();
            ui->plat_tab->setModel(P.Trier(Tri));
}





void Gestionplatsmenu::on_pushButton_8_clicked()
{
    ui->plat_tab->setModel(P.afficher()) ;
    INFORMER(ui->labelmessage,"LISTE PLAT CHARGEE   ",3000);
}



void Gestionplatsmenu::on_pushButton_9_clicked()
{

        QString nom = ui->nomME_LE->text();



        QString prix = ui->prixME_LE->text();
         QString description = ui->descME_LE->text();

      Menu M( nom, description,prix);
      bool test = M.ajouter1();
      if (test)

      {

          ui->menu_tab->setModel(M.afficher1()) ;
          Notifications N;
           N.notifications_ajoutermenu();
          INFORMER(ui->labelmessage2," MENU AJOUTE AVEC SUCCES ",3000);

      }
      else

      {INFORMER(ui->labelmessage2,"MENU NON AJOUTE ",3000);
      }
}
void Gestionplatsmenu::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   Gestionplatsmenu::sendMail()
{
    Smtp* smtp = new Smtp("farah.hasnaoui@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("farah.hasnaoui@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("farah.hasnaoui@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   Gestionplatsmenu::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void Gestionplatsmenu::on_chercher_2_textChanged(const QString &arg1)
{
    QString by=ui->listechercher_2->currentText();
            ui->menu_tab->setModel(M.chercher1(arg1,by));
}

void Gestionplatsmenu::on_trier_2_clicked()
{
    QString Tri = ui->listtrier_2->currentText();
            ui->menu_tab->setModel(M.Trier1(Tri));
}

void Gestionplatsmenu::on_pushButton_10_clicked()
{
    ui->menu_tab->setModel(M.afficher1()) ;
    INFORMER(ui->labelmessage2,"LISTE Menu CHARGEE   ",3000);
}

void Gestionplatsmenu::on_sliderprog_sliderMoved(int position)
{
player->setPosition(position);
}

void Gestionplatsmenu::on_slidervolume_sliderMoved(int position)
{
player->setVolume(position);
}

void Gestionplatsmenu::on_pushButton_18_clicked()
{
    //load file
    player->setMedia(QUrl("C:/Users/Home/Documents/gestionplats-menu/m.mp3"));
    player->play();
    qDebug()<< player->errorString();
}

void Gestionplatsmenu::on_pushButton_19_clicked()
{
    player->stop();
}

void Gestionplatsmenu::on_positionChanged(qint64 position)
{
    ui->sliderprog->setValue(position);
}

void Gestionplatsmenu::on_durationChanged(qint64 position)
{
ui->sliderprog->setMaximum(position);
}

void Gestionplatsmenu::on_stat_clicked()
{
   ui->tabWidget_2->setCurrentIndex(6);
}

void Gestionplatsmenu::on_pushButton_20_clicked()
{
      ui->tabWidget_2->setCurrentIndex(1);
}


