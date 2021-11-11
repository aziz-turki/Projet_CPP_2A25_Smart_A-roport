#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QApplication>

#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_Num_Tel->setValidator(new QIntValidator(0, 99999999, this));
 }

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_Ajouter_clicked()
{
    int CIN=ui->lineEdit_CIN->text().toInt(); //convertir en entier
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    QString sexe=ui->lineEdit_Sexe->text();
    QString date_naissance=ui->lineEdit_Date_Naissance->text();
    int num_tel=ui->lineEdit_Num_Tel->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString adress=ui->lineEdit_Adress->text();

    Employe E(CIN,nom,prenom,sexe,date_naissance,num_tel,email,adress);

        bool test=E.ajouterEmploye();
             if(test)
              {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                            QObject::tr("ajout successful.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                             ui->table_employe->setModel(E.afficherEmploye());


              }
                            else
                                QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                            QObject::tr("ajout failed.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
}




/******************************************************************************************************************/



void MainWindow::on_pushButton_Afficher_clicked()
{
    ui->table_employe->setModel(E.afficherEmploye());

}




/******************************************************************************************************************/




void MainWindow::on_pushButton_Supprimer_clicked()
{
    Employe E1;
    E1.setCIN(ui->lineEdit_CIN->text().toInt());
    bool test=E1.supprimerEmploye(E1.getCIN());

    QMessageBox msgBox;

    if(test)
        {
            msgBox.setText("Suppression avec succes.");
            ui->table_employe->setModel(E.afficherEmploye());
        }
    else
        msgBox.setText("Echec de suppression!!!!!");
        msgBox.exec();
}




/******************************************************************************************************************/




void MainWindow::on_pushButton_MIseAJour_clicked()
{
    int CIN=ui->lineEdit_CIN->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    QString sexe=ui->lineEdit_Sexe->text();
    QString date_naissance=ui->lineEdit_Date_Naissance->text();
    int num_tel=ui->lineEdit_Num_Tel->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString adress=ui->lineEdit_Adress->text();

    Employe E(CIN,nom,prenom,sexe,date_naissance,num_tel,email,adress);

    bool test=E.modifierEmploye(E.getCIN(),E.getnom(),E.getprenom(),E.getsexe(),E.getdate_naissance(),E.getnum_tel(),E.getemail(),E.getadress());

    QMessageBox msgBox;

    if(test)
        {
            msgBox.setText("Modification avec succes.");
            ui->table_employe->setModel(E.afficherEmploye());
        }
    else
        msgBox.setText("Echec de Modification!!!!!!");
        msgBox.exec();

}



/**********************************************************************************************************************/



void MainWindow::on_pushButton_Recherche_clicked()
{

E.setCIN(ui->lineEdit_CIN->text().toInt());
ui->table_employe->setModel(E.RechercheEmploye(E.getCIN()));

ui->lineEdit_CIN->clear();
ui->lineEdit_Nom->clear();
ui->lineEdit_Prenom->clear();
ui->lineEdit_Sexe->clear();
ui->lineEdit_Date_Naissance->clear();
ui->lineEdit_Num_Tel->clear();
ui->lineEdit_Email->clear();
ui->lineEdit_Adress->clear();

}



/**********************************************************************************************************************/



void MainWindow::on_pushButton_Trier_clicked()
{
    if(E.trierEmploye())
    {
        ui->table_employe->setModel(E.trierEmploye());

    }
}



/**********************************************************************************************************************/



void MainWindow::on_pushButton_PDF_clicked()
{
    QPdfWriter pdf("C:\\Utilisateurs\\21698\\Bureau\\PDF_Projet\\pdfemploye.pdf");

                           QPainter painter(&pdf);
                           int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Time New Roman", 25));
                                  painter.drawText(950,1400,"Liste Des Employes");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Time New Roman", 15));
                                  painter.drawRect(100,100,8000,2000); // dimension ta3 rectangle eli fih liste des animaux
                                  painter.drawRect(0,3000,8000,500);
                                  painter.setFont(QFont("Time New Roman", 9));
                                  painter.drawText(500,3300,"CIN : ");
                                  painter.drawText(1600,3300,"Nom : ");
                                  painter.drawText(2400,3300,"Prenom : ");
                                  painter.drawText(3700,3300,"Sexe : ");
                                  painter.drawText(4700,3300,"Date de Naissance : ");
                                  painter.drawText(5700,3300,"Numero de Telephone");
                                  painter.drawText(6700,3300,"Email");
                                  painter.drawText(6700,3300,"Adress");
                                  painter.drawRect(0,3000,8000,9000);

                                  QSqlQuery query;
                                  query.prepare("select * from EMPLOYE");
                                  query.exec();
                                  while (query.next())
                                  {
                                      painter.drawText(500,i,query.value(0).toString());
                                      painter.drawText(1650,i,query.value(1).toString());
                                      painter.drawText(2450,i,query.value(2).toString());
                                      painter.drawText(3750,i,query.value(3).toString());
                                      painter.drawText(4750,i,query.value(4).toString());
                                      painter.drawText(5750,i,query.value(5).toString());
                                      painter.drawText(6750,i,query.value(6).toString());



                                     i = i + 500;
        }
                                  QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



/**********************************************************************************************************************/





