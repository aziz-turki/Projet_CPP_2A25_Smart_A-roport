#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "emplacement.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QSqlQueryModel>
#include <QApplication>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->le_num->setValidator(new QIntValidator(100, 99999, this));
    ui->tab_empl->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbajouter_clicked()
{
    int num=ui->le_num->text().toInt();
    QString nom=ui->le_nom->text();
    int dimension=ui->la_dimension->text().toInt();
     QString reservation=ui->la_reservation->text();
            QString liberation=ui->la_liberation->text();
     Emplacement E(num,nom,dimension,reservation,liberation);
     bool test=E.ajouter();
     QMessageBox msg;
     if(test)
       { msg.setText("ajout effectue");}
     else {msg.setText("Echeb d'ajout");}
     msg.exec();}

void MainWindow::on_pbsupp_clicked()
{
    Emplacement E1; E1.setnum(ui->lenumsupp->text().toInt());
    bool test=E1.supprimer(E1.getnum());
    QMessageBox msgBOX;
                if(test)
                    msgBOX.setText("suppression avec succes");
                else msgBOX.setText("Echec de suppression");
                msgBOX.exec();


}



//void MainWindow::on_pbmodifier_clicked()
//{
   // int num= ui->nouvnum->text().toInt();
     //  QString nom=ui->nouvnom->text();
//}






void MainWindow::on_pbafficher_clicked()
{
    ui->tab_empl->setModel(E.afficher());
}

void MainWindow::on_pb_miseajour_clicked()
{
    int num=ui->lenouv_num->text().toInt();
       QString nom=ui->lenouv_nom->text();
       int dimension=ui->lanouv_dim->text().toInt();
       QString reservation=ui->lanouv_reser->text();
       QString liberation=ui->lanouv_lib->text();

       Emplacement E(num,nom,dimension,reservation,liberation);

       bool test=E.modifier(E.getnum(),E.getnom(),E.getdimension(),E.getreservation(),E.getliberation());

       QMessageBox msgBox;

       if(test)
           {
               msgBox.setText("Modification avec succes.");
               ui->tab_empl->setModel(E.afficher());
           }
       else
           msgBox.setText("Echec de Modification!!!!!!");
           msgBox.exec();

}
