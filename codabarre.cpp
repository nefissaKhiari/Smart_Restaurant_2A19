#include "codabarre.h"
#ifndef MYDIALOG_H
#define MYDIALOG_H
#include <QtGui>
class GenerateurCodeBarre;
class MyDialog : public QDialog
{
Q_OBJECT
public:
MyDialog( QWidget *parent = 0 );
private:
QLineEdit *codebarre;
QLabel *valeur;
//QPushButton *bGenerer;
//QPushButton *bImprimer;
//QPushButton *bQuitter;
GenerateurCodeBarre *generateurCodeBarre;
QIntValidator *intValidator;
private slots:
void generer();
void imprimer();
};
#endif
codabarre::codabarre()
{

}
