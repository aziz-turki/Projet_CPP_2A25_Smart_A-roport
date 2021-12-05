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
#include<QPixmap>
#include <QFile>
#include<iostream>
#include<QTextStream>
#include<fstream>
#include<QDebug>
#include <QDateTime>
#include<iostream>
#include<QCoreApplication>
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
       {

         msg.setText("ajout effectue");}
     else {
         msg.setText("Echeb d'ajout");}


     msg.exec();



     QString nomFile ="Historique";
          QFile file("C:/Users/USER/Desktop/Atelier_Connexion/"+nomFile+".txt");
          QString finalmsg="fichier modifie avec succes";
           if(!file.exists()){
           finalmsg="fichier cree avec succes";
           }
          file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



          QTextStream txt(&file);
            QString d_info = QDateTime::currentDateTime().toString();

          QString message2=d_info+" - Un Emplacement a été ajoutée avec le nom "+ nom +"\n";
          txt << message2;
     ui->le_num->clear();
     ui->le_nom->clear();
     ui->la_dimension->clear();
     ui->la_reservation->clear();
     ui->la_liberation->clear();













}

void MainWindow::on_pbsupp_clicked()
{
    Emplacement E1; E1.setnum(ui->lenumsupp->text().toInt());
     QString nom =E1.getnom();
   bool test=E1.supprimer(E1.getnum());
    QMessageBox msgBOX;
                if(test)
                    msgBOX.setText("suppression avec succes");
                else msgBOX.setText("Echec de suppression");



               msgBOX.exec();
               QString nomFile ="Historique";
                    QFile file("C:/Users/USER/Desktop/Atelier_Connexion/"+nomFile+".txt");
                    QString finalmsg="fichier modifie avec succes";
                     if(!file.exists()){
                     finalmsg="fichier cree avec succes";
                     }
                    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                    QTextStream txt(&file);
                      QString d_info = QDateTime::currentDateTime().toString();

                    QString message2=d_info+" - Un Emplacement a été suprimmé avec le nom "+ nom +"\n";
                    txt << message2;

}











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

       if((num==0),(nom==""),(dimension==0),(reservation==""),(liberation==""))
        {  msgBox.setText("Echec de Modification!!!!!!");}
       else

       {
                   msgBox.setText("Modification avec succes.");
                   ui->tab_empl->setModel(E.afficher());
               }
           msgBox.exec();
           QString nomFile ="Historique";
                QFile file("C:/Users/USER/Desktop/Atelier_Connexion/"+nomFile+".txt");
                QString finalmsg="fichier modifie avec succes";
                 if(!file.exists()){
                 finalmsg="fichier cree avec succes";
                 }
                file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                QTextStream txt(&file);
                  QString d_info = QDateTime::currentDateTime().toString();

                QString message2=d_info+" - Un Emplacement a été modifié avec le nom "+ nom +"\n";
                txt << message2;
           ui->lenouv_num->clear();
           ui->lenouv_nom->clear();
           ui->lanouv_dim->clear();
           ui->lanouv_lib->clear();
           ui->lanouv_reser->clear();


}





void MainWindow::on_Fichier_clicked()
{
    QString nomFile="fichier excel ";
        QMessageBox msg;
        if(!nomFile.length()){

            msg.setText("entrer le nom du fichier");
            msg.exec();
        }
        else{
        QFile file("C:/Users/USER/Desktop/Atelier_Connexion/"+nomFile+".csv");
        QString finalmsg="fichier modifie avec succes";
         if(!file.exists()){
         finalmsg="fichier cree avec succes";
         }
        file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
;



        QTextStream txt(&file);
        txt<<"Numéro \t\t  Nom    \t Dimension   \t\t  Reservation  \t\t     Liberation      \n";

        for(int i=0;i<5;i++){

        QString num= ui->tab_empl->model()->index(i,0).data().toString();
        QString nom= ui->tab_empl->model()->index(i,1).data().toString();
        QString dimension= ui->tab_empl->model()->index(i,2).data().toString();
        QString reservation= ui->tab_empl->model()->index(i,3).data().toString();
        QString liberation= ui->tab_empl->model()->index(i,4).data().toString();

        if(num.length()){

        txt<< "'"+ num +"' \t";
        txt<< "'"+ nom +"' \t";
        txt<< "'"+ dimension +"' \t";
        txt<< "'"+ reservation +"' \t";
        txt<< "'"+ liberation +"' \n\n";
        }
        }
        msg.setText(finalmsg);
        msg.exec();
        file.close();
        }
}







void MainWindow::on_recherche_textEdited()
{
    QString rech=ui->recherche->text();
         ui->tab_rech->setModel(E.chercheEmplacement(rech));


}



void MainWindow::on_comboBoxA_activated()

    {
        {
            if(ui->comboBoxA->currentText()=="Tri par dimension")
            {
                ui->tab_empl->setModel(E.triEmplacementParDimension());

            }else if(ui->comboBoxA->currentText()=="Tri par nom")
            {
                ui->tab_empl->setModel(E.triEmplacementParNom());

            }else
            {

                ui->tab_empl->setModel(E.triEmplacementParNum());
            }
        }
    }

