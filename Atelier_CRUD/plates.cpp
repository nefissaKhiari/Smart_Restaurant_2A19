#include "plates.h"

plates::plates( int IDp ,QString nom,int prix)
{

    this->nom=nom;
    this->prix=prix;
    this->IDp=IDp;
}
plates::plates( QString nom,int prix)
{

    this->nom=nom;
    this->prix=prix;

}
bool plates::ajouter()
{
    QSqlQuery query;
    QString res2 = QString::number(prix);


    query.prepare("insert into PLATES (NOMP,PRIX)" "values(:nomp, :prix)");
    query.bindValue(":nomp",nom);
    query.bindValue(":prix",res2);

    return query.exec();

}

bool plates::SupprimerPlat(int IDp)
 {
     QSqlQuery query;
     query.prepare("DELETE FROM PLATES WHERE IDP=:IDp");
     query.bindValue(":IDp",IDp);
     return query.exec();
 }
QSqlQueryModel* plates:: AfficherPlat()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM PLATES");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDP"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOMP"));


    return  model;
 }
QSqlQueryModel* plates:: AfficherIDPlat()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT max(IDP)+1 AS ID FROM PLATES");
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDP"));
     return  model;
  }
bool plates::ModifierPlat(int IDp)
{
       QSqlQuery query;
       query.prepare(" UPDATE PLATES SET NOMP = :NOMP,PRIX = :PRIX, WHERE  IDP = :IDP");
                          query.bindValue(":NOMP",nom);
                          query.bindValue(":IDP",IDp);
                          query.bindValue(":PRIX", prix);
                         return query.exec();
/*QSqlQuery query;
    query.prepare("UPDATE COMMANDES SET NUMC= :NUMC,IDEMPLOYE=:IDEMPLOYE,NOMP = :NOMP,DATEC = :DATEC WHERE NUMC=:NUMC");
    query.bindValue(":NUMC",num);
    query.bindValue(":NOMP",nomp);
    query.bindValue(":DATEC",date);
    query.bindValue(":IDEMPLOYE",idemploye);

    return    query.exec();*/


}


