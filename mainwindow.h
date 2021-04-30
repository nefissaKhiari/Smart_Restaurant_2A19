#ifndef MAINWINDOW_H
#define MAINWINDOW_H
<<<<<<< HEAD
#include "produits.h"
#include "fournisseur.h"
#include <QMainWindow>
#include <QSqlQuery>
#include "QrCode.hpp"
#include "statistiques.h"
#include <QPropertyAnimation>

=======
#include "livraisons.h"
#include "vehicule.h"
#include <QMainWindow>
>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
<<<<<<< HEAD
private:

    QPropertyAnimation *animation;

private slots:
    void on_pbajouter_clicked();

    void on_supp_clicked();



    void on_tabWidgett_currentChanged(int);
    void on_modifier_clicked();
    /*fournisseurrr*/





    void on_ajoutfrs_clicked();

    void on_frsmod_2_clicked();









    void on_tabWidget_currentChanged(int index);

    void on_QRcode_clicked();

    //void on_list_supp_activated(const QString &arg1);

    void on_frssupp_clicked();

    void on_stat_clicked();

    void on_search_textEdited(const QString &arg1);

    void on_tri_clicked();


    void on_pushButton_clicked();
=======

private slots:


    void on_supp_clicked();

    void on_tabWidget_currentChanged(int index);





    void on_ajout_clicked();

    void on_mod_clicked();



    void on_modv_clicked();

    void on_suppv_clicked();

    void on_ajoutv_clicked();



    void on_recherche_textEdited(const QString &arg1);



    //void on_tabWidget_2_currentChanged(int index);

    void on_trii_clicked();

    void on_pushButton_3_clicked();
>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

<<<<<<< HEAD
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_excelfournii_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    Produits tmpproduit;
    Fournisseur tmpfournisseur;

=======
    void on_mail_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    livraisons tmplivraisons;
        Vehicule tmpv;
>>>>>>> 2eb64e115593b267e435c60f8ef171d60ffecaf4
};

#endif // MAINWINDOW_H
