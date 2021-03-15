#ifndef PLAT_H
#define PLAT_H

#include <QString>
#include <QSqlQueryModel>

class Plat
{
private:
    int id;
    QString nom,ingredient, categorie;
    int prix;

public:
     Plat();
     Plat(int,QString,QString, QString,int);
    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);
    QString getIngredient();
    void setIngredient(QString);
    QString getCategorie();
    void setCategorie(QString);
    int getPrix();
    void setPrix(int);
    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherById(int);
    QSqlQueryModel* listId();
};

#endif // PLAT_H
