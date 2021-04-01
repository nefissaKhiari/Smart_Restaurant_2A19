#ifndef Vehicule_H
#define Vehicule_H


#include <QString>
#include <QSqlQueryModel>

class Vehicule
{

private:

    int id_vehicule;
    QString modele;
    QString etat;

public:
    Vehicule();
  Vehicule( int, QString , QString);
    int getId_vehicule();
    void setId_vehicule(int);
    QString getModele();
    void setModele(QString);
    QString getEtat();
    void setEtat(QString);


    bool ajouter();


    bool modifier1(int id_vehicule);





    QSqlQueryModel* afficher1();
    bool supprimer1 (QString);



};


#endif // Vehicule_H
