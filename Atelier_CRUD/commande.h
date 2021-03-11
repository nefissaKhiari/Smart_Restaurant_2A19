#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

class Commande
{
    int num, idemploye;
    QString date;
public:

     Commande(){}
     Commande(int num, QString date, int idemploye);


     int getNum(){return num;}
     QString getDate(){return date;}
     int getIdemploye(){return idemploye;}


     void setNum(int num){this->num=num;}
     void setDate(QString date){this->date=date;}
     void setIdemploye(int idemploye){this->idemploye=idemploye;}



     bool ajouter();
     bool SupprimerCommande(int);
     QSqlQueryModel* AfficherCommande();

};

#endif // COMMANDE_H
