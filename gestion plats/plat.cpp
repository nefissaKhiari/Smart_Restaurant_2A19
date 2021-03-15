#include "plat.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Plat::Plat()
{
    id=0; nom="";ingredient="";categorie="";prix=0;
}

Plat::Plat(int id,QString nom, QString ingredient, QString categorie, int prix ) {
    this->id=id;    this->nom=nom;    this->ingredient=ingredient; this->categorie=categorie; this->prix=prix;
}

int Plat::getId() {
    return id;
}

void Plat::setId(int id) {
    this->id=id;
}

QString Plat::getNom() {
    return nom;
}

void Plat::setNom(QString nom) {
    this->nom=nom;
}

QString Plat::getIngredient() {
    return  ingredient;
}

void Plat::setIngredient(QString ingredient) {
    this->ingredient=ingredient;
}
QString Plat::getCategorie() {
    return  ingredient;
}

void Plat::setCategorie(QString categorie) {
    this->categorie=categorie;
}
 int Plat::getPrix() {
    return  prix;
}
 void Plat::setPrix(int prix) {
     this->prix=prix;
 }


bool Plat::ajouter() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("INSERT INTO plats (id, nom, ingredient,categorie,prix)" "VALUES (:id, :nom, :ingredient,:categorie,:prix)");
    query.bindValue(0, id_string);
    query.bindValue(1, nom);
    query.bindValue(2, ingredient);
      query.bindValue(3, categorie);
      query.bindValue(4, prix);
    return query.exec();
}

QSqlQueryModel* Plat::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plats");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ingredient"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

QSqlQueryModel* Plat::listId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM plats");
    return model;
}

bool Plat::supprimer(int id) {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("delete from plats where id=:id");
    query.bindValue(0, id);
    return query.exec();
}

bool Plat::modifier() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE plats set nom=:nom, ingredient=:ingredient,categorie=:categorie,prix=:prix where id=:id");
    query.bindValue(0, id_string);
    query.bindValue(1, nom);
    query.bindValue(2, ingredient);
      query.bindValue(3,categorie);
      query.bindValue(4,prix);
    return query.exec();

    /*  --------------------- OR LIKE THIS
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE etudiant set nom='"+nom+"', prenom='"+prenom+"' where id='"+id_string+"'");
    return query.exec();
    ---------------------  */
}

QSqlQueryModel* Plat::afficherById(int id) {
    QSqlQuery query;
    QString id_string = QString::number(id);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM plats where id=:id");
    query.bindValue(0, id_string);
    return model;
}
