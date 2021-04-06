/*#ifndef PLATS_H
#define PLATS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

class plats
{
    int prix;
    QString nom;
    int IDp;
public:
    plats(){}
    plats(QString nomp, int prix);



    QString getNom(){return nom;}
    int getPrix(){return prix;}
    int getIDp(){return IDp;}




    void setIDp(int IDp){this->IDp=IDp;}
    void setNom(QString Nom){this->nom=nom;}
    void setPrix(int prix){this->prix=prix;}


    bool ajouter();
    bool SupprimerPlat(int);
    QSqlQueryModel* AfficherPlat();
};

#endif // PLATS_H
*/
