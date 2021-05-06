#ifndef SUPPLEMENT_H
#define SUPPLEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QObject>
#include <QMessageBox>


class supplement
{
    QString nomsup,typesup;
    int prixsup;

public:
    supplement(){}
    supplement(QString,QString,int);
    QString idcommande;



    QString getNomSup(){return nomsup;}
    QString getTypeSup(){return typesup;}
    int getPrixSup(){return prixsup;}


    void setNomSup(QString nomsup){this->nomsup=nomsup;}
    void setTypeSup(QString typesup){this->typesup=typesup;}
    void setPrixSup(int prixsup){this->prixsup=prixsup;}


    bool AjouterSuppcom(int idsup, int qtysup);
    bool ajouterSup();
    bool SupprimerSupp(int);
    QSqlQueryModel* AfficherSupplement();
    QSqlQueryModel*AfficherPlat();

    bool modifierSupplement(int);
    bool modifierQTYsup(int,int , int);
      QSqlQueryModel* tri();
      QSqlQueryModel* chercher(QString);

};

#endif // SUPPLEMENT_H
