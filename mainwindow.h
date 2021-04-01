#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "livraisons.h"
#include "vehicule.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_supp_clicked();

    void on_tabWidget_currentChanged(int index);





    void on_ajout_clicked();

    void on_mod_clicked();



    void on_modv_clicked();

    void on_suppv_clicked();

    void on_ajoutv_clicked();



    void on_recherche_textEdited(const QString &arg1);



private:
    Ui::MainWindow *ui;
    livraisons tmplivraisons;
        Vehicule tmpv;
};

#endif // MAINWINDOW_H
