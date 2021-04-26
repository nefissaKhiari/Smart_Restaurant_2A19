#ifndef PLATS_H
#define PLATS_H
#include <QString>
#include <QSqlQueryModel>

class Plats
{

private:
    int id;
    int id_menu;
    QString nom, categorie,prix,type;

public:
    Plats();
   Plats( QString,QString,QString,QString,int);
    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);

    QString getCategorie();
    void setCategorie(QString);
    QString getPrix();
    void setPrix(QString);
    QString getType();
    void setType(QString);
    int getId_menu();
    void setId_menu(int);
    bool ajouter();
    bool supprimer(int);
    bool modifier();
QSqlQueryModel* Trier(QString);
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficherById(int);
    QSqlQueryModel* listId();
 QSqlQueryModel* chercher(QString,QString);
};


#endif // PLATS_H
