#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QSqlQueryModel>
class client
{ QString ID;
    QString Nom;
    QString Prenom;
    QString Age;
    QString Adresse;

public:
    client();

    QString getID()
    {return ID; }
    QString getNom()
    {return Nom; }
    QString getPrenom()
    {return Prenom; }
    QString getAdresse()
    {return Adresse; }
    QString getAge()
    {return Age; }

    void setID(QString id)
    {ID=id;}
    void setNom(QString n)
    {Nom=n;}
    void setPrenom(QString pr)
    {Prenom=pr;}
    void setAge(QString age)
    {Age=age;}
    void setAdresse(QString ad)
    {Adresse=ad; }
bool ajouter();
void afficher(QString* ID,QString*Nom,QString*Prenom,QString*Age,QString*Adresse);
QSqlQueryModel * afficher();
bool Modifier(QString ID,QString Nom,QString Prenom,QString Age,QString Adresse);
bool Supprimer(QString ID);
  QSqlQueryModel * rechercherCL(QString chercher);
};

#endif // CLIENT_H
