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

#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(0);
    QPixmap pic("C:/Users/21698/Desktop/photo_Employe_Qt");
    ui->label_photo->setPixmap(pic);
    ui->label_photo2->setPixmap(pic);
    ui->lineEdit_CIN->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_Num_Tel->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_Nom->setMaxLength(8);
    ui->lineEdit_Prenom->setMaxLength(8);
    ui->lineEdit_Email->setInputMask("NNNNNNNN.NNNNNNNN@AAAAAA.AAA");
    ui->lineEdit_Adress->setMaxLength(8);
    connect(ui->sendbtn,SIGNAL(clicked()),this,SLOT(sendMail()));
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
    QDate date_naissance=ui->dateEdit_naissance->date();
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
             ui->comboBox_Sexe->setCurrentIndex(0);
             ui->dateEdit_naissance->clear();
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
    ui->comboBox_Sexe->setCurrentIndex(0);
    ui->dateEdit_naissance->clear();
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
    QDate date_naissance=ui->dateEdit_naissance->date();
    int num_tel=ui->lineEdit_Num_Tel->text().toInt();
    QString email=ui->lineEdit_Email->text();
    QString adress=ui->lineEdit_Adress->text();

    Employe E(CIN,nom,prenom,sexe,date_naissance,num_tel,email,adress);

    bool test=E.modifierEmploye(E.getCIN(),E.getnom(),E.getprenom(),E.getsexe(),E.getdate_naissance(),E.getnum_tel(),E.getemail(),E.getadress());

    QMessageBox msgBox;

    if ((ui->lineEdit_CIN->text()==0),(ui->lineEdit_Nom->text()==""),(ui->lineEdit_Prenom->text()==""),(ui->comboBox_Sexe->currentText()==""),(ui->lineEdit_Num_Tel->text()==0),(ui->lineEdit_Email->text()==""),(ui->lineEdit_Adress->text()==""))
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
    ui->comboBox_Sexe->setCurrentIndex(0);
    ui->dateEdit_naissance->clear();
    ui->lineEdit_Num_Tel->clear();
    ui->lineEdit_Email->clear();
    ui->lineEdit_Adress->clear();


}



/***************************************************************Metiers*************************************************************************/
/**********************************************************************************************************************/


/*
void MainWindow::on_pushButton_Recherche_clicked()
{

E.setCIN(ui->lineEdit_CIN->text().toInt());
E.setnom(ui->lineEdit_Nom->text());
E.setprenom(ui->lineEdit_Prenom->text());
ui->table_employe->setModel(E.RechercheEmploye(E.getCIN(),E.getnom(),E.getprenom()));

ui->lineEdit_CIN->clear();
ui->lineEdit_Nom->clear();
ui->lineEdit_Prenom->clear();
ui->comboBox_Sexe->setCurrentIndex(0);
ui->dateEdit_naissance->clear();
ui->lineEdit_Num_Tel->clear();
ui->lineEdit_Email->clear();
ui->lineEdit_Adress->clear();
}
*/

void MainWindow::on_lineEdit_recherche_textChanged()
{
    QString rech=ui->lineEdit_recherche->text();
    ui->table_employe->setModel(E.RechercheEmploye(rech));
}



/****************************************************************************************/




void MainWindow::on_comboBox_tri_activated()
{
    if(ui->comboBox_tri->currentText()=="Tri par CIN Monatnt")
    {
        ui->table_employe->setModel(E.trierEmployeParCIN_M());

    }else if(ui->comboBox_tri->currentText()=="Tri par CIN Descendant")
    {
        ui->table_employe->setModel(E.trierEmployeParCIN_D());

    }else if(ui->comboBox_tri->currentText()=="Tri par Nom")
    {
        ui->table_employe->setModel(E.trierEmployeParNom());
    }else
    {

        ui->table_employe->setModel(E.trierEmployeParDate());
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

           if (username == "admin" && password == "admin") {
               QMessageBox::information(this, "Login", "Username and password are correct");
            ui->stackedWidget->setCurrentIndex(1);

           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
           ui->lineEdit_username->clear();
           ui->lineEdit_password->clear();
}



/************************************************************************************************************************/

void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp * smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->currentText(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->currentText(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
