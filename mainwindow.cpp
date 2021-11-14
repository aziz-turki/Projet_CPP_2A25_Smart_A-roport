#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QApplication>
#include <QPixmap>

#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap pic("C:/Users/21698/Desktop/photo_Qt");
    ui->label_photo->setPixmap(pic);
    ui->lineEdit_CIN->setValidator(new QIntValidator(100, 99999999, this));
    ui->lineEdit_Num_Tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_Nom->setMaxLength(8);
    ui->lineEdit_Prenom->setMaxLength(8);
    ui->lineEdit_Date_Naissance->setMaxLength(8);
    ui->lineEdit_Email->setMaxLength(8);
    ui->lineEdit_Adress->setMaxLength(8);
 }

MainWindow::~MainWindow()
{
    delete ui;
}




/******************************************************************************************************************/




void MainWindow::on_pushButton_Ajouter_clicked()
{
    int CIN=ui->lineEdit_CIN->text().toInt(); //convertir en entier
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    QString sexe=ui->comboBox_Sexe->currentText();
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

             ui->lineEdit_CIN->clear();
             ui->lineEdit_Nom->clear();
             ui->lineEdit_Prenom->clear();
             ui->comboBox_Sexe->clear();
             ui->lineEdit_Date_Naissance->clear();
             ui->lineEdit_Num_Tel->clear();
             ui->lineEdit_Email->clear();
             ui->lineEdit_Adress->clear();

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
    if (ui->lineEdit_CIN->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                           QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
    }
    else if (test)
    {
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                           QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->table_employe->setModel(E.afficherEmploye());
    }
    ui->lineEdit_CIN->clear();
    ui->lineEdit_Nom->clear();
    ui->lineEdit_Prenom->clear();
    ui->comboBox_Sexe->clear();
    ui->lineEdit_Date_Naissance->clear();
    ui->lineEdit_Num_Tel->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_Adress->clear();
}



/**********************************************************************************************************************/




void MainWindow::on_pushButton_Reset_clicked()
{
    Employe E1;
    bool test=E1.supprimerTout();
    QMessageBox msgBox;
         if(test)
          {    QMessageBox::information(nullptr, QObject::tr("Reset avec succes"),
                                        QObject::tr("Reset successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                         ui->table_employe->setModel(E.afficherEmploye());
          }
                        else
                            QMessageBox::critical(nullptr, QObject::tr("Reset errer"),
                                        QObject::tr("Reset failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
}




/******************************************************************************************************************/




void MainWindow::on_pushButton_MIseAJour_clicked()
{
    int CIN=ui->lineEdit_CIN->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    QString sexe=ui->comboBox_Sexe->currentText();
    QString date_naissance=ui->lineEdit_Date_Naissance->text();
    int num_tel=ui->lineEdit_Num_Tel->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString adress=ui->lineEdit_Adress->text();

    Employe E(CIN,nom,prenom,sexe,date_naissance,num_tel,email,adress);

    bool test=E.modifierEmploye(E.getCIN(),E.getnom(),E.getprenom(),E.getsexe(),E.getdate_naissance(),E.getnum_tel(),E.getemail(),E.getadress());

    QMessageBox msgBox;

    if ((ui->lineEdit_CIN->text()==0),(ui->lineEdit_Nom->text()==""),(ui->lineEdit_Prenom->text()==""),(ui->comboBox_Sexe->currentText()==""),(ui->lineEdit_Date_Naissance->text()==""),(ui->lineEdit_Num_Tel->text()==0),(ui->lineEdit_Email->text()==""),(ui->lineEdit_Adress->text()==""))
    {
        QMessageBox::critical(this, QObject::tr("Modification Errer"),
                           QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);

    }
    else if(test)
    {
        QMessageBox::information(this, QObject::tr("Modification Succes"),
                           QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
        ui->table_employe->setModel(E.afficherEmploye());

    }
    ui->lineEdit_CIN->clear();
    ui->lineEdit_Nom->clear();
    ui->lineEdit_Prenom->clear();
    ui->comboBox_Sexe->clear();
    ui->lineEdit_Date_Naissance->clear();
    ui->lineEdit_Num_Tel->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_Adress->clear();


}

/***************************************************************Metiers*************************************************************************/

/**********************************************************************************************************************/



void MainWindow::on_pushButton_Recherche_clicked()
{

E.setCIN(ui->lineEdit_CIN->text().toInt());
E.setnom(ui->lineEdit_Nom->text());
E.setprenom(ui->lineEdit_Prenom->text());
ui->table_employe->setModel(E.RechercheEmploye(E.getCIN(),E.getnom(),E.getprenom()));

ui->lineEdit_CIN->clear();
ui->lineEdit_Nom->clear();
ui->lineEdit_Prenom->clear();
ui->comboBox_Sexe->clear();
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
    QPdfWriter pdf("C:\\Users\\21698\\Desktop\\PDF_Projet\\PDF_Employe.pdf");

   QPainter painter(&pdf);
   int i = 4000;
          painter.setPen(Qt::red);
          painter.setFont(QFont("Time New Roman", 25));
          painter.drawText(3000,1400,"Liste Des Employes");
          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,3000,9400,500);
          painter.setFont(QFont("Time New Roman", 9));
          painter.drawText(400,3300,"CIN");
          painter.drawText(1350,3300,"Nom");
          painter.drawText(2200,3300,"Prenom");
          painter.drawText(3400,3300,"Sexe");
          painter.drawText(4400,3300,"Date de Naissance");
          painter.drawText(6200,3300,"Numero de Tel");
          painter.drawText(7600,3300,"Email");
          painter.drawText(8500,3300,"Adress");
          painter.drawRect(100,3000,9400,9000);

          QSqlQuery query;
          query.prepare("select * from EMPLOYE");
          query.exec();
          while (query.next())
          {
              painter.drawText(400,i,query.value(0).toString());
              painter.drawText(1350,i,query.value(1).toString());
              painter.drawText(2300,i,query.value(2).toString());
              painter.drawText(3400,i,query.value(3).toString());
              painter.drawText(4400,i,query.value(4).toString());
              painter.drawText(6200,i,query.value(5).toString());
              painter.drawText(7600,i,query.value(6).toString());
              painter.drawText(8500,i,query.value(7).toString());


             i = i + 350;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



/**********************************************************************************************************************/



void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if (username == "aziz" && password == "esprit123") {
               QMessageBox::information(this, "Login", "Username and password are correct");
            ui->stackedWidget->setCurrentIndex(1);

           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
           ui->lineEdit_username->clear();
           ui->lineEdit_password->clear();
}


