#include "statistique.h"
#include "ui_statistique.h"

statistique::statistique(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::statistique)
{
    ui->setupUi(this);
}

statistique::~statistique()
{
    delete ui;
}
