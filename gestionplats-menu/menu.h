#ifndef MENU_H
#define MENU_H


#include <QString>
#include <QSqlQueryModel>

class Menu
{

private:

    int id;
    QString nom,prix,description;

public:
    Menu();
  Menu( QString, QString,QString);
    int getId();
    void setId(int);
    QString getNom();
    void setNom(QString);
    QString getPrix();
    void setPrix(QString);
    QString getDescription();
    void setDescription(QString);



    bool ajouter1();
    bool supprimer1(int);
    bool modifier1();

    QSqlQueryModel* afficher1();
    QSqlQueryModel* afficherById1(int);
    QSqlQueryModel* listId1();
};


#endif // MENU_H
