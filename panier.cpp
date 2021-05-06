#include "panier.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>

Panier::Panier(int id  ,QString nom_produit,QString categorie,double prix)
{this->id=id;
    this->nom_produit=nom_produit;
    this->categorie=categorie;
    this->prix=prix;}

bool Panier::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO panier (id,nom_produit,categorie,prix) VALUES (:id,:nom_produit,:categorie,:prix)");
    query.bindValue(":id",id);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    return query.exec();
}

QSqlQueryModel* Panier::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM panier");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom produits"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool Panier::clear() {
    QSqlQuery query;
    query.prepare("delete from panier");
    return query.exec();
}

float Panier::prixT() {
    QSqlQuery qry;
    qry.prepare("SELECT SUM(prix) FROM panier");
    qry.exec();
    int p= 0;
    if (qry.next()) {
        p= qry.value(0).toInt();
    }
    return p;
}
