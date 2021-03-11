#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
#include<QString>
#include<QSqlQueryModel>

class carte_fidelite
{
    QString  numero;
    QString ID;
    QString date_creation;
    QString nb_points;

public:
    carte_fidelite();
};

#endif // CARTE_FIDELITE_H
