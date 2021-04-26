#include "gestionplatsmenu.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
      QTranslator guiTranslator;
     QStringList languages;
     languages <<"French"<<"English";
     QString lang=QInputDialog::getItem(NULL,"Select Language","Language",languages);
     if (lang=="english")
 {     t.load("/english.ts");

     }
     if (lang !="french"){
       a.installTranslator(&t);
       a.installTranslator(&guiTranslator);
     }


    Connection c;
    bool test=c.createconnect();
    Gestionplatsmenu w;

    if(test){
        w.show();
        QMessageBox::information(nullptr, QObject::tr("base de données ouvert "),
                    QObject::tr("connexion réussir.\n"
                                "cliquer annuler pour quitter."), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connexion non réussi.\n"
                                "cliquer annuler pour quitter."), QMessageBox::Cancel);
    }
    return a.exec();
}
