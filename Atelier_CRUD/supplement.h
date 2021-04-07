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
    supplement();




    QString getNomSup(){return nomsup;}
    QString getTypeSup(){return typesup;}
    int getPrixSup(){return prixsup;}


    void setNomSup(QString nomsup){this->nomsup=nomsup;}
    void setTypeSup(QString typesup){this->typesup=typesup;}
    void setPrixSup(int prixsup){this->prixsup=prixsup;}


    bool ajouterPlat(int platid, int qty);
    bool ajouterSup();
    bool SupprimerCommande(int);
    QSqlQueryModel* AfficherCommande();
    QSqlQueryModel*AfficherPlat();
    bool ConfirmCom();
    bool modifierEmployer(int);
    bool modifierQTY(int,int,int);
};

#endif // SUPPLEMENT_H
