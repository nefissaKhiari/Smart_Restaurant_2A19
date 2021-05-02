#include "employe.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
Employe::Employe()
{
id=0;
nom="";
prenom="";
adresse="";
telephone=0;
}

Employe::Employe(int id  ,QString nom, QString prenom, QString adresse,int telephone)
{this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->telephone=telephone;}
int Employe::getid(){return id;}
QString Employe:: getnom(){return nom;}
QString Employe::getprenom() {return prenom;}
QString Employe::getadresse(){return adresse;}
int Employe::gettelephone(){return telephone;}
void Employe::setid(int id) {this->id=id;}
void Employe::setnom(QString nom){this->nom;}
void Employe::setprenom(QString prenom){this->prenom;}
void Employe::setadresse(QString adresse){this->adresse;}
void Employe::settelephone(int telephone){this->telephone;}
bool Employe::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO employe (id,nom,prenom,adresse,telephone) VALUES (:id,:nom,:prenom,:adresse,:telephone)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":telephone",telephone);
    return query.exec();
}
bool Employe::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from employe where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM EMPLOYE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("telephone"));
    return model;
}

bool Employe::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE employe SET nom =:nom,prenom =:prenom,adresse =:adresse,telephone =:telephone  WHERE id=:id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":telephone",telephone);
    return query.exec();
}

QSqlQueryModel * Employe::Find_Employe()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,prenom,adresse,telephone FROM employe");

    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * Employe::rechercher(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from employe where id like '%"+search+"%' or nom like '%"+search+"%' or prenom like '%"+search+"%' or adresse like '%"+search+"%' or telephone like '%"+search+"%'";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel * Employe::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY id");
    return model;

}

bool Employe::login(QString __l, QString __p)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users");

    query.exec();
    while(query.next()) {
        if(query.value(1).toString() == __l && query.value(2).toString() == __p) {
            int id_e = query.value(3).toInt();
            QSqlQuery query1;
            query1.exec("SELECT * FROM employe WHERE id = "+QString::number(id_e));
            while(query1.next()) {
                this->id = query1.value(0).toInt();
                this->nom = query1.value(1).toString();
                this->prenom = query1.value(2).toString();
                this->adresse = query1.value(3).toString();
                this->telephone = query1.value(4).toInt();
            }
            return true;
        }
    }
    return false;
}
QSqlQueryModel * Employe::trierid_employe()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from EMPLOYE ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"adresse");
    model->setHeaderData(2,Qt::Horizontal,"telephone");
    return model ;
}
QSqlQueryModel * Employe::trier_nom_emplye()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from EMPLOYE ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"adresse");
    model->setHeaderData(2,Qt::Horizontal,"telephone");
    return model ;
}
QSqlQueryModel * Employe::trier_prenom_emplye()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from EMPLOYE ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"nom");
    model->setHeaderData(2,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"adresse");
    model->setHeaderData(2,Qt::Horizontal,"telephone");
    return model ;
}

