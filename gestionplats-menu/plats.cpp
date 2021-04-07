#include "plats.h"
#include <QSqlQuery>

#include <QDebug>
#include <QObject>
#include <QPrinter>
#include<QPrintDialog>
#include<QtPrintSupport/QPrintDialog>
Plats::Plats()
{
    id=0;    nom="";    categorie="",prix="",type="", id_menu=0 ;
}

Plats::Plats( QString nom,QString categorie,QString prix,QString type,int id_menu) {
        this->nom=nom;     this->categorie=categorie ; this->prix=prix;  this->type=type;this-> id_menu= id_menu;
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
QString Plats::getType() {
    return type;
}

void Plats::setType(QString type) {
    this->type=type;
}
int Plats::getId_menu() {
    return id_menu;
}

void Plats::setId_menu(int id_menu) {
    this->id_menu=id_menu;
}

bool Plats::ajouter() {
    QSqlQuery query;
     QString idmenu_string = QString::number(id_menu);
    QString id_string = QString::number(id);
    query.prepare("INSERT INTO plats ( nom, categorie,prix,type,id_menu)" "VALUES ( :nom,:categorie,:prix,:type,:id_menu)");

    query.bindValue(0, nom);

     query.bindValue(1, categorie);
      query.bindValue(2, prix);
      query.bindValue(3, type);
       query.bindValue(4, id_menu);

    return query.exec();
}


QSqlQueryModel* Plats::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plats");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Categorie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
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
    query.prepare("UPDATE plats set nom=:nom,  categorie=:categorie, prix=:prix, type=:type,id_menu=:id_menu where id=:id");
    query.bindValue(5, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, categorie);
    query.bindValue(2, prix);
       query.bindValue(3, type);
       query.bindValue(4, id_menu);
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



QSqlQueryModel* Plats::chercher(QString chercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="nom") {
        model->setQuery("SELECT * FROM plats WHERE nom LIKE '"+chercher+"%'");
    }
    else if(by=="categorie") {
       model->setQuery("SELECT * FROM plats WHERE  categorie LIKE '"+chercher+"%'");
    }

    return model;
}
QSqlQueryModel* Plats::Trier(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="nom") {
        model->setQuery("SELECT * FROM plats ORDER BY nom");
    }

    else if(tri=="categorie") {
        model->setQuery("SELECT * FROM plats ORDER BY categorie ");
    }
    else if(tri=="prix") {
        model->setQuery("SELECT * FROM plats ORDER BY prix ");
    }
    else if(tri=="type") {
        model->setQuery("SELECT * FROM plats ORDER BY type ");
    }

    return model;
}








