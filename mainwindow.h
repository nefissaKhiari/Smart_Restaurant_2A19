#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "equipements.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

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

void on_tabWidget_currentChanged(int);

void on_modifier_clicked();

void on_ajout_clicked();

void on_sup_clicked();


private slots:




void on_ajouteq_clicked();

void on_supeq_clicked();

void on_modifeq_clicked();

void on_supprimer_currentChanged(int);

void on_pushButton_3_clicked();

void on_Excel_clicked();

void on_imprimer_clicked();

void on_lineEdit_textEdited(const QString &arg1);

void on_trier_clicked();

private:
    Ui::MainWindow *ui;
    Employe tmpemploye;
    Equipement tmpequipement;
};

#endif // MAINWIND
