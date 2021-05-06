#ifndef PANIER_H
#define PANIER_H
#include <QString>
#include <QSqlQueryModel>

class Panier
{

private:
    int id;
    QString nom_produit , categorie ;
    double prix;
public:
    Panier(){};
    Panier(int ,QString,QString,double);
    bool ajouter();
    bool clear();
    float prixT();
    QSqlQueryModel* afficher();
};

#endif // PANIER_H
