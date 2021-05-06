#include "employe.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include "src/SmtpMime"
Employe::Employe()
{
id=0;
nom="";
prenom="";
adresse="";
telephone=0;
}

Employe::Employe(int id  ,QString nom, QString prenom, QString adresse,int telephone)
{this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->telephone=telephone;}
int Employe::getid(){return id;}
QString Employe:: getnom(){return nom;}
QString Employe::getprenom() {return prenom;}
QString Employe::getadresse(){return adresse;}
int Employe::gettelephone(){return telephone;}
void Employe::setid(int id) {this->id=id;}
void Employe::setnom(QString nom){this->nom;}
void Employe::setprenom(QString prenom){this->prenom;}
void Employe::setadresse(QString adresse){this->adresse;}
void Employe::settelephone(int telephone){this->telephone;}
bool Employe::ajouter()
{
    QSqlQuery query;
        query.prepare("INSERT INTO employe (id,nom,prenom,adresse,telephone) VALUES (:id,:nom,:prenom,:adresse,:telephone)");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":telephone",telephone);
        if( query.exec() ) {
            Historique("Employe "+nom+" "+prenom+" Ajouter");
            return true;
        }
        return false;
}
bool Employe::supprimer(int id )
{
    QSqlQuery query__;
        query__.prepare("select nom, prenom, adresse, telephone from employe where id = ? ");
        query__.addBindValue(QString::number(id));
        query__.exec();
        while (query__.next()) {
            QSqlQuery query_____;
            query_____.prepare("INSERT INTO ARCHIVE_EMPLOYE (id,nom,prenom,adresse,telephone) VALUES (:id,:nom,:prenom,:adresse,:telephone)");
            query_____.bindValue(":id",id);
            query_____.bindValue(":nom",query__.value(0).toString());
            query_____.bindValue(":prenom",query__.value(1).toString());
            query_____.bindValue(":adresse",query__.value(2).toString());
            query_____.bindValue(":telephone",query__.value(3).toString());
            query_____.exec();
            Historique(" Employe "+query__.value(0).toString()+" "+query__.value(1).toString()+" Archiver");
        }
        QSqlQuery query;
        query.prepare("delete from employe where id = :id") ;

        query.bindValue(":id",id);

        return query.exec();
}
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM EMPLOYE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
    return model;
}

bool Employe::modifier(int id)
{
    QSqlQuery query;
        query.prepare("UPDATE employe SET nom =:nom,prenom =:prenom,adresse =:adresse,telephone =:telephone  WHERE id=:id ");
        query.bindValue(":id",id);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":telephone",telephone);


        if( query.exec() ) {
            Historique("Employe "+nom+" "+prenom+" Modifier");
            return true;
        }
        return false;
}

QSqlQueryModel * Employe::Find_Employe()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,prenom,adresse,telephone FROM employe");

    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * Employe::rechercher(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from employe where id like '%"+search+"%' or nom like '%"+search+"%' or prenom like '%"+search+"%' or adresse like '%"+search+"%' or telephone like '%"+search+"%'";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel * Employe::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY id");
    return model;

}

bool Employe::login(QString __l, QString __p)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users");

    query.exec();
    while(query.next()) {
        if(query.value(1).toString() == __l && query.value(2).toString() == __p) {
            int id_e = query.value(3).toInt();
            QSqlQuery query1;
            query1.exec("SELECT * FROM employe WHERE id = "+QString::number(id_e));
            while(query1.next()) {
                this->id = query1.value(0).toInt();
                this->nom = query1.value(1).toString();
                this->prenom = query1.value(2).toString();
                this->adresse = query1.value(3).toString();
                this->telephone = query1.value(4).toInt();
            }
            return true;
        }
    }
    return false;
}

bool Employe::oublieMDP(QString __l)
{
    QSqlQuery query;
       query.prepare("SELECT email, password FROM users where login = ?");
       query.addBindValue(__l);
       query.exec();
       QString email, password;
       bool rtn = false;
       while(query.next()) {
           email = query.value(0).toString();
           password = query.value(1).toString();
           rtn = true;
       }
       if( rtn ) {
           SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

           smtp.setUser("farah.hasnaoui22@gmail.com");
           smtp.setPassword("kenzafarah");

           MimeMessage message;

           EmailAddress sender("farah.hasnaoui22@gmail.com", "Admin");
           message.setSender(&sender);

           EmailAddress to(email, __l);
           message.addRecipient(&to);

           message.setSubject(" Mot de passe oublie! ");

           MimeText text;
           text.setText(" login: "+__l+" \r password: "+password);

           message.addPart(&text);

               if (!smtp.connectToHost()) {
                   qDebug() << "Failed to connect to host!" << endl;
               }

               if (!smtp.login()) {
                   qDebug() << "Failed to login!" << endl;
               }

               if (!smtp.sendMail(message)) {
                   qDebug() << "Failed to send mail!" << endl;
               }

           smtp.quit();
       }
       return rtn;
}

bool Employe::restoration(int id)
{
    QSqlQuery query__;
        query__.prepare("select nom, prenom, adresse, telephone from ARCHIVE_EMPLOYE where id = ? ");
        query__.addBindValue(QString::number(id));
        query__.exec();
        while (query__.next()) {
            QSqlQuery query_____;
            query_____.prepare("INSERT INTO employe (id,nom,prenom,adresse,telephone) VALUES (:id,:nom,:prenom,:adresse,:telephone)");
            query_____.bindValue(":id",id);
            query_____.bindValue(":nom",query__.value(0).toString());
            query_____.bindValue(":prenom",query__.value(1).toString());
            query_____.bindValue(":adresse",query__.value(2).toString());
            query_____.bindValue(":telephone",query__.value(3).toString());
            query_____.exec();
            Historique(" Employe "+query__.value(0).toString()+" "+query__.value(1).toString()+" Restaurer");

        }
        QSqlQuery query;
        query.prepare("delete from ARCHIVE_EMPLOYE where id = :id") ;

        query.bindValue(":id",id);

        return query.exec();
}

QSqlQueryModel * Employe::archive()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ARCHIVE_EMPLOYE ORDER BY id");
    return model;

}

bool Employe::Historique(QString active)
{
    QSqlQuery query;
    query.prepare("INSERT INTO historique (active,time) VALUES (:active,:time)");
    query.bindValue(":active",active);
    query.bindValue(":time",QDateTime::currentDateTime().toString());
    return query.exec();
}

void Employe::showHistorique(QPlainTextEdit * __p)
{
    QSqlQuery query;
    __p->clear();
    query.exec("SELECT active, time from historique order by id");
    while (query.next()) {
        __p->insertPlainText(""+query.value(1).toString()+" : "+query.value(0).toString()+"\r");
    }
}
