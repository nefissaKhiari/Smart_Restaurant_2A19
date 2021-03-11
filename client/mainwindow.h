#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "carte_fidelite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Carte_clicked();


    void on_pushButton_Client_clicked();

    void on_pushButton_Ajouter_clicked();

    void on_gerer_CF_clicked();

    void on_pushButton_clicked();

    void on_re_2_1_clicked();

    void on_re_3_0_clicked();

    void on_re_4_3_clicked();

    void on_gerer_client_clicked();

    void on_annuler_client_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_client_clicked();



    void on_supp_client_clicked();

    void on_supprimer_client_clicked();



    void on_re_7_3_clicked();

    void on_consulter_client_clicked();

    void on_re_6_4_clicked();

private:
    Ui::MainWindow *ui;
    client tmpC;
};
#endif // MAINWINDOW_H
