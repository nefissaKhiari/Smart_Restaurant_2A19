#ifndef LIVRAISONS_H
#define LIVRAISONS_H

#include <QString>
#include <QSqlQueryModel>

class livraisons
{
public:

    livraisons();
    livraisons(int , int, int);
    int getID();

    int getID_LIVREUR();
    int getID_V ();
    void setID(int);

    void setID_LIVREUR(int);
    void setID_V(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (QString);
    bool modifier();

    QSqlQueryModel *rechercher(QString search);
        QSqlQueryModel* trii();
private:
    int ID;

    int ID_LIVREUR;
    int ID_V;

};

#endif // LIVRAISONS_H
