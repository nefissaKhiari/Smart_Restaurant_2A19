#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QWidget>

namespace Ui {
class Statistiques;
}

class Statistiques : public QWidget
{
    Q_OBJECT

public:
    explicit Statistiques(QWidget *parent = nullptr);
    ~Statistiques();

private:
    Ui::Statistiques *ui1;
};

#endif // STATISTIQUES_H
