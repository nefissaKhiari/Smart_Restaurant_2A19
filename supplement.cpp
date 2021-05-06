#include "supplement.h"

supplement::supplement(QString nomsup , QString typesup , int prixsup)
{
    this->nomsup=nomsup;
    this->typesup=typesup;
    this->prixsup=prixsup;
}
bool supplement::ajouterSup()
{
    QSqlQuery query;
    query.prepare("insert into SUPPLEMENT (NOM,TYPE,PRIX)" "values(:nom,:type,:prix)");
    query.bindValue(":nom",nomsup);
    query.bindValue(":type",typesup);
    query.bindValue(":prix",prixsup);
    query.exec();
    return true;

}
QSqlQueryModel* supplement:: AfficherSupplement()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM SUPPLEMENT");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

    return  model;

 }

bool supplement::SupprimerSupp(int idsup)
 {
     QSqlQuery query;

     query.prepare("DELETE FROM SUPPLEMENT WHERE IDS=:ids");
     query.bindValue(":ids",idsup);

     return query.exec();
 }

bool supplement::modifierSupplement(int idsup)
{
    QSqlQuery query;
    query.prepare("UPDATE SUPPLEMENT SET IDS= :IDS,NOM=:NOM,TYPE=:TYPE,PRIX=:PRIX WHERE IDS=:IDS");

    query.bindValue(":IDS",idsup);
    query.bindValue(":NOM",nomsup);
    query.bindValue(":TYPE",typesup);
    query.bindValue(":PRIX",prixsup);

    return  query.exec();
}
bool supplement::AjouterSuppcom(int idsup, int qtysup){
    QSqlQuery query;
    QSqlQuery queryId("select max(numc) ID from COMMANDES;");
          queryId.next();
          this->idcommande = queryId.value(0).toString();

    query.prepare("begin insert into SUPPCOM (NUMC,IDS, QTY) values (:numc, :idsup, :qty); exception when dup_val_on_index then update SUPPCOM set    qty = qty + :qty where  NUMC = :numc and IDS = :idsup; commit; end;");
     query.bindValue(":numc",this->idcommande);
     query.bindValue(":idsup",idsup);
     query.bindValue(":qty",qtysup);
     return query.exec();
}

bool supplement::modifierQTYsup(int num,int idsup, int qty){
    QSqlQuery query;
query.prepare("begin insert into SUPPCOM (NUMC,IDS, QTY) values (:numc, :idsup, :qty); exception when dup_val_on_index then update SUPPCOM set    qty = :qty where  NUMC = :numc and IDS = :idsup; commit; end;");
query.bindValue(":numc",num);
query.bindValue(":idsup",idsup);
query.bindValue(":qty",qty);
return query.exec();
}
QSqlQueryModel* supplement::tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM SUPPLEMENT ORDER BY PRIX");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}
QSqlQueryModel * supplement::chercher(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from supplement where IDS like '%"+search+"%' or NOM like '%"+search+"%' or TYPE like '%"+search+"%' or PRIX like '%"+search+"%' ";
    qDebug()<<qry;

    model->setQuery(qry);
    return model;
}
