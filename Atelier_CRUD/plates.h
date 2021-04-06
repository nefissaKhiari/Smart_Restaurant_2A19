#ifndef PLATES_H
#define PLATES_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

class plates
{
    int prix;
    QString nom;

public:
    int IDp;
    plates(){}
    plates( int IDp , QString nomp, int prix);
    plates(   QString nomp, int prix);



    QString getNom(){return nom;}
    int getPrix(){return prix;}
    int getIDp(){return IDp;}




    void setIDp(int IDp){this->IDp=IDp;}
    void setNom(QString nom){this->nom=nom;}
    void setPrix(int prix){this->prix=prix;}


    bool ajouter();
    bool SupprimerPlat(int);
    QSqlQueryModel* AfficherIDPlat();
    QSqlQueryModel* AfficherPlat();
    bool ModifierPlat(int IDp);
};
#endif // PLATES_H
