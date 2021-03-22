#include "menu.h"

#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Menu::Menu()
{
    id=0;    nom="";   prix="";  description="";   id_plat=0;
}

Menu::Menu( QString nom,QString prix,QString description,int id_plat) {
      this->nom=nom;  this->prix=prix;  this->description=description;    this-> id_plat= id_plat;
}

int Menu::getId() {
    return id;
}

void Menu::setId(int id) {
    this->id=id;
}

QString Menu::getNom() {
    return nom;
}

void Menu::setNom(QString nom) {
    this->nom=nom;
}


QString Menu::getPrix() {
    return prix;
}

void Menu::setPrix(QString prix) {
    this->prix=prix;
}
QString Menu::getDescription() {
    return description;
}

void Menu::setDescription(QString description) {
    this->description=description;
}
int Menu::getIdplat() {
    return id_plat;
}

void Menu::setIdplat(int id_plat) {
    this->id_plat=id_plat;
}
bool Menu::ajouter1() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    QString idplat_string = QString::number(id_plat);
    query.prepare("INSERT INTO menu ( nom,prix,description,id_plat)" "VALUES ( :nom, :prix,:description,:id_plat)");
    query.bindValue(0, nom);
      query.bindValue(1, prix);
       query.bindValue(2, description);
         query.bindValue(3,idplat_string);
    return query.exec();
}

QSqlQueryModel* Menu::afficher1() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM menu");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    return model;
}



QSqlQueryModel* Menu::listId1() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id FROM menu");
    return model;
}

bool Menu::supprimer1(int id) {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("delete from menu where id=:id");
    query.bindValue(0, id);
    return query.exec();
}

bool Menu::modifier1() {
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("UPDATE menu set nom=:nom, prix=:prix ,description=:description where id=:id");
    query.bindValue(3, id_string);
    query.bindValue(0, nom);
    query.bindValue(1, prix);
      query.bindValue(2, description);
    return query.exec();


}

QSqlQueryModel*Menu::afficherById1(int id) {
    QSqlQuery query;
    QString id_string = QString::number(id);
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM menu where id=:id");
    query.bindValue(0, id_string);
    return model;
}
