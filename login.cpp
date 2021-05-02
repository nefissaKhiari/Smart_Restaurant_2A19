
#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QThread>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_connect_clicked()
{

        QString username = ui->user->text();
         QString password = ui->mdp->text();
         if(username == "farah" && password =="10" || username =="ghofrane" && password=="20" || username == "rym" && password =="30" || username == "achref" && password =="40" || username == "seif" && password =="50" || username == "souhail" && password =="60")
         {
            /* QMediaPlayer* player;
             player= new QMediaPlayer;
                          player->setMedia(QUrl::fromLocalFile("C:/Users/Mehdi AZZAZ/Documents/projt_Dhouse/connexion.mp3"));
                              player->play();
                              qDebug()<<player->errorString();
                              QThread::sleep(1);
                           qDebug() <<"login etablie";*/
                         this->hide();
                          MainWindow *newmain=new MainWindow();
                          newmain->show();
                      }
         else
                  {
                      /*QMediaPlayer* player;
                      player= new QMediaPlayer;
                      player->setMedia(QUrl::fromLocalFile("C:/Users/user/Desktop/projet c++/QT/projet_finallll/failed.mp3"));
                          player->play();
                          qDebug()<<player->errorString();
                          QThread::sleep(1);*/
                        QMessageBox::warning(this,"LOGIN","CONNECTION FAILED");

                  }
         }
//
         void login::on_quitter_clicked()
         {

             close();
         }


