#include "plats.h"
#include <QSqlQuery>

#include <QDebug>
#include <QObject>
#include <QPrinter>
#include<QPrintDialog>
#include<QtPrintSupport/QPrintDialog>
Plats::Plats()
{
    id=0;    nom="";    ingredient="" ,categorie="",prix="";
}

Plats::Plats( QString nom, QString ingredient,QString categorie,QString prix) {
        this->nom=nom;    this->ingredient=ingredient; this->categorie=categorie ; this->prix=prix;
}

int Plats::getId() {
    return id;
}

void Plats::setId(int id) {
    this->id=id;
}

QString Plats::getNom() {
    return nom;
}

void Plats::setNom(QString nom) {
    this->nom=nom;
}

QString Plats::getIngredient() {
    return  ingredient;
}

void Plats::setIngredient(QString ingredient) {
    this->ingredient=ingredient;
}
QString Plats::getCategorie() {
    return  categorie;
}

void Plats::setCategorie(QString categorie) {
    this->categorie=categorie;
}
QString Plats::getPrix() {
    return prix;
}

void Plats::setPrix(QString prix) {
    this->prix=prix;
}

bool Plats::ajouter() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("INSERT INTO plats ( nom, ingredient , categorie,prix)" "VALUES ( :nom, :ingredient,:categorie,:prix)");

    query.bindValue(0, nom);
    query.bindValue(1, ingredient);
     query.bindValue(2, categorie);
      query.bindValue(3, prix);
    return query.exec();
}
QSqlQueryModel * Plats::chercherplat2(QString categorie)
 {
    QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT * FROM plats WHERE categorie='"+categorie+"' ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ingredient"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

            return model ;


 }
QSqlQueryModel *Plats:: chercherplat(QString  nom)


    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM plats WHERE nom='"+nom+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ingredient"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
        return model ;
    }



QSqlQueryModel * Plats::chercherplat1(QString ingredient)
 {
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM plats WHERE ingredient='"+ingredient+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ingredient"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    return model ;

}
QSqlQueryModel * Plats::chercherplat3(QString prix)
 {
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM plats WHERE prix='"+prix+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ingredient"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    return model ;

}

QSqlQueryModel* Plats::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plats");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ingredient"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Categorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    return model;
}



QSqlQueryModel* Plats::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM plats");
    return model;
}

bool Plats::supprimer(int id) {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("delete from plats where id=:id");
    query.bindValue(0, id);
    return query.exec();
}

bool Plats::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE plats set nom=:nom, ingredient=:ingredient , categorie=:categorie, prix=:prix where id=:id");
    query.bindValue(4, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, ingredient);
    query.bindValue(2, categorie);
    query.bindValue(3, prix);
    return query.exec();


}

QSqlQueryModel*Plats::afficherById(int id) {
    QSqlQuery query;
    QString id_string = QString::number(id);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plats where id=:id");
    query.bindValue(0, id_string);
    return model;
}






QSqlQueryModel * Plats::afficherTrinom(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plats ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ingredient"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("categorie"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));


    return model;

}
 QSqlQueryModel * Plats::afficherTriingredient(){
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM plats ORDER BY ingredient");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("ingredient"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("categorie"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));


     return model;

 }
 QSqlQueryModel * Plats::afficherTricategorie(){
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM plats ORDER BY prix");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("ingredient"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("categorie"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));


     return model;

 }




