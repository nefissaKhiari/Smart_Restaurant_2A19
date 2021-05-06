#include "fournisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
Fournisseur::Fournisseur()
{
id_fournisseur=0;
nom_fournisseur="";
prenom_fournisseur="";
tel=0;
id_produit=0;
}

Fournisseur::Fournisseur(int id_fournisseur  ,QString nom_fournisseur,QString prenom_fournisseur,int tel,int id_produit)
{this->id_fournisseur=id_fournisseur;
    this->nom_fournisseur=nom_fournisseur;
    this->prenom_fournisseur=prenom_fournisseur;
    this->tel=tel;
    this->id_produit=id_produit;
}
int Fournisseur::getid_fournisseur(){return id_fournisseur;}
QString Fournisseur::getnom_fournisseur(){return nom_fournisseur;}
QString Fournisseur::getprenom_fournisseur() {return prenom_fournisseur;}
int Fournisseur::gettel(){return tel;}
int Fournisseur::getid_produit(){return  id_produit;}

//void Fournisseur::setid_fournisseur(int id_fournisseur) {this->id_fournisseur=id_fournisseur;}
//void Fournisseur::setnom_fournisseur(QString nom_fournisseur){this->nom_fournisseur;}
//void Fournisseur::setprenom_fournisseur(QString prenom_fournisseur){this->prenom_fournisseur;}
//void Fournisseur::settel(int tel){this->tel;}
//void Fournisseur::setid_produit(int id_produit) {this->id_produit;}
bool Fournisseur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO fournisseur (id_fournisseur , nom_fournisseur,prenom_fournisseur,tel,id_produit) VALUES (:id_fournisseur,:nom_fournisseur,:prenom_fournisseur,:tel,:id_produit)");
    query.bindValue(":id_fournisseur",id_fournisseur);
    query.bindValue(":nom_fournisseur",nom_fournisseur);
    query.bindValue(":prenom_fournisseur",prenom_fournisseur);
    query.bindValue(":tel",tel);
    query.bindValue(":id_produit",id_produit);
    if( query.exec() ) {
        Historique("Fournisseur "+nom_fournisseur+" "+prenom_fournisseur+" Ajouter");
        return true;
    }
    return false;
}
bool Fournisseur::supprimer(int id_fournisseur )
{
    QSqlQuery query;
    query.prepare("delete from fournisseur where id_fournisseur = :id_fournisseur") ;

    query.bindValue(":id_fournisseur",id_fournisseur);

    if( query.exec() ) {
        Historique("Fournisseur Supprimerr");
        return true;
    }
    return false;;
}
QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM FOURNISSEUR");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom fournisseur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom fournisseur"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel fournisseur"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_produit"));
    return model;
}

bool Fournisseur::modifier(int id_fournisseur)
{
    QSqlQuery query;
    query.prepare("UPDATE Fournisseur SET id_fournisseur= :id_fournisseur,nom_fournisseur = :nom_fournisseur,prenom_fournisseur = :prenom_fournisseur,tel = :tel,id_produit=:id_produit WHERE id_fournisseur= :id_fournisseur ");
    query.bindValue(":id_fournisseur",id_fournisseur);
    query.bindValue(":nom_fournisseur",nom_fournisseur);
    query.bindValue(":prenom_fournisseur",prenom_fournisseur);
    query.bindValue(":tel",tel);
    query.bindValue(":id_produit",id_produit);
    if( query.exec() ) {
        Historique("Fournisseur "+nom_fournisseur+" "+prenom_fournisseur+" Modifier");
        return true;
    }
    return false;
}

QSqlQueryModel * Fournisseur::chercher(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from fournisseur where id_fournisseur like '%"+search+"%' or nom_fournisseur like '%"+search+"%' or prenom_fournisseur like '%"+search+"%' or tel like '%"+search+"%' or id_produit like '%"+search+"%'";
    qDebug()<<qry;

    model->setQuery(qry);
    return model;
}

QSqlQueryModel* Fournisseur::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM FOURNISSEUR ORDER BY nom_fournisseur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom fournisseur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom fournisseur"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel fournisseur"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_produit"));
    return model;
}
QSqlQueryModel* Fournisseur::Find_fournisseur()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id_fournisseur,nom_fournisseur,prenom_fournisseur,tel,id_produit FROM fournisseur");

    query.exec();
    model->setQuery(query);
    return model;
}


bool Fournisseur::Historique(QString active)
{
    QSqlQuery query;
    query.prepare("INSERT INTO historique_four (active,time) VALUES (:active,:time)");
    query.bindValue(":active",active);
    query.bindValue(":time",QDateTime::currentDateTime().toString());
    return query.exec();
}

void Fournisseur::showHistorique(QPlainTextEdit * __p)
{
    QSqlQuery query;
    __p->clear();
    query.exec("SELECT active, time from historique_four order by id");
    while (query.next()) {
        __p->insertPlainText(""+query.value(1).toString()+" : "+query.value(0).toString()+"\r");
    }
}

