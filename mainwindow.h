#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
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

    void on_ajout_clicked();

    void on_sup_clicked();

private:
    Ui::MainWindow *ui;
    Employe tmpemploye;
};

#endif // MAINWIND
