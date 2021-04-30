#include "livraisons.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>

livraisons::livraisons()
{
ID=0;

ID_LIVREUR=0;
ID_V=0;
}

livraisons::livraisons(int ID  , int ID_LIVREUR, int ID_V )
{this->ID=ID;

    this->ID_LIVREUR=ID_LIVREUR;
    this->ID_V=ID_V;
    }
int livraisons::getID(){return ID;}

int livraisons::getID_LIVREUR() {return ID_LIVREUR  ;}
int livraisons::getID_V() {return ID_V  ;}

void livraisons::setID(int ID) {this->ID=ID;}

void livraisons::setID_LIVREUR(int ID_LIVREUR ){this->ID_LIVREUR;}
void livraisons::setID_V(int ID_V ){this->ID_V;}

bool livraisons::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO livraisons (ID,ID_LIVREUR, ID_V) VALUES (:ID,:ID_LIVREUR,:ID_V) ");
    query.bindValue(":ID",ID);

    query.bindValue(":ID_LIVREUR",ID_LIVREUR);
       query.bindValue(":ID_V",ID_V);
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
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id livreur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("id v"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));


    return model;
}

bool livraisons::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE livraisons SET ID= :ID,ID_LIVREUR = :ID_LIVREUR, ID_V=:ID_V WHERE ID=:ID");
    query.bindValue(":ID",ID);
       query.bindValue(":ID_LIVREUR",ID_LIVREUR);
    query.bindValue(":ID_V",ID_V);

    return    query.exec();
}



QSqlQueryModel * livraisons::rechercher(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from livraisons where ID like '%"+search+"%'  or  ID_LIVREUR like '%"+search+"%'";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel* livraisons::trii()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM livraisons ORDER BY DATEC");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id livraison"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id livreur"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("id v"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("date "));

    return model;
}

