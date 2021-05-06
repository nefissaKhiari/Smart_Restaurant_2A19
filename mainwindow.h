#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "equipements.h"
#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QMediaPlayer>



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

void on_recherche_textEdited(const QString &arg1);

void on_chat_clicked();


void on_pb_login_clicked();

void on_employe_clicked();

void on_equipement_clicked();

void on_retour_clicked();

void on_retour2_clicked();

void on_chat_2_clicked();

void on_retour3_clicked();

void on_envoyer_clicked();

void on_mail_clicked();

void on_mdp_clicked();

void on_retour4_clicked();

void on_exit_clicked();

void on_horizontalSlider_sliderMoved(int position);

void on_horizontalSlider_2_sliderMoved(int position);

void on_start_clicked();

void on_pushButton_stop_clicked();

void on_checkBox_clicked();

void on_trier_id_employe_clicked();

void on_trier_nom_emplye_clicked();

void on_trier_prenom_employe_clicked();

private:
    Ui::MainWindow *ui;
    Employe tmpemploye;
    Equipement tmpequipement;
    Employe session;
    QMediaPlayer *player;
};

#endif // MAINWIND
