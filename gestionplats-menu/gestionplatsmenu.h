#ifndef GESTIONPLATSMENU_H
#define GESTIONPLATSMENU_H
#include "plats.h"
#include<QLabel>
#include "menu.h"
#include <QFileDialog>
#include <QDialog>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Gestionplatsmenu; }
QT_END_NAMESPACE

class Gestionplatsmenu : public QMainWindow
{
    Q_OBJECT

public:
    Gestionplatsmenu(QWidget *parent = nullptr);
    ~Gestionplatsmenu();
     void INFORMER(QLabel *label ,QString message, int duration);


private slots:

 void showTime();
    void on_ajouter_B_clicked();

    void on_ListDelete_B_clicked();

    void on_ListEdit_B_clicked();

    void on_ConfrimEdit_B_clicked();



    void on_ListEditME_B_clicked();

    void on_ListDeleteME_B_clicked();

    void on_ajouterME_B_clicked();

    void on_ConfrimEditME_B_clicked();

    void on_bouton_imprimer_clicked();

    void on_bouton_imprimer_2_clicked();



    void on_boutonchercher_clicked();

    void on_boutonafficher_clicked();


    void on_trinom_clicked();

    void on_triingredient_clicked();

    void on_tricategorie_clicked();





    void on_exporter_clicked();

    void on_exporter_2_clicked();







private:
    Ui::Gestionplatsmenu *ui;
     Plats P;
     Menu M;

};
#endif // GESTIONPLATSMENU_H
