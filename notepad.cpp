#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
notepad::notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

notepad::~notepad()
{
    delete ui;
}


void notepad::on_actionNew_triggered()
{
    file_path_ ="";
    ui->textEdit->setText("");

}

void notepad::on_actionopen_triggered()
{
QString file_name =QFileDialog::getOpenFileName(this,"open the file");
QFile file(file_name);
file_path_ = file_name;
if(!file.open(QFile::ReadOnly | QFile::Text))
{
    QMessageBox:: warning(this,"..","file not open");
   return;
}
 QTextStream in (&file);
 QString text= in.readAll();
 ui->textEdit->setText(text);
 file.close();

}

void notepad::on_actionsave_triggered()
{
    QFile file(file_path_);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox:: warning(this,"..","file not open");
       return;
    }
     QTextStream out (&file);
     QString text= ui->textEdit->toPlainText();

     out <<text;

     file.flush();
     file.close();

}

void notepad::on_actionSave_AS_triggered()
{
    QString file_name =QFileDialog::getSaveFileName(this,"open the file");
    QFile file(file_name);
    file_path_ = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox:: warning(this,"..","file not open");
       return;
    }
     QTextStream out (&file);
     QString text= ui->textEdit->toPlainText();

     out <<text;

     file.flush();
     file.close();
}

void notepad::on_actioncut_triggered()
{
    ui->textEdit->cut();
}

void notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void notepad::on_actionRedo_triggered()
{
   ui->textEdit->redo();
}

void notepad::on_actionUndo_triggered()
{
     ui->textEdit->undo();
}

void notepad::on_actionabout_notepad_triggered()
{
    QString about_text;
    about_text ="Auther : somebody";
    about_text +="Date : 19/05/2020";
      about_text +="(c)  Notepad (R)";

   QMessageBox::about(this,"About notepad",about_text);
}
