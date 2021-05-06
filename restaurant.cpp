#include "restaurant.h"
#include "ui_restaurant.h"
#include "plats.h"
#include <QPrinter>
#include<QPrintDialog>
#include "menu.h"
#include <QtCore>
#include <QMessageBox>
#include "livraisons.h"
#include "vehicule.h"
#include <QIntValidator>
#include <QtWidgets>
#include <QSqlQuery>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include<QTimer>
#include "widget.h"
#include<QDateTime>
#include<QVideoWidget>
#include "smtp.h"
#include <QFileDialog>
#include <QDialog>
#include <QTextDocument>
#include <notepad.h>
#include<QPdfWriter>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <restaurant.h>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include "notifications.h"
#include "qcustomplot.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include "produits.h"
#include "fournisseur.h"
#include <qmessagebox.h>
#include <QIntValidator>

#include <QCategoryAxis>
#include <QPieSeries>
#include <QPieSlice>
#include "employe.h"
#include "equipements.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include<excel.h>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QIntValidator>



using namespace qrcodegen;
restaurant::restaurant(QWidget *parent):
  QMainWindow (parent),
     ui(new Ui::restaurant)
{
    ui->setupUi(this);
    refrech();

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

    animation =new QPropertyAnimation(ui->gestionfourni,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->gestionfourni->geometry());
    animation->setEndValue(QRect(500,200,200,100));
      animation ->start();

    animation =new QPropertyAnimation(ui->gestionprod,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->gestionprod->geometry());
    animation->setEndValue(QRect(200,300,200,100));
    animation ->start();



    ui->tabproduits->setModel(tmpproduit.afficher());
    ui->tabfournisseur->setModel(tmpfournisseur.afficher());

    ui->tabemploye->setModel(tmpemploye.afficher());

    ui->tabequipement->setModel(tmpequipement.afficher());

     ui->stackedWidget->setCurrentIndex(1);
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
    connect(player, &QMediaPlayer::positionChanged, this,&restaurant::on_positionChanged );
        connect(player, &QMediaPlayer::durationChanged, this,&restaurant::on_durationChanged );

        //gestionli//
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

       //gestioncli//
       ui->tableView_client ->setModel(tmpC.afficher());
       ui->tableView_client ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

       //Affichage tab carte client
       ui->tableView_carte ->setModel(tmpCarte.afficher());
       ui->tableView_carte->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->stackedWidgetClient->setCurrentIndex(0);
     ui->comboBox_tri_Carte->addItem("Trier les cartes fidélités");
      ui->comboBox_tri_Carte->addItem("Nombre de points");
       ui->comboBox_tri_Carte->addItem("Date de creation");
       timer_1s = new QTimer(this);
       QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
       timer_1s->start(1000);



}

restaurant::~restaurant()
{
    delete ui;
}

void restaurant::refrech()
{

    ui->tabemploye->setModel(tmpemploye.afficher());
            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT ID FROM EMPLOYE");
            ui->idsup->setModel(model);
            ui->idmodifier->setModel(model);

            ui->tabequipement->setModel(tmpequipement.afficher());
            QSqlQueryModel * model1= new QSqlQueryModel();
            model1->setQuery("SELECT ID_EQUIPEMENT FROM Equipement");
            ui->ideqsup->setModel(model1);
            ui->ideqmodif->setModel(model1);

            QSqlQueryModel * model3= new QSqlQueryModel();
            model3->setQuery("SELECT id FROM ARCHIVE_EMPLOYE");
            ui->idsup_3->setModel(model3);
}


void restaurant:: showTime()
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
void restaurant::INFORMER(QLabel *label, QString message, int duration){
    label->setVisible(true);
    label->setText(message);
    QTimer::singleShot(duration, ui->labelmessage, &QLabel::hide);
    QTimer::singleShot(duration, ui->labelmessage2, &QLabel::hide);


}


void restaurant::on_ajouter_B_clicked()
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
void restaurant::on_ListDelete_B_clicked()
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
void restaurant::on_ConfrimEdit_B_clicked()
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

void restaurant::on_ListEdit_B_clicked()
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

void restaurant::on_ListEditME_B_clicked()
{
    QSqlQuery qry;
    QString id_string = QString::number(ui->idListME_CB->currentText().toInt());
    qry.prepare("SELECT * FROM menu where id=:id");
    qry.bindValue(0, id_string);
    if(qry.exec()) {
        while(qry.next()) {

            ui->nomME_LE_2->setCurrentText(qry.value(1).toString());
            ui->prixME_LE_2->setText(qry.value(2).toString());
              ui->descME_LE_2->setText(qry.value(3).toString());

        }
    }
    ui->tabWidget_2->setCurrentIndex(4);
}

void restaurant::on_ListDeleteME_B_clicked()
{
    Menu M;
    M.setId(ui->idListME_CB->currentText().toInt());
    //bool test=M.supprimer1(M.getId());
    if(M.supprimer1(M.getId())) {
        QMessageBox::information(nullptr, QObject::tr("Done"),
                    QObject::tr("menu supprimer.\n"
                                "cliquer sur ok pour quitter."), QMessageBox::Ok);
        ui->idListME_CB->setModel(M.listId1());
        ui->menu_tab->setModel(M.afficher1());
        ui->tabWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("nom"),
                    QObject::tr(" menu non supprimer.\n"
                                "cliquer sur ok pour quitter."), QMessageBox::Ok);
    }

}




void restaurant::on_ConfrimEditME_B_clicked()
{
    Menu M1 ;
    M1.setId(ui->idListME_CB->currentText().toInt());
    M1.setNom(ui->nomME_LE_2->currentText());
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

void restaurant::on_bouton_imprimer_clicked()
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
















void restaurant::on_exporter_2_clicked()
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
        QMessageBox::information(this, tr("fait"),
                                 QString(tr("%1 enregistrement exporter!")).arg(retVal)
                                 );
    }

}


















void restaurant::on_affichermenu_clicked()
{
     ui->menu_tab->setModel(M.afficher1()) ;
}

void restaurant::on_exporterM_clicked()
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

void restaurant::on_exporterXM_clicked()
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
                                 QString(tr("%1 enregistrement exporter !")).arg(retVal)
                                 );
    }

}



void restaurant::on_bouton_imprimer_3_clicked()
{
    ui->tabWidget_2->setCurrentIndex(5);
}




void restaurant::on_pushButton_5_clicked()
{
     ui->tabWidget_2->setCurrentIndex(3);
}

void restaurant::on_pushButton_6_clicked()
{
    ui->tabWidget_2->setCurrentIndex(1);
   restaurant::makePlot_type();


}

void restaurant::on_bouton_imprimer_4_clicked()
{
    ui->tabWidget_2->setCurrentIndex(0);
}

void restaurant::on_pushButton_clicked()
{
   ui->tabWidget_2->setCurrentIndex(1);
}

void restaurant::on_pushButton_2_clicked()
{
  ui->tabWidget_2->setCurrentIndex(0);
}



void restaurant::on_chercher_textChanged(const QString &arg1)
{
    QString by=ui->listechercher->currentText();
            ui->plat_tab->setModel(P.chercher(arg1,by));

}

void restaurant::on_trier_clicked()
{
    QString Tri = ui->listtrier->currentText();
            ui->plat_tab->setModel(P.Trier(Tri));
}





void restaurant::on_pushButton_8_clicked()
{
    ui->plat_tab->setModel(P.afficher()) ;
    INFORMER(ui->labelmessage,"LISTE PLAT CHARGEE   ",3000);
}



void restaurant::on_pushButton_9_clicked()
{

    QString msg;
    Menu menu;

        QString nom = ui->nomME_LE->currentText();



        QString prix = ui->prixME_LE->text();
         QString description = ui->descME_LE->text();

      Menu M( nom, description,prix);
      bool test = M.ajouter1();
      if (test)

      {
          msg="monsieur "+menu.getNom()+" , Nous sommes heureux de vous avoir en tant que nouveau menu a éte ajouter a notre restaurant  nous    ";
          Smtp* smtp = new Smtp("farah.hasnaoui22@gmail.com", "kenzafarah", "smtp.gmail.com", 465);
                       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


                    smtp->sendMail("farah.hasnaoui22@gmail.com","farah.hasnaoui22@gmail.com"  , "confirmation d'ajout",msg);

          ui->menu_tab->setModel(M.afficher1()) ;
          Notifications N;
           N.notifications_ajoutermenu();
          INFORMER(ui->labelmessage2," MENU AJOUTE AVEC SUCCES ",3000);

      }
      else

      {INFORMER(ui->labelmessage2,"MENU NON AJOUTE ",3000);
      }
}
void restaurant::browse()
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
void  restaurant::sendMail()
{
    Smtp* smtp = new Smtp("farah.hasnaoui22@gmail.com",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("farah.hasnaoui22@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("farah.hasnaoui22@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void  restaurant::mailSent(QString status)
{

    if(status == "Message envoyee")
        QMessageBox::warning( nullptr, tr( "client Qt Simple SMTP " ), tr( "Message envoyee!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void restaurant::on_chercher_2_textChanged(const QString &arg1)
{
    QString by=ui->listechercher_2->currentText();
            ui->menu_tab->setModel(M.chercher1(arg1,by));
}

void restaurant::on_trier_2_clicked()
{
    QString Tri = ui->listtrier_2->currentText();
            ui->menu_tab->setModel(M.Trier1(Tri));
}

void restaurant::on_pushButton_10_clicked()
{
    ui->menu_tab->setModel(M.afficher1()) ;
    INFORMER(ui->labelmessage2,"LISTE Menu CHARGEE   ",3000);
}

void restaurant::on_sliderprog_sliderMoved(int position)
{
player->setPosition(position);
}

void restaurant::on_slidervolume_sliderMoved(int position)
{
player->setVolume(position);
}

void restaurant::on_pushButton_18_clicked()
{
    //load file
    player->setMedia(QUrl("C:/Users/Home/Documents/gestionplats-menu/m.mp3"));
    player->play();
    qDebug()<< player->errorString();
}

void restaurant::on_pushButton_19_clicked()
{
    player->stop();
}

void restaurant::on_positionChanged(qint64 position)
{
    ui->sliderprog->setValue(position);
}

void restaurant::on_durationChanged(qint64 position)
{
ui->sliderprog->setMaximum(position);
}

void restaurant::on_stat_clicked()
{

   /********************* BEGIN : Donut->Nationalite *********************/
       QSqlQuery qry;
       qry.prepare("SELECT COUNT (*) FROM equipement where poste='caissier'");
       qry.exec();
       int Cs= 0;
       if (qry.next()) {
           Cs= qry.value(0).toInt();
       }
       QSqlQuery qery;
       qery.prepare("SELECT COUNT (*) FROM equipement where poste='chef de cuisine'");
       qery.exec();
       int Cc= 0;
       if (qery.next()) {
           Cc= qery.value(0).toInt();
       }
       QSqlQuery qury;
       qury.prepare("SELECT COUNT (*) FROM equipement where poste='employe'");
       qury.exec();
       int Ep= 0;
       if (qury.next()) {
           Ep= qury.value(0).toInt();
       }

       QPieSeries *series = new QPieSeries();
       series->append("Chef de Cuisine", Cc);
       series->append("Caissier", Cs);
       series->append("Employe", Ep);
       series->setHoleSize(0.5);
       series->setPieSize(0.8);

       QPieSlice *cc = series->slices().at(0);
       QPieSlice *cs = series->slices().at(1);
       QPieSlice *ep = series->slices().at(2);
       //QPieSlice *autres = series->slices().at(4);
       /*********************** Labels
       tn->setLabelVisible(true);
       fr->setLabelVisible(true);
       ag->setLabelVisible(true);
       lb->setLabelVisible(true);
       autres->setLabelVisible(true);
       ******************************/
       cs->setBrush(Qt::red);
       cc->setBrush(Qt::blue);
       ep->setBrush(Qt::green);

       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques");
       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignBottom);
       chart->setAnimationOptions(QChart::AllAnimations);

       QChartView *chartView = new QChartView(chart);
       chartView->setParent(ui->horizontalFrame);


       ui->tabWidget_2->setCurrentIndex(6);
      restaurant::makePlot_type();
}

void restaurant::on_pushButton_20_clicked()
{
      ui->tabWidget_2->setCurrentIndex(1);
}



void restaurant::on_pushButton_13_clicked()
{
    ui->tabWidget_2->setCurrentIndex(3);
}

void restaurant::on_pushButton_22_clicked()
{
      ui->tabWidget_2->setCurrentIndex(1);
}
QVector<double>restaurant::Statistique_type()
{
    QSqlQuery q;
    QVector<double> stat(2);
    stat[0]=0;
    stat[1]=0;

    q.prepare("SELECT type FROM plats WHERE type='special'");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT type FROM plats WHERE type='simple'");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }





    return stat;
}

void restaurant::makePlot_type()
{
    // prepare data:
    QVector<double> x3(2), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->CustomPlot->xAxis, ui->CustomPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3,restaurant::Statistique_type());
    bars1->setName("nombre du plats selon type");
    bars1->setPen(QPen(QColor(200, 40, 60).lighter(170)));

    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->CustomPlot->replot();


    // move bars above graphs and grid below bars:
    ui->CustomPlot->addLayer("abovemain", ui->CustomPlot->layer("main"), QCustomPlot::limAbove);
    ui->CustomPlot->addLayer("belowmain", ui->CustomPlot->layer("main"), QCustomPlot::limBelow);
    ui->CustomPlot->xAxis->grid()->setLayer("belowmain");
    ui->CustomPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"special"<<"simple";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->CustomPlot->xAxis->setTicker(textTicker);
    ui->CustomPlot->xAxis->setSubTicks(false);
    ui->CustomPlot->xAxis->setTickLength(0,4);
    ui->CustomPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->CustomPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->CustomPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->CustomPlot->xAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot->yAxis->setTickLabelColor(Qt::white);
    ui->CustomPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->CustomPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->CustomPlot->xAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot->yAxis->grid()->setSubGridVisible(true);
    ui->CustomPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->CustomPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->CustomPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->CustomPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->CustomPlot->axisRect()->setBackground(axisRectGradient);

    ui->CustomPlot->rescaleAxes();
    ui->CustomPlot->xAxis->setRange(0, 7);
    ui->CustomPlot->yAxis->setRange(0, 10);


}

void restaurant::on_pushButton_25_clicked()
{
   restaurant::makePlot_type();
}


void restaurant::on_tabWidget_currentChanged(int )
{
   { ui->tabemploye->setModel(tmpemploye.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM EMPLOYE");
    ui->idsup->setModel(model);
    ui->idmodifier->setModel(model);

    ui->tabequipement->setModel(tmpequipement.afficher());
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("SELECT ID_EQUIPEMENT FROM Equipement");
    ui->ideqsup->setModel(model1);
    ui->ideqmodif->setModel(model1);
    }

}










void restaurant::on_ajout_clicked()
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

void restaurant::on_sup_clicked()
{

    int id=ui->idsup->currentText().toInt();
    bool test=tmpemploye.supprimer(id);
    if(test){
        ui->tabemploye->setModel(tmpemploye.afficher());
        QMessageBox::information(nullptr,"suppression employe","employe supprimer avec succés");
        refrech();
    }
    else
            QMessageBox::warning(nullptr,"Error","employe non supprimer");

}








void restaurant::on_ajouteq_clicked()
{
    int id_equipement=ui->ideqajout->text().toInt();
        QString materiel=ui->matajout->currentText();
        QString poste=ui->postajout->currentText();
        int id_employee=ui->idempajout->text().toInt();
        Equipement tmpequipement(id_equipement,materiel,poste,id_employee);
        bool test=tmpequipement.ajouter();
        if(test){
            ui->tabequipement->setModel(tmpequipement.afficher());
            QMessageBox::information(nullptr,"Ajout equipement","equipement ajouté avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","equipement non ajouté");
}

void restaurant::on_supeq_clicked()
{
    int id_equipement=ui->ideqsup->currentText().toInt();
    bool test=tmpequipement.supprimer(id_equipement);
    if(test){
        ui->tabequipement->setModel(tmpequipement.afficher());
        QMessageBox::information(nullptr,"suppression equipement","equipement supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","equipement non supprimer");

}
void restaurant::on_modifier_clicked()
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


void restaurant::on_modifeq_clicked()
{
    int id_equipement=ui->ideqmodif->currentText().toInt();
    QString materiel=ui->matmodif->currentText();
    QString poste=ui->postmodif->currentText();
    int id_employee=ui->idempmodif->text().toInt();
    Equipement e(id_equipement,materiel,poste,id_employee);
    bool test=e.modifier(id_equipement);
    if(test){
        ui->tabequipement->setModel(tmpequipement.afficher());

        QMessageBox::information(nullptr,"modification equipement","equipement modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","equipement non modifie");
}

void restaurant::on_supprimer_currentChanged(int )
{
    ui->tabemploye->setModel(tmpemploye.afficher());
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT ID FROM EMPLOYE");
        ui->idsup->setModel(model);
        ui->idmodifier->setModel(model);

        ui->tabequipement->setModel(tmpequipement.afficher());
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("SELECT ID_EQUIPEMENT FROM Equipement");
        ui->ideqsup->setModel(model1);
        ui->ideqmodif->setModel(model1);
        QFile file("messenger.txt");
        if(!file.open(QIODevice::ReadOnly));
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
        file.close();
        QScrollBar *sb = ui->textBrowser->verticalScrollBar();
        sb->setValue(sb->maximum());

}

void restaurant::on_pushButton_3_clicked()
{

    QString msg= ui->messageline->text();
    ui->messageline->clear();
    QFile file("messenger.txt");
    file.close();
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream out(&file);
        out << "<User> "<< msg<<" - "<< QDateTime::currentDateTime().toString("dd/MM/yyyy h:mm ap") <<"\n";
        file.close();
    }
    if(!file.open(QIODevice::ReadOnly));
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    file.close();
    QScrollBar *sb = ui->textBrowser->verticalScrollBar();
    sb->setValue(sb->maximum());
}

void restaurant::on_Excel_clicked()
{
    Employe E;
           QSqlQueryModel * model=new QSqlQueryModel();
           model=E.Find_Employe();
           QString textData= "id ; nom ; prenom ; adresse ; telephone \n";
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

void restaurant::on_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabemploye->model()->rowCount();
                const int columnCount = ui->tabemploye->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>Employes LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ****LISTE DES Employes **** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabemploye->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabemploye->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabemploye->isColumnHidden(column)) {
                            QString data =ui->tabemploye->model()->data(ui->tabemploye->model()->index(row, column)).toString().simplified();
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



void restaurant::on_trieremplo_clicked()
{
    ui->tabemploye->setModel(tmpemploye.tri());
}

void restaurant::on_recherche_textEdited(const QString &arg1)
{
    Employe e;
    ui->tabemploye->setModel(e.rechercher(ui->recherche->text()));

}

void restaurant::on_chat_clicked()
{
    QString msg= ui->messageline->text();
        ui->messageline->clear();
        QFile file("messenger.txt");
        file.close();
        if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream out(&file);
            out << "<"+session.getnom()+" "+session.getprenom()+"> "<< msg<<" - "<< QDateTime::currentDateTime().toString("dd/MM/yyyy h:mm ap") <<"\n";
            file.close();
        }
        if(!file.open(QIODevice::ReadOnly));
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
        file.close();
        QScrollBar *sb = ui->textBrowser->verticalScrollBar();
        sb->setValue(sb->maximum());
}










void restaurant::on_chat_2_clicked()
{
     ui->supprimer->setCurrentIndex(2);
}

void restaurant::on_retourpageemploye_clicked()
{
    ui->supprimer->setCurrentIndex(0);
}







void restaurant::on_pushButton_28_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(1);
}





void restaurant::on_gestionplatmenu_clicked()
{
      ui->stackedWidget_2->setCurrentIndex(0);
}


//gestionpro//
void restaurant::on_pbajouter_clicked()
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

void restaurant::on_supp_clicked()
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






void restaurant::on_modifierprod_clicked()
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


void restaurant::on_tabWidgett_currentChanged(int index)
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






void restaurant::on_ajoutfrs_clicked()
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

void restaurant::on_frsmod_2_clicked()
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













void restaurant::on_tabWidget_4_currentChanged(int index)
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

void restaurant::on_QRcode_clicked()
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

void restaurant::on_frssupp_clicked()
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

void restaurant::on_statprix_clicked()
{
    ui->tabWidget_4->setCurrentIndex(3);
    Produits p;


    p.stat(ui->widget);

}

void restaurant::on_search_textEdited(const QString &arg1)
{
    Fournisseur f;
    ui->tabfournisseur->setModel(f.chercher(ui->search->text()));
}

void restaurant::on_trifourni_clicked()
{
    ui->tabfournisseur->setModel(tmpfournisseur.tri());

}

void restaurant::on_gestionfourni_clicked()
{
    ui->tabWidget_4->setCurrentIndex(1);

}

void restaurant::on_gestionprod_clicked()
{
    ui->tabWidget_4->setCurrentIndex(2);

}

void restaurant::on_retourfp_clicked()
{
    ui->tabWidget_4->setCurrentIndex(0);
}

void restaurant::on_retour2fp_clicked()
{
     ui->tabWidget_4->setCurrentIndex(0);
}

void restaurant::on_retour3fp_clicked()
{ui->tabWidget_4->setCurrentIndex(2);

}


void restaurant::on_gestionproduit_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(2);
}

void restaurant::on_pb_login_2_clicked()
{
    QString l = ui->le_login_2->text();
    QString p = ui->le_password_2->text();
    if(session.login(l, p)) {
        ui->supprimer->setCurrentIndex(0);

    }
}

void restaurant::on_notepad_clicked()
{
    notepad *ga;
      ga = new  notepad();
      ga->show();
}

void restaurant::on_pagegoogle_clicked()
{
    QString link="http://www.google.com";

    QDesktopServices::openUrl(QUrl(link));
}

void restaurant::on_statmateriel_clicked()
{
    QPieSeries *series = new QPieSeries();
       series->append("four",10);
       series->append("table",30);
       series->append("chaise",20);
       series->append("gaz ",20);
       series->append("friteuse ",40);
        series->append("pizzeria ",30);
       QPieSlice *slice= series->slices().at(1);
       slice->setExploded(true);
       slice->setLabelVisible(true);
       slice->setPen(QPen(Qt::darkGreen,2));
       slice->setBrush(Qt::green);
       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("statistiques");
       QChartView *chartview=new QChartView(chart);
       chartview->setParent(ui->horizontalFrame_2);
       ui->tabWidget_3->setCurrentIndex(2);
}

void restaurant::on_excelrym_clicked()
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

void restaurant::on_imprimerim_clicked()
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



void restaurant::on_pushButton_29_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(3);
}

void restaurant::on_contacteznous_clicked()
{
    Smtp* smtp = new Smtp("farah.hasnaoui22@gmail.com", "kenzafarah", "smtp.gmail.com", 465);
    smtp->sendMail("farah.hasnaoui22@gmail.com", "farah.hasnaoui22@gmail.com" , "Signalisation Problème" ,ui->plainTextEdit_probleme->toPlainText());
    ui->plainTextEdit_probleme->clear();
}



//mode//

void restaurant::on_radioButton_jour_toggled(bool)
{


    this->setStyleSheet("font: 8pt \"Pacifico\";");


    QList<QPushButton *> butts = this->findChildren<QPushButton *>();

    for (int i=0; i<butts.size();i++)
    {
        butts.at(i)->setStyleSheet("QPushButton { background-color: grey; }");
    }
    QList<QStackedWidget *> tabs = this->findChildren<QStackedWidget *>();

    for (int i=0; i<tabs.size();i++)
    {
        tabs.at(i)->setStyleSheet("QStackedWidget { background-color:  grey;}");
    }

}

void restaurant::on_radioButton_nuit_toggled(bool)
{



    this->setStyleSheet("font: 8pt \"Pacifico\";");


    QList<QPushButton *> butts = this->findChildren<QPushButton *>();

    for (int i=0; i<butts.size();i++)
    {
        butts.at(i)->setStyleSheet("QPushButton { background-color: blue; }");
    }
    QList<QStackedWidget *> tabs = this->findChildren<QStackedWidget *>();

    for (int i=0; i<tabs.size();i++)
    {
        tabs.at(i)->setStyleSheet("QStackedWidget { background-color:  black;}");
    }
}

//liv//




void restaurant::on_suppl_clicked()
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



void restaurant::on_gestionlv_currentChanged(int)
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





void restaurant::on_ajoutliv_2_clicked()
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


void restaurant::on_mod_clicked()
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

void restaurant::on_modv_clicked()
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

void restaurant::on_suppv_clicked()
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

void restaurant::on_ajoutv_clicked()
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





void restaurant::on_recherche_textEdited2(const QString &arg1)
{
    livraisons L;
    ui->tablivraison->setModel(L.rechercher(ui->recherche->text()));
}



void restaurant::on_triil_clicked()
{
   ui->tablivraison->setModel(tmplivraisons.trii());

}

void restaurant::on_pdfl_clicked()
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



void restaurant::on_trive_clicked()
{

    ui->tabvehicule->setModel(tmpv.tri());
}

void restaurant::on_gestionlivb_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(4);
}


//client//
void restaurant::on_pushButton_Carte_clicked()
{
    ui->groupBox_carte->setTitle("");
   ui->Numero->clear() ;
   ui->Id_utilisateur->clear() ;
    ui->date_creation->clear() ;
       ui->nb_points->clear() ;
    ui->stackedWidgetClient->setCurrentIndex(4);

}




void restaurant::on_annuler_client_clicked()
{

    ui->stackedWidgetClient->setCurrentIndex(1);
}



void restaurant::on_ajouter_client_clicked()
{


    ui->nom_client->clear();
    ui->age_client->clear();
    ui->adresse->clear();
    ui->prenom_client->clear();
    ui->id_client->clear();
    ui->stackedWidgetClient->setCurrentIndex(1);
}



void restaurant::on_re_7_3_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(0);

}

void restaurant::on_pushButton_Client_clicked()
{
client C;
ui->stackedWidgetClient->setCurrentIndex(1);

    ui->tableView_client->setModel(C.afficher());
    ui->tableView_client->resizeRowsToContents();
    ui->tableView_client->resizeColumnsToContents();
    ui->tableView_client->show();

}

void restaurant::on_re_7_5_clicked()
{

     ui->stackedWidgetClient->setCurrentIndex(0);
}

void restaurant::on_pushButton_Ajouter_clicked()
{
     ui->stackedWidgetClient->setCurrentIndex(2);
}

void restaurant::on_pushButton_Ajouter_5_clicked()
{
      ui->stackedWidgetClient->setCurrentIndex(4);
}





void restaurant::on_annuler_client_3_clicked()
{
      ui->stackedWidgetClient->setCurrentIndex(4);
}

void restaurant::on_ajouter_Carte_clicked()
{ carte_fidelite carte;
QString msg;
QSqlQuery qry;
qry.prepare("SELECT ADRESSE FROM CLIENT WHERE ID=:id");
qry.bindValue(":id",ui->Id_utilisateur_Ajout->text());
          if(!(ui->Numero_Ajout->text().isEmpty()||ui->Id_utilisateur_Ajout->text().isEmpty()||
                ui->nb_points_Ajout->text().isEmpty()))
           {


              carte.setID(ui->Id_utilisateur_Ajout->text());
                carte.setNumero(ui->Numero_Ajout->text());
                  carte.setDate_creation(ui->dateEdit_AjoutCarte->date().toString("dd/MM/yyyy"));
                  carte.setNb_points(ui->nb_points_Ajout->text());
              QMessageBox msgB;

              msgB.setText("La carte d'identifiant "+carte.getNumero()+" a bien été enregistrée ");
              msgB.exec();
              ui->Id_utilisateur_Ajout->clear();
                             ui->Numero_Ajout->clear();
                               ui->date_creation->clear();
                             ui->nb_points_Ajout->clear();
                               ui->stackedWidgetClient->setCurrentIndex(4);
msg="votre carte est bien enregistrée sous le numero "+carte.getNumero()+" vous pouver le recuperer de notre boutique apres15jours ";

          }
          else
              QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");

              //Ajout
carte.ajouter();
if(qry.exec()){
    while(qry.next())
            {
Smtp* smtp = new Smtp("farah.hasnaoui22@gmail.com", "kenzafarah", "smtp.gmail.com", 465);
                         connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


                         smtp->sendMail("farah.hasnaoui22@gmail.com", qry.value(0).toString() , "carte fidelitée",msg);
}
}
  ui->tableView_carte ->setModel(tmpCarte.afficher());
}



void restaurant::on_tableView_client_clicked(const QModelIndex &index)
{
    client C;
    QString ID=ui->tableView_client->model()->data(index).toString();

    QString  Nom, Prenom,Age,Adresse;
    C.afficher(&ID,&Nom,&Prenom,&Age,&Adresse);
  ui->id_client->setText(ID) ;
  ui->age_client->setText(Age) ;
  ui->prenom_client->setText(Prenom) ;
  ui->adresse->setText(Adresse) ;
    ui->nom_client->setText(Nom) ;
       ui->groupBox_client->setTitle(ID);
}

void restaurant::on_tableView_carte_clicked(const QModelIndex &index)
{
    carte_fidelite carte;

    QString numero=ui->tableView_carte->model()->data(index).toString();

    QString  ID_cl, date_creation, nb_points;
     carte.afficher(&ID_cl,&numero,&date_creation,&nb_points);
      ui->groupBox_carte->setTitle(numero);
     ui->Numero->setText(numero) ;
     ui->Id_utilisateur->setText(ID_cl);
      ui->date_creation->setText(date_creation);
         ui->nb_points->setText(nb_points);
}

void restaurant::on_pushButton_Ajouter_client_clicked()
{
     ui->stackedWidgetClient->setCurrentIndex(  3);
}

void restaurant::on_pushButton_Ajouter_Carte_clicked()
{
      ui->stackedWidgetClient->setCurrentIndex(6);
}

void restaurant::on_pushButton_supp_Carte_clicked()
{
    QString Numero;
   Numero= ui->Numero->text();
   bool test= tmpCarte.Supprimer(Numero);
   if (test==1 && !(ui->groupBox_carte->title().isEmpty()))

   {    ui->tableView_carte ->setModel(tmpCarte.afficher());
       QMessageBox::information(nullptr,QObject::tr("Supprimer une carte fidélité")
                              ,QObject::tr("La carte fidélité a été supprimée"));
        ui->groupBox_carte->setTitle("");
       ui->Numero->clear() ;
       ui->Id_utilisateur->clear() ;
        ui->date_creation->clear() ;
           ui->nb_points->clear() ;
   }

   else if (ui->groupBox_carte->title().isEmpty())
   {
       QMessageBox::critical(nullptr,QObject::tr("Supprimer une carte fidélité")
                                ,QObject::tr("Pas de carte fidélité à supprimer!"));
   }
}

void restaurant::on_Enregistrer_client_clicked()
{
    client C;
    bool test;

    if(!(ui->nom_client_Ajouter->text().isEmpty()||ui->prenom_client_Ajouter->text().isEmpty()||
          ui->adresse_Ajouter->text().isEmpty()|| ui->id_client_Ajouter->text().isEmpty()))
     {
       C.setNom(ui->nom_client_Ajouter->text());
       C.setAge(ui->spinBox_Age->text());
       C.setPrenom(ui->prenom_client_Ajouter->text());
       C.setAdresse(ui->adresse_Ajouter->text());
       C.setID(ui->id_client_Ajouter->text());

       test= C.ajouter();
       QMessageBox msgB;
       msgB.setText("Le client d'identifiant "+C.getID()+" a bien été enregistré ");
       msgB.exec();
   ui->nom_client_Ajouter->clear();
   ui->prenom_client_Ajouter->clear();
   ui->adresse_Ajouter->clear();
   ui->id_client_Ajouter->clear();
   ui->stackedWidgetClient->setCurrentIndex(1);
    }
    else
QMessageBox::critical(this,"Alerte","Il faut tout remplire ! ");
//Ajout

      ui->tableView_client->setModel(tmpC.afficher());
}
void restaurant::on_pushButton_supp_clicked()
{
    QString ID;
   ID= ui->id_client->text();
   bool test= tmpC.Supprimer(ID);
   if (test==1 && !(ui->groupBox_client->title().isEmpty()))

   {    ui->tableView_client->setModel(tmpC.afficher());
       QMessageBox::information(nullptr,QObject::tr("Supprimer un client")
                              ,QObject::tr("Le client a été supprimé"));

        ui->groupBox_client->setTitle("");
        ui->nom_client_Ajouter->clear();
        ui->prenom_client_Ajouter->clear();
        ui->adresse_Ajouter->clear();
        ui->id_client_Ajouter->clear();
           ui->nb_points->clear() ;
}
   else if (ui->groupBox_carte->title().isEmpty())
   {
       QMessageBox::critical(nullptr,QObject::tr("Supprimer un client")
                                ,QObject::tr("Pas de client à supprimer!"));
   }
}


void restaurant::on_pushButton_save_MAJ_Carte_clicked()
{
    carte_fidelite carte;


    QString  numero,ID_cl, date_creation, nb_points;
    numero=ui->Numero_maj->text();
    ID_cl=ui->Id_utilisateur_maj->text();

           nb_points=ui->nb_points_maj->text();
          date_creation =ui->date_creation_maj->text();

        bool test=carte.Modifier(ID_cl,numero,date_creation,nb_points);
        if  (test)
           {

       ui->tableView_carte ->setModel(tmpCarte.afficher());
            QMessageBox::information(nullptr,QObject::tr("Modifier une carte fidélité")
                                     ,QObject::tr("La carte fidélité a été modifiée"));

   ui->stackedWidgetClient->setCurrentIndex(4);
              }

}

void restaurant::on_Modifier_clicked()
{


        if (ui->groupBox_carte->title().isEmpty())
            {
                QMessageBox::critical(nullptr,QObject::tr("Modifier une carte fidélité")
                                         ,QObject::tr("Pas de carte fidélité à modifier!"));
            }
            else
            {
                ui->stackedWidgetClient->setCurrentIndex(5);
            ui->Numero_maj->setText(ui->Numero->text());

ui->Id_utilisateur_maj->setText( ui->Id_utilisateur->text());
             ui->Numero_maj->setDisabled(true);
              ui->date_creation_maj->setText( ui->date_creation->text());
                 ui->nb_points_maj->setText( ui->nb_points->text());
                 ui->groupBox_carte->setTitle("");
                ui->Numero->clear() ;
                ui->Id_utilisateur->clear() ;
                 ui->date_creation->clear() ;
                    ui->nb_points->clear() ;

            }

}

void restaurant::on_pushButton_save_MAJ_Client_clicked()
{
    client C;


    QString  ID,Nom, Prenom,Age,Adresse;

 ID= ui->id_client_MAJ->text() ;
qDebug()<<ID;
 Age= ui->age_client_MAJ->text() ;
 qDebug()<<Age;
 Prenom= ui->prenom_client_MAJ->text() ;
  Adresse=ui->adresse_MAJ->text() ;
   Nom= ui->nom_client_MAJ->text() ;
 bool test= C.Modifier(ID,Nom,Prenom,Age,Adresse);
 qDebug()<<test;
 if  (test)
    {

ui->tableView_client ->setModel(tmpC.afficher());
     QMessageBox::information(nullptr,QObject::tr("Modifier un client")
                              ,QObject::tr("Le client a été modifiée"));

ui->stackedWidgetClient->setCurrentIndex(1);
       }
}

void restaurant::on_pushButton_Modif_client_clicked()
{
    if (ui->groupBox_client->title().isEmpty())
        {
            QMessageBox::critical(nullptr,QObject::tr("Modifier un client")
                                     ,QObject::tr("Pas de carte client à modifier!"));
        }
        else
        {
            ui->stackedWidgetClient->setCurrentIndex(2);

ui->id_client_MAJ->setDisabled(true);

ui->nom_client_MAJ->setText( ui->nom_client->text());
 ui->prenom_client_MAJ->setText( ui->prenom_client->text());
  ui->adresse_MAJ->setText( ui->adresse->text());
  ui->id_client_MAJ->setText(ui->id_client->text());
  ui->age_client_MAJ->setText(ui->age_client->text());

             ui->groupBox_client->setTitle("");
             ui->nom_client->clear();
              ui->age_client->clear();
             ui->prenom_client->clear();
             ui->adresse->clear();
             ui->id_client->clear();

        }
}

void restaurant::on_pushButtonverspage4_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(4);

}

void restaurant::on_annuler_modif_ca_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(4);

}

void restaurant::on_pushButton_Ann_MAJ_client_clicked()
{
    ui->stackedWidgetClient->setCurrentIndex(1);

}


void restaurant::on_comboBox_tri_Carte_activated(int index)
{
    ui->tableView_carte->setModel(tmpCarte.tri(index));
   if(index==0)
         {
     ui->tableView_carte->setModel(tmpCarte.afficher());

    }
   if(index==1)
        {
  ui->tableView_carte->setModel(tmpCarte.afficher());
}

   if(index==2)
        {
  ui->tableView_carte->setModel(tmpCarte.afficher());
}
}

void restaurant::on_recherch_CF_textChanged(const QString &arg1)
{
    carte_fidelite cf;
    ui->tableView_carte->setModel(cf.rechercherCF(arg1));
}

void restaurant::on_recherche_cl_textChanged(const QString &arg1)
{
    client cl;
    ui->tableView_client->setModel(cl.rechercherCL(arg1));
}



void restaurant::on_gestionclient_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(5);
}

void restaurant::on_jeu_clicked()
{

    Widget *ga;
      ga = new  Widget();
      ga->show();
}

//commande
void restaurant::UpdateTime()
{
    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->lbl_time_2->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->lbl_time_3->setText(QTime::currentTime().toString("hh:mm:ss"));


}
void restaurant::on_AddCommande_clicked()
{
    int idp=ui->iddddddddd->currentText().toInt();


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
void restaurant::on_SupprimerCommande_clicked()
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


void restaurant::on_pushButton_4_clicked()
{

        QMessageBox msg;
QItemSelectionModel *select = ui->Tab->selectionModel();
    QString idrow=select->selectedRows().at(0).data().toString();
        msg.setText(idrow);
        msg.exec();
}



void restaurant::on_pushButton_midifier_clicked()
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
void restaurant::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    showEventHelper();
}

void restaurant::RefreshTables(){
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
                    if (!select1.exec("select * from PLATS")) {
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
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("SELECT ID FROM employe");
    ui->iddddddddd->setModel(model1);
    /*******************************************/

    QTableView * view = new QTableView();
    view->verticalHeader()->hide();

}
void restaurant::showEventHelper()
{
    ui->iddddddddd->setValidator( new QIntValidator(0, 1000, this) );
    ui->lineEdit_prix_supp->setValidator( new QIntValidator(0, 100000, this) );
    ui->lineEdit_prix_sup->setValidator( new QIntValidator(0, 100000, this) );
    ui->qtyplat->setValidator( new QIntValidator(0, 1000000, this) );
    ui->lineEdit_Idemploye_2->setValidator( new QIntValidator(0, 1000, this) );
    ui->lineEdit_QTY->setValidator( new QIntValidator(0, 100000, this) );
    ui->lineEdit_QTY_2->setValidator( new QIntValidator(0, 100000, this) );
    ui->qtysupp->setValidator( new QIntValidator(0, 100000, this) );

   this->RefreshTables();
}

void restaurant::on_getid_clicked()
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

void restaurant::on_UpdateQuantity_clicked()
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

void restaurant::on_ADD_supp_clicked()
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

void restaurant::on_Delete_sup_clicked()
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

void restaurant::on_Modifier_Nom_sup_clicked()
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




void restaurant::on_ADD_supp_4_clicked()
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

void restaurant::on_UpdateQuantity_2_clicked()
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


void restaurant::on_serchsup_textEdited(const QString &arg1)
{

    ui->Tab3_2->setModel(t.chercher(ui->serchsup->text()));
}





void restaurant::on_serchcom_textEdited(const QString &arg1)
{
    ui->Tab->setModel(x.chercherCom(ui->serchcom->text()));
}


void restaurant::on_RecuCommande_clicked()
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
    query.prepare("select c.*, p.nom, p.prix, cp.qty, s.nom, s.prix, sc.qty from Commandes c, PLATS p, CommandePlat cp,supplement s,suppcom sc where cp.numc = c.numc and cp.id_plat = p.id and sc.numc = c.numc and sc.ids= s.ids and cp.numc = :numc and sc.numc = :numc");
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





void restaurant::on_gestioncommande_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
}

void restaurant::on_modifieaupanier_clicked()
{
    int id_Pr = ui->list_supp->currentText().toInt();
    int id; QString nom_produit,categorie;  float prix;
    QSqlQuery query;
    query.prepare("SELECT * from produits where id = :id");
    query.bindValue(":id" , id_Pr);
    if (query.exec())
    {
        while (query.next())
        {
            id = query.value(0).toInt();
            nom_produit = query.value(1).toString();
            categorie = query.value(2).toString();
            prix = query.value(3).toFloat();
        }
    }
    Panier panier(id, nom_produit, categorie, prix);
    if(panier.ajouter()) {
        // ken t7eb tamel alerte nena wala faza (ajout succes lel panier)
        QMessageBox::critical(nullptr, QObject::tr("nom"),
                    QObject::tr("Ajout au panier succes.\n"
                           "cliquer sur ok pour quitter."), QMessageBox::Ok);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("nom"),
                    QObject::tr("Ajout au panier Echue.\n"
                                "cliquer sur ok pour quitter."), QMessageBox::Ok);
    }
}

void restaurant::on_modifieaupanier_2_clicked()
{
    ui->tabpanier->setModel(panier.afficher());
    int p = panier.prixT();
    QString p_string = QString::number(p);
    ui->PrixTotale->setText(p_string);
    ui->tabWidget_4->setCurrentIndex(4);
}

void restaurant::on_modifieaupanier_3_clicked()
{
    panier.clear();
    ui->PrixTotale->setText("");
    ui->tabpanier->setModel(panier.afficher());
    ui->tabWidget_4->setCurrentIndex(2);
}

void restaurant::update_label()
{
    data=A.read_from_arduino();

    if (data!="#")
    {

        cin_recu+=data;

        if (data!="\r")//  || data!="\n" || data!="x")
        {
            tmp_recue+=data;
            qDebug() << data;
            ui->lcdNumber->display(data.toInt());
            ui->lineEdit_tmp->setText(tmp_recue);
            qDebug() << tmp_recue;

            QString test=ui->lineEdit_tmp->text();
            if (test.length()>5)
                tmp_recue="";
//            if (ui->lineEdit_tmp->text().toStdString().find("23") && tmp_verif==false)
//            {
//                QMessageBox::information(nullptr, QObject::tr("Notification"),
//                                         QObject::tr("TROP CHAUD\n"), QMessageBox::Ok);
//                tmp_verif=true;
//            }



        }




    }





}

void restaurant::on_pb_login_3_clicked()
{
    QString username = ui->le_login_2->text();
        if( username != "" ) {
            Employe e__;
            if(e__.oublieMDP(username)) {
                QMessageBox::information(nullptr, QObject::tr("MDP Oublie"),
                                      QObject::tr("Check Your Mail !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else {
                QMessageBox::critical(nullptr, QObject::tr("MDP Oublie"),
                                      QObject::tr("Check Username !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
            }

        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("MDP Oublie"),
                                  QObject::tr("Check Username !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void restaurant::on_sup_3_clicked()
{
    int id=ui->idsup_3->currentText().toInt();
        bool test=tmpemploye.restoration(id);
        if(test){
            ui->tabemploye->setModel(tmpemploye.afficher());
            QMessageBox::information(nullptr,"restauration employe","employe restaurer avec succés");
            refrech();
        }
        else
                QMessageBox::warning(nullptr,"Error","employe non restaurer");
}

void restaurant::on_chat_3_clicked()
{
    ui->tabemploye->setModel(tmpemploye.archive());
}

void restaurant::on_chat_4_clicked()
{
    ui->supprimer->setCurrentIndex(4);
    tmpemploye.showHistorique(ui->historiqueEmploye);

}

void restaurant::on_pushButton_7_clicked()
{
    ui->supprimer->setCurrentIndex(0);

}

void restaurant::on_chat_5_clicked()
{

}

void restaurant::on_pushButton_11_clicked()
{

}

void restaurant::on_imprimerim_2_clicked()
{
   ui->tabWidget_4->setCurrentIndex(5);
   tmpfournisseur.showHistorique(ui->fourHistorique);
}

void restaurant::on_pushButton_12_clicked()
{
    ui->tabWidget_4->setCurrentIndex(1);

}

void restaurant::on_QRcodecom_clicked()
{
    QMessageBox msg;
    QItemSelectionModel *select = ui->Tab->selectionModel();
    if (!select->hasSelection()){
         msg.setText("Please select something");

         msg.setIcon(msg.Critical);
         msg.exec();
         return;
    }
    QString idd=select->selectedRows().at(0).data().toString();

                int id= idd.toInt();
                QSqlQuery qry;
                qry.prepare("select * from commandes where numc=:numc");
                qry.bindValue(":numc",id);
                qry.exec();
                QString idemploye,datec,prixtot,ids;
                while(qry.next()){
                    idemploye=qry.value(1).toString();
                    datec=qry.value(2).toString();
                    prixtot=qry.value(3).toString();
                }
                ids=QString::number(id);
                ids="ID Commande: "+ids+" ID Employe: "+idemploye+" Date: "+datec+" Prix Totale: "+prixtot;
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
                ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));
}

void restaurant::on_ClientDuMoisBtn_clicked()
{
    QString cmd = "Select e.Nom, e.Prenom from Commandes c, Employe e  where e.Id = c.Idemploye order by c.prixtot DESC;";
    QSqlQuery qry;
    qry.prepare(cmd);
    qry.exec();
    if (qry.next()) {
        QString name = qry.value(0).toString();
        QString lastname = qry.value(1).toString();
        QString fullName = QString("%1 %2").arg(name).arg(lastname);
        QMessageBox msg;
        msg.setText(QString("Le client du mois est %1").arg(fullName));
        msg.exec();

    }
}

void restaurant::on_exit_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Home/Documents/Restaurant/bon travail et aurevoir.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(2);
        QVideoWidget * VW =new QVideoWidget ;
                  player->setVideoOutput(VW);
                  player->setMedia(QUrl::fromLocalFile("C:/Users/Home/Documents/Restaurant/thank.mpg"));
                  VW->setGeometry(350,120,700,500);
                  VW->show();
                  player->setVolume(10);
                  player->play();
                  qDebug() <<player->state();
                  QThread::sleep(5);
                  VW->close();
                  close();
}
