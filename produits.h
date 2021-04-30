#ifndef PRODUITS_H
#define PRODUITS_H

#include <QString>
#include <QSqlQueryModel>
#include "qcustomplot.h"
class Produits
{
public:
    Produits();
    Produits(int ,QString,QString,double);
    int getid();
    QString getnom_produit();
    QString getcategorie();
    double getprix();
    void setid(int);
    void setnom(QString);
    void setcategorie(QString);
    void setprix(double);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier(int id);
    void stat(QCustomPlot *customPlot);
private:
    int id;
    QString nom_produit , categorie ;
    double prix;

};

#endif // PRODUITS_H
