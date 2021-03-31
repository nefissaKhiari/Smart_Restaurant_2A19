#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "equipements.h"
#include "interface.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabemploye->setModel(tmpemploye.afficher());

    ui->tabequipement->setModel(tmpequipement.afficher());



}

MainWindow::~MainWindow()
{
    delete ui;

}

//COMBOBOX
void MainWindow::on_tabWidget_currentChanged(int )
{
   { ui->tabemploye->setModel(tmpemploye.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM EMPLOYE");
    ui->idsup->setModel(model);
    ui->idmodifier->setModel(model);

    ui->tabequipement->setModel(tmpequipement.afficher());
    QSqlQueryModel * model1= new QSqlQueryModel();
    model1->setQuery("SELECT ID_EQUIPEMENT FROM Equipement");
    ui->ideqsup->setModel(model1);
    ui->ideqmodif->setModel(model1);
    }

}










void MainWindow::on_ajout_clicked()
{
    int id=ui->idajout->text().toInt();
        QString nom=ui->nomajout->text();
        QString prenom=ui->prenomajout->text();
        QString adresse=ui->adresseajout->text();
        int telephone=ui->telephoneajout->text().toInt();

        Employe tmpemploye(id,nom,prenom,adresse,telephone);
        bool test=tmpemploye.ajouter();
        if(test){
            ui->tabemploye->setModel(tmpemploye.afficher());
            QMessageBox::information(nullptr,"Ajout employe","employe ajouté avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","employe non ajouté");
}

void MainWindow::on_sup_clicked()
{

    int id=ui->idsup->currentText().toInt();
    bool test=tmpemploye.supprimer(id);
    if(test){
        ui->tabemploye->setModel(tmpemploye.afficher());
        QMessageBox::information(nullptr,"suppression employe","employe supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","employe non supprimer");

}








void MainWindow::on_ajouteq_clicked()
{
    int id_equipement=ui->ideqajout->text().toInt();
        QString materiel=ui->matajout->text();
        QString poste=ui->postajout->text();
        int id_employee=ui->idempajout->text().toInt();
        Equipement tmpequipement(id_equipement,materiel,poste,id_employee);
        bool test=tmpequipement.ajouter();
        if(test){
            ui->tabequipement->setModel(tmpequipement.afficher());
            QMessageBox::information(nullptr,"Ajout equipement","equipement ajouté avec succés");
        }
        else
                QMessageBox::warning(nullptr,"Error","equipement non ajouté");
}

void MainWindow::on_supeq_clicked()
{
    int id_equipement=ui->ideqsup->currentText().toInt();
    bool test=tmpequipement.supprimer(id_equipement);
    if(test){
        ui->tabequipement->setModel(tmpequipement.afficher());
        QMessageBox::information(nullptr,"suppression equipement","equipement supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","equipement non supprimer");

}
void MainWindow::on_modifier_clicked()
{
    int id=ui->idmodifier->currentText().toInt();
    QString nom=ui->nommodifier->text();
    QString prenom=ui->prenommodifier->text();
    QString adresse=ui->adressemodifier->text();
    int telephone=ui->telmodifier->text().toInt();
    Employe tmpemploye(id,nom,prenom,adresse,telephone);
    bool test=tmpemploye.modifier(id);
    if(test){
        ui->tabemploye->setModel(tmpemploye.afficher());

        QMessageBox::information(nullptr,"modification employe","employe modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","employe non modifie");

    }


void MainWindow::on_modifeq_clicked()
{
    int id_equipement=ui->ideqmodif->currentText().toInt();
    QString materiel=ui->matmodif->text();
    QString poste=ui->postmodif->text();
    int id_employee=ui->idempmodif->text().toInt();
    Equipement e(id_equipement,materiel,poste,id_employee);
    bool test=e.modifier(id_equipement);
    if(test){
        ui->tabequipement->setModel(tmpequipement.afficher());

        QMessageBox::information(nullptr,"modification equipement","equipement modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","equipement non modifie");
}

void MainWindow::on_supprimer_currentChanged(int )
{
    ui->tabemploye->setModel(tmpemploye.afficher());
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT ID FROM EMPLOYE");
        ui->idsup->setModel(model);
        ui->idmodifier->setModel(model);

        ui->tabequipement->setModel(tmpequipement.afficher());
        QSqlQueryModel * model1= new QSqlQueryModel();
        model1->setQuery("SELECT ID_EQUIPEMENT FROM Equipement");
        ui->ideqsup->setModel(model1);
        ui->ideqmodif->setModel(model1);
        QFile file("messenger.txt");
        if(!file.open(QIODevice::ReadOnly));
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
        file.close();
        QScrollBar *sb = ui->textBrowser->verticalScrollBar();
        sb->setValue(sb->maximum());

}

void MainWindow::on_pushButton_3_clicked()
{

    QString msg= ui->messageline->text();
    ui->messageline->clear();
    QFile file("messenger.txt");
    file.close();
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream out(&file);
        out << "<User> "<< msg<<" - "<< QDateTime::currentDateTime().toString("dd/MM/yyyy h:mm ap") <<"\n";
        file.close();
    }
    if(!file.open(QIODevice::ReadOnly));
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    file.close();
    QScrollBar *sb = ui->textBrowser->verticalScrollBar();
    sb->setValue(sb->maximum());
}

void MainWindow::on_Excel_clicked()
{
    Employe E;
           QSqlQueryModel * model=new QSqlQueryModel();
           model=E.Find_Employe();
           QString textData= "id ; nom ; prenom ; adresse ; telephone \n";
           int rows=model->rowCount();
           int columns=model->columnCount();
           for (int i = 0; i < rows; i++)
           {
               for (int j = 0; j < columns; j++)
               {
                   textData += model->data(model->index(i,j)).toString();
                   textData +=" ; ";
               }
               textData += "\n";
           }
           QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
           if (!fileName.isEmpty())
               if (QFileInfo(fileName).suffix().isEmpty())
                   fileName.append(".csv");
           QFile csvfile(fileName);
           if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
           {
               QTextStream out(&csvfile);
               out<<textData;
           }
           csvfile.close();
}

void MainWindow::on_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabemploye->model()->rowCount();
                const int columnCount = ui->tabemploye->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>Employes LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ****LISTE DES Employes **** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabemploye->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabemploye->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabemploye->isColumnHidden(column)) {
                            QString data =ui->tabemploye->model()->data(ui->tabemploye->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *test = new QPrintDialog(&printer, NULL);
                if (test->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
   Employe e;
   ui->tabemploye->setModel(e.rechercher(ui->lineEdit->text()));
}

void MainWindow::on_trier_clicked()
{
    ui->tabemploye->setModel(tmpemploye.tri());
}
