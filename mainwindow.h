#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produits.h"
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
    void on_pbajouter_clicked();

    void on_supp_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_modifier_clicked();

private:
    Ui::MainWindow *ui;
    Produits tmpproduit;
};

#endif // MAINWINDOW_H
