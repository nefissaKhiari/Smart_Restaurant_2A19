#include "menu.h"

#include <QSqlQuery>
#include <QDebug>
#include <QObject>

Menu::Menu()
{
    id=0;    nom="";   prix="";  description="";
}

Menu::Menu( QString nom,QString prix,QString description) {
      this->nom=nom;  this->prix=prix;  this->description=description;
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

bool Menu::ajouter1() {
    QSqlQuery query;
    QString id_string = QString::number(id);

    query.prepare("INSERT INTO menu ( nom,prix,description)" "VALUES ( :nom, :prix,:description)");
    query.bindValue(0, nom);
      query.bindValue(1, prix);
       query.bindValue(2, description);

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

QSqlQueryModel* Menu::chercher1(QString chercher,QString by) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(by=="nom") {
        model->setQuery("SELECT * FROM menu WHERE nom LIKE '"+chercher+"%'");
    }
    else if(by=="prix") {
       model->setQuery("SELECT * FROM plats WHERE  prix LIKE '"+chercher+"%'");
    }

    return model;
}
QSqlQueryModel* Menu::Trier1(QString tri) {
    QSqlQueryModel* model = new QSqlQueryModel();
    if(tri=="nom") {
        model->setQuery("SELECT * FROM menu ORDER BY nom");
    }


    else if(tri=="prix") {
        model->setQuery("SELECT * FROM menu ORDER BY prix ");
    }
    else if(tri=="description") {
        model->setQuery("SELECT * FROM menu ORDER BY description ");
    }

    return model;
}

