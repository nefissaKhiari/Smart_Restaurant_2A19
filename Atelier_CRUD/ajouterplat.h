#ifndef AJOUTERPLAT_H
#define AJOUTERPLAT_H

#include <QDialog>

namespace Ui {
class ajouterplat;
}

class ajouterplat : public QDialog
{
    Q_OBJECT

public:
    explicit ajouterplat(QWidget *parent = nullptr);
    ~ajouterplat();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_Supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ajouterplat *ui;
};

#endif // AJOUTERPLAT_H
