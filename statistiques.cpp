#include "statistiques.h"
#include "ui_statistiques.h"

Statistiques::Statistiques(QWidget *parent) :
    QWidget(parent),
    ui1(new Ui::Statistiques)
{
    ui1->setupUi(this);
}

Statistiques::~Statistiques()
{
    delete ui1;
}
