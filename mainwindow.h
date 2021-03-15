#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "plat.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_B_clicked();

    void on_delete_B_clicked();

    void on_ListDelete_B_clicked();

    void on_ListEdit_B_clicked();

    void on_BackToConfig_B_clicked();

    void on_ConfrimEdit_B_clicked();

private:
    Ui::MainWindow *ui;
    Plat P;
};

#endif // MAINWINDOW_H
