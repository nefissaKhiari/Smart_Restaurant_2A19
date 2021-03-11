#include "livraisons.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>

livraisons::livraisons()
{
ID=0;
DATE_L =0 ;
ID_LIVREUR=0;

}

livraisons::livraisons(int ID  , int DATE_L, int ID_LIVREUR )
{this->ID=ID;
    this->DATE_L=DATE_L;
    this->ID_LIVREUR=ID_LIVREUR;
    }
int livraisons::getID(){return ID;}
int livraisons::getDATE_L(){return DATE_L;}
int livraisons::getID_LIVREUR() {return ID_LIVREUR  ;}

void livraisons::setID(int ID) {this->ID=ID;}
void livraisons::setDATE_L(int DATE_l){this->DATE_L;}
void livraisons::setID_LIVREUR(int ID_LIVREUR ){this->ID_LIVREUR;}

bool livraisons::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO livraisons (ID,DATE_L,ID_LIVREUR) VALUES (:ID,:DATE_L,:ID_LIVREUR)");
    query.bindValue(":ID",ID);
    query.bindValue(":DATE_L",DATE_L);
    query.bindValue(":ID_LIVREUR",ID_LIVREUR);

    return query.exec();
}
bool livraisons::supprimer(QString ID )
{
    QSqlQuery query;
    query.prepare("delete from livraisons where ID = :ID") ;

    query.bindValue(":ID",ID);

    return query.exec();
}
QSqlQueryModel* livraisons::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM livraisons");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id livreur"));

    return model;
}

bool livraisons::modifier(int ID)
{
    QSqlQuery query;
    query.prepare("UPDATE livraisons SET ID= :ID,DATE_L = :DATE_L,ID_LIVREUR = :ID_LIVREUR ");
    query.bindValue(":ID",ID);
    query.bindValue(":DATE_L",DATE_L);
    query.bindValue(":ID_LIVREUR",ID_LIVREUR);

    return    query.exec();
}

