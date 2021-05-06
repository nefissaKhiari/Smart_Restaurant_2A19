#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>
#include <QPlainTextEdit>
#include <QDateTime>
class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int ,QString,QString,int,int);
    int getid_fournisseur();
    QString getnom_fournisseur();
    QString getprenom_fournisseur();
    int gettel();
    int getid_produit ();
    void setid_fournisseur(int);
    void setnom_fournisseur(QString);
    void setprenom_fournisseur(QString);
    void settel(int);
    void setid_produit(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier(int id_fournisseur);
    QSqlQueryModel * chercher(QString search);
    QSqlQueryModel* tri();
        QSqlQueryModel* Find_fournisseur();
        bool Historique(QString active);
        void showHistorique(QPlainTextEdit * __p);



private:
    int id_fournisseur;
    QString nom_fournisseur, prenom_fournisseur;
    int tel,id_produit;

};

#endif // FOURNISSEUR_H
