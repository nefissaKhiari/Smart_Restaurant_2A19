#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H


#include <QSystemTrayIcon>
#include<QString>
class Notifications
{
public:
    Notifications();
    void notifications_ajouterplat();
    void notifications_ajoutermenu();
    void notifications_supprimerplat();
    void notifications_supprimermenu();
    void notifications_modifierplat();
    void notifications_modifiermenu();

};

#endif // NOTIFICATIONS_H
