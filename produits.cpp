#include "produits.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
Produits::Produits()
{
id=0;
nom_produit="";
categorie="";
prix=0;
}

Produits::Produits(int id  ,QString nom_produit,QString categorie,double prix)
{this->id=id;
    this->nom_produit=nom_produit;
    this->categorie=categorie;
    this->prix=prix;}
int Produits::getid(){return id;}
QString Produits:: getnom_produit(){return nom_produit;}
QString Produits::getcategorie() {return categorie;}
double Produits::getprix(){return prix;}
void Produits::setid(int id) {this->id=id;}
void Produits::setnom(QString nom_produit){this->nom_produit;}
void Produits::setcategorie(QString categorie){this->categorie;}
void Produits::setprix(double prix){this->prix;}
bool Produits::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO produits (id,nom_produit,categorie,prix) VALUES (:id,:nom_produit,:categorie,:prix)");
    query.bindValue(":id",id);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    return query.exec();
}
bool Produits::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from produits where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* Produits::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM PRODUITS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom produits"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("categorie"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool Produits::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE produits SET id= :id,nom_produit = :nom_produit,categorie = :categorie,prix = :prix  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":nom_produit",nom_produit);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",prix);
    return    query.exec();
}

void Produits::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
   // QCPBars *regen = new QCPBars(customPlot->xAxis, customPlot->yAxis);
   // QCPBars *nuclear = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  //  regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
  //  nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
  //  regen->setStackingGap(1);
    //nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Produit");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
  //  nuclear->setName("Nuclear");
  //  nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  //  nuclear->setBrush(QColor(250, 170, 20));
   // regen->setName("Regenerative");
  //  regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  //  regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
  //  nuclear->moveAbove(fossil);
 //   regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(DISTINCT id) FROM produits where prix between 0 and 10");
    query.exec();
    int un;
    while(query.next())
    {
        un=query.value(0).toInt();
        qDebug()<<un;
    }
    query.prepare("SELECT COUNT(DISTINCT id) FROM produits where prix between 10 and 100");
    query.exec();
    int deux;
    while(query.next())
    {
        deux=query.value(0).toInt();
    }

    query.prepare("SELECT COUNT(DISTINCT id) FROM produits where prix between 100 and 1000");
    query.exec();
    int trois;
    while(query.next())
    {
        trois=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 ;
    labels << "[0,10]" << "[11,100]" << "[101,1000]" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nombre de produits");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << un << deux << trois;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
  //  nuclear->setData(ticks, nuclearData);
 //   regen->setData(ticks, regenData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

