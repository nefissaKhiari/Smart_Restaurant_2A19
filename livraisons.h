#ifndef LIVRAISONS_H
#define LIVRAISONS_H

#include <QString>
#include <QSqlQueryModel>

class livraisons
{
public:
   livraisons();
    livraisons(int , int,int);
    int getID();
    int getDATE_L();
    int getID_LIVREUR();

    void setID(int);
    void setDATE_L(int);
    void setID_LIVREUR(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (QString);
    bool modifier();

    QSqlQueryModel *rechercher(QString search);
private:
    int ID;
 int DATE_L;
    int ID_LIVREUR;

};

#endif // LIVRAISONS_H
