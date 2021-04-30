#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produits.h"
#include "fournisseur.h"
#include <QMainWindow>
#include <QSqlQuery>
#include "QrCode.hpp"
#include "statistiques.h"
#include <QPropertyAnimation>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
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

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_excelfournii_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    Produits tmpproduit;
    Fournisseur tmpfournisseur;

};

#endif // MAINWINDOW_H
