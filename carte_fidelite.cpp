#include "carte_fidelite.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlQueryModel>
carte_fidelite::carte_fidelite()
{

}

bool carte_fidelite::Supprimer(QString Numero)
{
    QSqlQuery query;
    query.prepare("Delete from CARTE_FIDELITE where to_char(Numero) = :Numero");
    query.bindValue(":Numero",Numero);
    return query.exec();
}
QSqlQueryModel * carte_fidelite::tri(int index)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    if (index==1)
    model->setQuery("select NUMERO from CARTE_FIDELITE ORDER BY NB_POINT DESC");

    else if (index==2)
        model->setQuery("select NUMERO from CARTE_FIDELITE ORDER BY to_date(DATE_CREATION,'dd/MM/yyyy') DESC");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero"));
   return model;
}


bool carte_fidelite::ajouter()
{
      QSqlQuery query;


      query.prepare("insert into CARTE_FIDELITE (NUMERO,DATE_CREATION,NB_POINT,ID_CLIENT) values(:Numero,:Date,:Nb_point,:ID)");

query.bindValue(":Numero",getNumero());
query.bindValue(":Date",getDate_creation());
query.bindValue(":Nb_point",getNb_points());
query.bindValue(":ID",getID());


return query.exec();

}

void carte_fidelite::afficher (QString* ID,QString* numero,QString* date_creation,QString* nb_points)
{

    QSqlQuery q;

   q.prepare("select * from CARTE_FIDELITE where to_char(NUMERO)='"+*numero+"'");

    if(q.exec())
    {
        while(q.next())
        {

*numero=q.value(0).toString();
*date_creation =q.value(1).toString();
*nb_points  =q.value(2).toString();
*ID  =q.value(3).toString();


}
    }



}
QSqlQueryModel * carte_fidelite ::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM CARTE_FIDELITE  ");
return model;

}
bool  carte_fidelite::Modifier(QString ID,QString numero,QString date_creation,QString nb_points)
{
     QSqlQuery q;

q.prepare("update CARTE_FIDELITE set DATE_CREATION=:Date,NB_POINT=:Nb_point,ID_CLIENT=:ID where Numero=:Numero ");

q.bindValue(":Numero",numero);
q.bindValue(":Date",date_creation);
q.bindValue(":Nb_point",nb_points);
q.bindValue(":ID",ID);
q.exec();
        return   q.exec();
}
QSqlQueryModel * carte_fidelite ::rechercherCF(QString chercher)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM CARTE_FIDELITE WHERE NUMERO LIKE '%"+chercher+"%' ");
return model;

}
