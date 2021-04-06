/*#include "plats.h"

plats::plats(int IDp, QString nom,int prix)
{
    this->getIDp();
    this->nom=nom;
    this->prix=prix;
}
bool plats::ajouter()
{
    QSqlQuery query;
    QString res2 = QString::number(prix);


    query.prepare("insert into PLATES (IDP,NOMP,PRIX)" "values(:idp, :nomp, :prix)");

    query.bindValue(":nomp",nom);
    query.bindValue(":prix",res2);

    return query.exec();

}

bool plats::SupprimerPlat(int IDp)
 {
     QSqlQuery query;
     query.prepare("DELETE FROM PLATES WHERE IDP=:IDp");
     query.bindValue(":IDp",IDp);
     return query.exec();
 }
QSqlQueryModel* plats:: AfficherPlat()
 {
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM PLATES");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDP"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMP"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return  model;
 }

*/
