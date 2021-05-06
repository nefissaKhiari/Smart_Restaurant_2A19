#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QThread>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include "login.h"
#include <QApplication>


 int main(int argc, char *argv[])
{
     QApplication a(argc, argv);

       QMediaPlayer * player = new QMediaPlayer;
           QVideoWidget * VW =new QVideoWidget ;
           player->setVideoOutput(VW);
           player->setMedia(QUrl::fromLocalFile("C:/Users/Ghofrane/Desktop/Atelier_Connexion/aa.mpg"));
           VW->setGeometry(320,120,700,500);
           VW->show();
           player->play();
           qDebug() <<player->state();
           QThread::sleep(9);
           VW->close();

        player= new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/Ghofrane/Desktop/Atelier_Connexion/bienvenu.mp3"));
           player->play();
          qDebug()<<player->errorString();

          QMediaPlaylist *playlist = new QMediaPlaylist();
                   playlist->addMedia(QUrl("C:/Users/Ghofrane/Desktop/Atelier_Connexion/la.mp3"));
                   playlist->setPlaybackMode(QMediaPlaylist::Loop);
                    QMediaPlayer *music = new QMediaPlayer();
                 music->setPlaylist(playlist);
                 music->setVolume(0);
                 music->play();

    Connection c;

    bool test=c.createconnect();
    login w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}


