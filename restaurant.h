#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "produits.h"
#include "fournisseur.h"
#include <QMainWindow>
#include <QSqlQuery>
#include "QrCode.hpp"
#include "client.h"
#include "carte_fidelite.h"
#include "commande.h"
#include "supplement.h"
#include <QPrinter>
#include <QPdfWriter>
#include <QProcess>
#include "panier.h"
#include "plats.h"
#include<QLabel>
#include "menu.h"
#include <QFileDialog>
#include <QDialog>
#include "arduino.h"
#include <QMainWindow>
#include<QObject>
#include<QMediaPlayer>
#include "employe.h"
#include "equipements.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPropertyAnimation>
#include "livraisons.h"
#include "vehicule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class restaurant; }
QT_END_NAMESPACE

class restaurant : public QMainWindow
{
    Q_OBJECT

public:
   restaurant(QWidget *parent = nullptr);
    ~restaurant();

    void refrech();
private:

    QPropertyAnimation *animation;
     void INFORMER(QLabel *label ,QString message, int duration);
protected:
    void showEvent(QShowEvent *ev);


private slots:

 void showTime();
    void on_ajouter_B_clicked();

    void on_ListDelete_B_clicked();

    void on_ListEdit_B_clicked();

    void on_ConfrimEdit_B_clicked();



    void on_ListEditME_B_clicked();

    void on_ListDeleteME_B_clicked();
    void on_tabWidget_currentChanged(int);

    void on_modifier_clicked();

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_ajout_clicked();

    void on_sup_clicked();
    void on_ajouteq_clicked();

    void on_supeq_clicked();

    void on_modifeq_clicked();

    void on_supprimer_currentChanged(int);

    void on_pushButton_3_clicked();

    void on_Excel_clicked();

    void on_imprimer_clicked();



    void on_trier_clicked();

    void on_recherche_textEdited(const QString &arg1);

    void on_chat_clicked();




    void on_chat_2_clicked();

    void on_retourpageemploye_clicked();

    void on_ConfrimEditME_B_clicked();

    void on_bouton_imprimer_clicked();
    void sendMail();

    void mailSent(QString);

    void browse();
    void on_exporter_2_clicked();
    void on_affichermenu_clicked();

    void on_exporterM_clicked();

    void on_exporterXM_clicked();

    void on_bouton_imprimer_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_bouton_imprimer_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_trieremplo_clicked();

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

        void on_pushButton_28_clicked();

        void on_gestionplatmenu_clicked();
        void on_pbajouter_clicked();

        void on_supp_clicked();



        void on_tabWidgett_currentChanged(int);
        void on_modifierprod_clicked();
        /*fournisseurrr*/





        void on_ajoutfrs_clicked();

        void on_frsmod_2_clicked();









        void on_tabWidget_4_currentChanged(int index);

        void on_QRcode_clicked();

        //void on_list_supp_activated(const QString &arg1);

        void on_frssupp_clicked();

        void on_statprix_clicked();

        void on_search_textEdited(const QString &arg1);

        void on_trifourni_clicked();


        void on_gestionfourni_clicked();

        void on_gestionprod_clicked();

        void on_retourfp_clicked();

        void on_retour2fp_clicked();

        void on_retour3fp_clicked();


        void on_gestionproduit_clicked();

        void on_pb_login_2_clicked();

        void on_notepad_clicked();

        void on_pagegoogle_clicked();

        void on_statmateriel_clicked();

        void on_excelrym_clicked();

        void on_imprimerim_clicked();



        void on_pushButton_29_clicked();

        void on_contacteznous_clicked();

        //mode
        void on_radioButton_nuit_toggled(bool checked);

        void on_radioButton_jour_toggled(bool checked);

        //liv

        void on_suppl_clicked();

        void on_gestionlv_currentChanged(int index);





        void on_ajoutliv_2_clicked();

        void on_mod_clicked();



        void on_modv_clicked();

        void on_suppv_clicked();

        void on_ajoutv_clicked();



        void on_recherche_textEdited2(const QString &arg1);



        //void on_tabWidget_2_currentChanged(int index);

        void on_triil_clicked();

        void on_pdfl_clicked();



        void on_trive_clicked();



        void on_gestionlivb_clicked();


        //client
        void on_pushButton_Carte_clicked();


        void on_pushButton_Client_clicked();

        void on_pushButton_Ajouter_clicked();



        void on_annuler_client_clicked();



        void on_ajouter_client_clicked();



      /*  void on_supp_client_clicked();

        void on_supprimer_client_clicked();

    */

        void on_re_7_3_clicked();



      //  void on_re_6_4_clicked();

        void on_re_7_5_clicked();

        void on_pushButton_Ajouter_5_clicked();



        void on_annuler_client_3_clicked();

        void on_ajouter_Carte_clicked();



        void on_tableView_client_clicked(const QModelIndex &index);

        void on_tableView_carte_clicked(const QModelIndex &index);

        void on_pushButton_Ajouter_client_clicked();

        void on_pushButton_Ajouter_Carte_clicked();

        void on_pushButton_supp_Carte_clicked();

        void on_Enregistrer_client_clicked();

        void on_pushButton_supp_clicked();


        void on_pushButton_save_MAJ_Carte_clicked();

        void on_Modifier_clicked();

        void on_pushButton_save_MAJ_Client_clicked();

        void on_pushButton_Modif_client_clicked();

        void on_pushButtonverspage4_clicked();

        void on_annuler_modif_ca_clicked();

        void on_pushButton_Ann_MAJ_client_clicked();



        void on_comboBox_tri_Carte_activated(int index);

        void on_recherch_CF_textChanged(const QString &arg1);

        void on_recherche_cl_textChanged(const QString &arg1);





        void on_gestionclient_clicked();

        void on_jeu_clicked();
        //commande//

        void on_pushButton_4_clicked();







        void on_pushButton_midifier_clicked();














        void UpdateTime();






        void on_getid_clicked();

        void on_UpdateQuantity_clicked();

        void on_ADD_supp_clicked();

        void on_Delete_sup_clicked();

        void on_Modifier_Nom_sup_clicked();





        void on_ADD_supp_4_clicked();

        void on_UpdateQuantity_2_clicked();





        void on_serchsup_textEdited(const QString &arg1);





        void on_serchcom_textEdited(const QString &arg1);



        void on_RecuCommande_clicked();

        void on_AddCommande_clicked();

        void on_SupprimerCommande_clicked();

        void on_gestioncommande_clicked();

        void on_modifieaupanier_clicked();

        void on_modifieaupanier_2_clicked();

        void on_modifieaupanier_3_clicked();


        void on_pb_login_3_clicked();

        void on_sup_3_clicked();

        void on_chat_3_clicked();

        void on_chat_4_clicked();

        void on_pushButton_7_clicked();

        void on_chat_5_clicked();

        void on_pushButton_11_clicked();

        void on_imprimerim_2_clicked();

        void on_pushButton_12_clicked();

        void on_QRcodecom_clicked();

        void on_ClientDuMoisBtn_clicked();

        void on_exit_clicked();

private:
    Ui::restaurant *ui;
     Plats P;
     Menu M;
     QMediaPlayer* player;
     Employe tmpemploye;
     Equipement tmpequipement;
     Employe session;
     Produits tmpproduit;
     Fournisseur tmpfournisseur;
     livraisons tmplivraisons;
         Vehicule tmpv;
         Panier panier;
         QString cin_recu="";
         QString tmp_recue="";
         bool tmp_verif=false;

         int num_entree=0;


         QByteArray  data; // variable contenant les données reçues
     QString input_password="";
         Arduino A; // objet temporaire
 QStringList files;
 client tmpC;
 carte_fidelite tmpCarte;
 Commande x;
 void showEventHelper();
 QTimer *timer_1s;
 void RefreshTables();
 supplement t;

};
#endif // RESTAURANT_H
