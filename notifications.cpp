#include "notifications.h"
#include <QSystemTrayIcon>
#include<QString>
Notifications::Notifications()
{

}

void Notifications::notifications_ajouterplat()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Home/Documents/gestionplats-menu/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des plats ","Nouveau plat ajouté ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_ajoutermenu()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

     notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des menus ","Nouveau menu ajouté ",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_supprimerplat(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des plat ","plat Supprimé",QSystemTrayIcon::Information,15000);
}
void Notifications::notifications_supprimermenu(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des menu ","Un menu est supprimé",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_modifierplat(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des plats ","Un plat est modifié",QSystemTrayIcon::Information,15000);

}
void Notifications::notifications_modifiermenu(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/User/Desktop/images/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des menus ","Un menu est modifié",QSystemTrayIcon::Information,15000);

}
