#include "commande.h"

 Commande::Commande(int num,QString date,int idemploye,QString nomp)
{
    this->num=num;
    this->date=date;
    this->idemploye=idemploye;
    this->nomp=nomp;
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
     query.prepare("DELETE FROM COMMANDES WHERE NUMC=:NUM");
     query.bindValue(":NUM",Num);
     return query.exec();
 }
QSqlQueryModel* Commande:: AfficherCommande()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM COMMANDEPLAT");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMC"));

    return  model;

 }
bool Commande::modifierCommande()
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDES SET NUMC= :NUMC,IDEMPLOYE=:IDEMPLOYE,NOMP = :NOMP,DATEC = :DATEC WHERE NUMC=:NUMC");
    query.bindValue(":NUMC",num);
    query.bindValue(":NOMP",nomp);
    query.bindValue(":DATEC",date);
    query.bindValue(":IDEMPLOYE",idemploye);

    return    query.exec();
}


