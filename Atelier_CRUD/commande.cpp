#include "commande.h"

 Commande::Commande(int num,QString date,int idemploye)
{
    this->num=num;
    this->date=date;
     this->idemploye=idemploye;
}
bool Commande::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(num);
    QString res2 = QString::number(idemploye);


    query.prepare("insert into COMMANDES (NUMC,DATEC,IDEMPLOYE)" "values(:num, :date, :idemploye)");

    query.bindValue(":num",res);
    query.bindValue(":date",date);
    query.bindValue(":idemploye",res2);
    return query.exec();

}
bool Commande::SupprimerCommande(int Num)
 {
     QSqlQuery query;
     query.prepare("DELETE FROM COMMANDES WHERE NUMC =:NUM");
     query.bindValue(":NUM",Num);
     return query.exec();
 }
QSqlQueryModel* Commande:: AfficherCommande()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM COMMANDES");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMC"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDEmploye"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DateC"));
    return  model;
 }


