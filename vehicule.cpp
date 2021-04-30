#include "vehicule.h"

#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Vehicule::Vehicule()
{
    id_vehicule=0;   modele ="";   etat="";
}

Vehicule::Vehicule( int id_vehicule,QString modele,QString etat) {
      this->id_vehicule=id_vehicule;  this->modele=modele;  this->etat=etat;

}

int Vehicule::getId_vehicule(){return id_vehicule;}
void Vehicule:: setId_vehicule(int id_vehicule){
    this->id_vehicule=id_vehicule;
}
QString Vehicule::getModele(){return modele;}
void Vehicule:: setModele(QString modele){
    this->modele=modele;
}
QString Vehicule::getEtat() {return etat  ;}
void Vehicule:: setEtat(QString etat){
    this->etat=etat;
}

bool Vehicule::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO vehicule (ID,MODELE,ETAT) VALUES (:ID,:MODELE,:ETAT)");
    query.bindValue(":ID",id_vehicule);
    query.bindValue(":MODELE",modele);
    query.bindValue(":ETAT",etat);
    return query.exec();
}

bool Vehicule::supprimer1(QString id_vehicule )
{
    QSqlQuery query;
    query.prepare("delete from vehicule where ID = :ID") ;

    query.bindValue(":ID",id_vehicule);

    return query.exec();
}
QSqlQueryModel* Vehicule::afficher1()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM Vehicule");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));

    return model;
}

bool Vehicule::modifier1(int id_vehicule)
{
    QSqlQuery query;
    query.prepare("UPDATE vehicule SET ID= :ID ,modele= :modele,etat = :etat WHERE ID=:ID ");
    query.bindValue(":ID",id_vehicule);
    query.bindValue(":modele",modele);
    query.bindValue(":etat",etat);

    return    query.exec();
}
QSqlQueryModel* Vehicule::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM vehicule ORDER BY ID   ");
                    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
                    model->setHeaderData(1, Qt::Horizontal, QObject::tr("modele"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    return model;
}


