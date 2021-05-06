#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
#include<QString>
#include<QSqlQueryModel>

class carte_fidelite
{
    QString  numero;
    QString ID;
    QString date_creation;
    QString nb_points;

public:
    carte_fidelite();
    QString getID()
    {return ID; }
    QString getNumero()
    {return numero; }
    QString getDate_creation()
    {return date_creation; }
    QString getNb_points()
    {return nb_points; }


    void setID(QString id)
    {ID=id;}
    void setNumero(QString num)
    {numero=num;}
    void setDate_creation(QString d)
    {date_creation=d;}

    void setNb_points(QString nb)
    {nb_points=nb; }

    bool ajouter();
    void afficher(QString* ID,QString* numero,QString* date_creation,QString* nb_points);
    QSqlQueryModel * afficher();
bool Modifier(QString ID,QString numero,QString date_creation,QString nb_points);
    bool Supprimer(QString Numero);
    QSqlQueryModel * tri(int index);
    QSqlQueryModel * rechercherCF(QString chercher);
};

#endif // CARTE_FIDELITE_H

