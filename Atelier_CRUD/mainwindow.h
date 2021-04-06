#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commande.h"


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
    void on_pushButton_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_date_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_Num_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_6_clicked();

    void on_pushButton_midifier_clicked();

    void on_pushButton_2_clicked();


    void on_NUMCsupp_activated(int index);

    void on_Tab_activated(const QModelIndex &index);

    void on_label_10_linkActivated(const QString &link);

    void on_Tab_clicked(const QModelIndex &index);

    void on_Tab_pressed(QKeyEvent * event);

    void on_Tab_viewportEntered();

private:
    Ui::MainWindow *ui;
    Commande x;
    void showEventHelper();
};

#endif // MAINWINDOW_H
