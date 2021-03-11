#include "client.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
client::client()
{

}
bool client::ajouter()
{



      QSqlQuery query;


      query.prepare("insert into CLIENT (ID,AGE,NOM,ADRESSE,PRENOM) values(:ID,:Age,:Nom,:Adresse,:Prenom)");

query.bindValue(":ID",getID());
query.bindValue(":Age",getAge());
query.bindValue(":Nom",getNom());
query.bindValue(":Adresse",getAdresse());
query.bindValue(":Prenom", getPrenom());

return query.exec();

}

bool client::Supprimer(QString ID)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENT where to_char(ID) = :ID");
    query.bindValue(":ID",ID);
    return query.exec();
}

void client::afficher(QString* ID,QString*Nom,QString*Prenom,QString*Age,QString*Adresse)
{

    QSqlQuery q;

   q.prepare("select * from RAMASSAGE where to_char(ID)='"+*ID+"'");

    if(q.exec())
    {
        while(q.next())
        {
*ID= q.value(0).toString();
*Age=q.value(1).toString();
*Nom   =q.value(2).toString();
*Adresse  =q.value(3).toString();
*Prenom  =q.value(4).toString();


}
    }



}
QSqlQueryModel * client ::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT ");



return model;
}
