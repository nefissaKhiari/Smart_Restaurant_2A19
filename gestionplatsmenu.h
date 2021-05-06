#ifndef GESTIONPLATSMENU_H
#define GESTIONPLATSMENU_H
#include "plats.h"
#include<QLabel>
#include "menu.h"
#include <QFileDialog>
#include <QDialog>
#include <QMainWindow>
#include<QObject>
#include<QMediaPlayer>



QT_BEGIN_NAMESPACE
namespace Ui { class Gestionplatsmenu; }
QT_END_NAMESPACE

class Gestionplatsmenu : public QMainWindow
{
    Q_OBJECT

public:
    Gestionplatsmenu(QWidget *parent = nullptr);
    ~Gestionplatsmenu();
     void INFORMER(QLabel *label ,QString message, int duration);



private slots:

 void showTime();
    void on_ajouter_B_clicked();

    void on_ListDelete_B_clicked();

    void on_ListEdit_B_clicked();

    void on_ConfrimEdit_B_clicked();



    void on_ListEditME_B_clicked();

    void on_ListDeleteME_B_clicked();



    void on_ConfrimEditME_B_clicked();

    void on_bouton_imprimer_clicked();






    void sendMail();

    void mailSent(QString);

    void browse();










    void on_exporter_2_clicked();






    void on_pushButton_3_clicked();

    void on_exporterM_clicked();

    void on_exporterXM_clicked();


    void on_bouton_imprimer_3_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_bouton_imprimer_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_trier_clicked();




    void on_pushButton_8_clicked();



    void on_pushButton_9_clicked();

    void on_chercher_2_textChanged(const QString &arg1);

    void on_trier_2_clicked();

    void on_pushButton_10_clicked();

    void on_sliderprog_sliderMoved(int position);

    void on_slidervolume_sliderMoved(int position);

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();
      void on_positionChanged(qint64 position);
    void on_durationChanged(qint64 position);

    void on_stat_clicked();

    void on_pushButton_20_clicked();


    void on_pushButton_13_clicked();

    void on_pushButton_22_clicked();
    void makePlot_type ();
        QVector<double> Statistique_type();
        void on_pushButton_25_clicked();

private:
    Ui::Gestionplatsmenu *ui;
     Plats P;
     Menu M;
     QMediaPlayer* player;

 QStringList files;
};
#endif // GESTIONPLATSMENU_H
