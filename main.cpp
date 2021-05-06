#include "restaurant.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QTranslator>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);






    Connection c;
    bool test=c.createconnect();
    QTranslator t;
      QTranslator guiTranslator;
     QStringList languages;
     languages <<"French"<<"English";
     QString lang=QInputDialog::getItem(NULL,"Select Language","Language",languages);
     if (lang=="English")
 {     t.load(":/tr/english.qm");
         a.installTranslator(&t);

     }
     /*if (lang !="french"){
       a.installTranslator(&t);
       a.installTranslator(&guiTranslator);
     }*/
     QMediaPlayer * player = new QMediaPlayer;
         QVideoWidget * VW =new QVideoWidget ;
         player->setVideoOutput(VW);
         player->setMedia(QUrl::fromLocalFile("C:/Users/Home/Documents/Restaurant/aa.mpg"));
         VW->setGeometry(320,120,700,500);
         VW->show();
         player->play();
         qDebug() <<player->state();
         QThread::sleep(9);
         VW->close();

      player= new QMediaPlayer;
      player->setMedia(QUrl::fromLocalFile("C:/Users/Home/Documents/Restaurant/bienvenu.mp3"));
         player->play();
        qDebug()<<player->errorString();



    login w;

    if(test){
        w.show();
        QMessageBox::information(nullptr, QObject::tr("base de données ouvert "),
                    QObject::tr("connexion réussir.\n"
                                "cliquer annuler pour quitter."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connexion non réussi.\n"
                                "cliquer annuler pour quitter."), QMessageBox::Cancel);
    }
    return a.exec();
}
