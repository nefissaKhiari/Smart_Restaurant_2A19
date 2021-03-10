#include "produits.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
Produits::Produits()
{
id=0;
nom_produit="";
categorie="";
prix=0;
}

Produits::Produits(int id  ,QString nom_produit,QString categorie,double prix)
{this->id=id;
    this->nom_produit=nom_produit;
    this->categorie=categorie;
    this->prix=prix;}
int Produits::getid(){return id;}
QString Produits:: getnom_produit(){return nom_produit;}
QString Produits::getcategorie() {return categorie;}
double Produits::getprix(){return prix;}
void Produits::setid(int id) {this->id=id;}
void Produits::setnom(QString nom_produit){this->nom_produit;}
void Produits::setcategorie(QString categorie){this->categorie;}
void Produits::setprix(double prix){this->prix;}
bool Produits::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO produits (id,nom_produit,categorie,prix) VALUES (:id,:nom_produit,:categorie,:prix)");
    query.bindValue(":id",id);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    return query.exec();
}
bool Produits::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from produits where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* Produits::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM PRODUITS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom produits"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("categorie"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool Produits::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE produits SET id= :id,nom_produit = :nom_produit,categorie = :categorie,prix = :prix  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    return    query.exec();
}
