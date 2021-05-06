#include "restaurant.h"
#include "ui_restaurant.h"
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
#include "qcustomplot.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>
#include <QPieSeries>
#include <QPieSlice>


#include<excel.h>



restaurant::restaurant(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::restaurant)
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
    connect(player, &QMediaPlayer::positionChanged, this,&restaurant::on_positionChanged );
        connect(player, &QMediaPlayer::durationChanged, this,&restaurant::on_durationChanged );


}

restaurant::~restaurant()
{
    delete ui;
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

            ui->nomME_LE_2->setText(qry.value(1).toString());
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


















void restaurant::on_pushButton_3_clicked()
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
void   restaurant::sendMail()
{
    Smtp* smtp = new Smtp("farah.hasnaoui@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("farah.hasnaoui@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("farah.hasnaoui@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   restaurant::mailSent(QString status)
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
       qry.prepare("SELECT COUNT (*) FROM employe where nom='caissier'");
       qry.exec();
       int Cs= 0;
       if (qry.next()) {
           Cs= qry.value(0).toInt();
       }
       QSqlQuery qery;
       qery.prepare("SELECT COUNT (*) FROM employe where nom='chef de cuisine'");
       qery.exec();
       int Cc= 0;
       if (qery.next()) {
           Cc= qery.value(0).toInt();
       }
       QSqlQuery qury;
       qury.prepare("SELECT COUNT (*) FROM employe where nom='employe'");
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
       /********************* END : Donut->Nationalite *********************/

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
QVector<double> restaurant::Statistique_type()
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
    bars1->setData(x3, restaurant::Statistique_type());
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
    labels<<"simple"<<"special";
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
