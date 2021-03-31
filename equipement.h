#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QSqlQueryModel>
class Equipement
{
public:
    Equipement();
    Equipement(int ,QString,QString,QString,int);
    int getid();
    QString getmateriel();
    QString getpost();
    void setid(int);
    void setmaterirel(QString);
    void setpost(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier(int id);
private:
    int id;
    QString nom ,materiel,post ;

   };

   #endif // EQUIPEMENT_H
