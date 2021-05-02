#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


private slots:
    void on_pushButton_connect_clicked();
   //
    void on_quitter_clicked();

signals:
    void sig();
    //
private:
    Ui::login *ui;
    MainWindow *m;
};

#endif // LOGIN_H
