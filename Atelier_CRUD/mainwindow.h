#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commande.h"
#include "supplement.h"
#include <QPrinter>
#include <QPdfWriter>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void showEvent(QShowEvent *ev);
private slots:




    void on_pushButton_4_clicked();







    void on_pushButton_midifier_clicked();














    void UpdateTime();






    void on_getid_clicked();

    void on_UpdateQuantity_clicked();

    void on_ADD_supp_clicked();

    void on_Delete_sup_clicked();

    void on_Modifier_Nom_sup_clicked();





    void on_ADD_supp_4_clicked();

    void on_UpdateQuantity_2_clicked();





    void on_serchsup_textEdited(const QString &arg1);





    void on_serchcom_textEdited(const QString &arg1);



    void on_RecuCommande_clicked();

    void on_AddCommande_clicked();

    void on_SupprimerCommande_clicked();

private:
    Ui::MainWindow *ui;
    Commande x;
    void showEventHelper();
    QTimer *timer_1s;
    void RefreshTables();
    supplement t;
};

#endif // MAINWINDOW_H
