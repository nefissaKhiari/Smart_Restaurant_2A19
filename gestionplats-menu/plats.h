#ifndef PLATS_H
#define PLATS_H
#include <QString>
#include <QSqlQueryModel>

class Plats
{

private:
    int id;
    QString nom, ingredient,categorie,prix;

public:
    Plats();
   Plats( QString, QString,QString,QString);
    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);
    QString getIngredient();
    void setIngredient(QString);
    QString getCategorie();
    void setCategorie(QString);
    QString getPrix();
    void setPrix(QString);
    bool ajouter();
    bool supprimer(int);
    bool modifier();
QSqlQueryModel * afficherRechId(int);
    QSqlQueryModel * afficherTrinom();
    QSqlQueryModel * afficherTriingredient();
    QSqlQueryModel * afficherTricategorie();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherById(int);
    QSqlQueryModel* listId();
    QSqlQueryModel * chercherplat(QString  nom);
    QSqlQueryModel * chercherplat1(QString  ingredient);
    QSqlQueryModel * chercherplat2(QString  categorie);
    QSqlQueryModel * chercherplat3(QString  prix);
};


#endif // PLATS_H
