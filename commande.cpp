#include "commande.h"

 Commande::Commande(int idemploye)
{


    this->idemploye=idemploye;

}
bool Commande::ajouter()
{
    QSqlQuery query;

    query.prepare("insert into COMMANDES (IDEMPLOYE)" "values(:idemploye)");
    query.bindValue(":idemploye",idemploye);
    query.exec();


return true;
}

bool Commande::ajouterPlat(int platid, int qty){
    QSqlQuery query;
    QSqlQuery queryId("select max(numc) ID from COMMANDES;");
          queryId.next();
          this->idcommande = queryId.value(0).toString();

    query.prepare("begin insert into CommandePlat (Numc,Id_Plat, Qty) values (:numc, :idplat, :qty); exception when dup_val_on_index then update CommandePlat set    qty = qty + :qty where  Numc = :numc and Id_Plat = :idplat; commit; end;");
     query.bindValue(":numc",this->idcommande);
     query.bindValue(":idplat",platid);
     query.bindValue(":qty",qty);
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
    model->setQuery("SELECT* FROM COMMANDES");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMC"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("IDEMPLOYE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEC"));

    return  model;

 }
bool Commande::modifierEmployer(int num)
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDES SET NUMC= :NUMC,IDEMPLOYE=:IDEMPLOYE WHERE NUMC=:NUMC");

    query.bindValue(":NUMC",num);

    query.bindValue(":IDEMPLOYE",idemploye);

    return  query.exec();
}
bool Commande::modifierQTY(int num,int IDplat, int qty){
    QSqlQuery query;
query.prepare("begin insert into COMMANDEPLAT (Numc,Id_Plat, Qty) values (:numc, :idplat, :qty); exception when dup_val_on_index then update CommandePlat set    qty =:qty where  Numc = :numc and Id_Plat = :idplat; commit; end;");
query.bindValue(":numc",num);
query.bindValue(":idplat",IDplat);
query.bindValue(":qty",qty);
return query.exec();
}
QSqlQueryModel* Commande:: AfficherPlat()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM PLATS");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Plat"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Plat"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix Plat"));

    return  model;

 }
QSqlQueryModel * Commande::chercherCom(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from commandes where numc like '%"+search+"%' or idemploye like '%"+search+"%' or to_char(datec,'DD/MM/YYYY HH:MM AM') like '%"+search+"%' or PRIXtot like '%"+search+"%' ";
    qDebug()<<qry;

    model->setQuery(qry);
    return model;
}

