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
    int idemploye,qty;
   public:

     Commande(){}
     Commande( int );

     QString idcommande;


     int getIdemploye(){return idemploye;}
     int getqty(){return qty;}
     void setqty(int qty){this->qty=qty;}
     void setIdemploye(int idemploye){this->idemploye=idemploye;}


     bool ajouterPlat(int platid, int qty);
     bool ajouter();
     bool SupprimerCommande(int);
     QSqlQueryModel* AfficherCommande();
     QSqlQueryModel*AfficherPlat();
    QSqlQueryModel*chercherCom(QString);
     bool modifierEmployer(int);
     bool modifierQTY(int,int,int);

};

#endif // COMMANDE_H
