#ifndef GESTIONPRODUIT_H
#define GESTIONPRODUIT_H

#include "produits.h"
#include "fournisseur.h"
#include <QMainWindow>
#include <QSqlQuery>
#include "QrCode.hpp"



namespace Ui {
class Gestionproduit;
}

class Gestionproduit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gestionproduit(QWidget *parent = nullptr);
    ~Gestionproduit();

private slots:
    void on_pbajouter_clicked();

    void on_supp_clicked();



    void on_tabWidgett_currentChanged(int);
    void on_modifierprod_clicked();
    /*fournisseurrr*/





    void on_ajoutfrs_clicked();

    void on_frsmod_2_clicked();









    void on_tabWidget_currentChanged(int index);

    void on_QRcode_clicked();

    //void on_list_supp_activated(const QString &arg1);

    void on_frssupp_clicked();

    void on_statprix_clicked();

    void on_search_textEdited(const QString &arg1);

    void on_trifourni_clicked();


    void on_gestionfourni_clicked();

    void on_gestionprod_clicked();

    void on_retourfp_clicked();

    void on_retour2fp_clicked();

    void on_retour3fp_clicked();

private:
    Ui::Gestionproduit *ui;
    Produits tmpproduit;
    Fournisseur tmpfournisseur;
};
#endif // GESTIONPRODUIT_H
