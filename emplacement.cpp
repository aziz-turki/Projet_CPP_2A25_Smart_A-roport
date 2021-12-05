#include "emplacement.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>
#include<QString>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include<fstream>
#include<iostream>
#include<GL/gl.h>

Emplacement::Emplacement()
{
num=0,dimension=0;
nom_emp=" ",reservation=" ",liberation=" ";
}


Emplacement::Emplacement(int num,QString nom_emp,int dimension,QString reservation,QString liberation)
{
    this->num=num;
    this->nom_emp=nom_emp;
    this->dimension=dimension;
    this->reservation=reservation;
    this->liberation=liberation;
}

    int Emplacement::getnum(){return num;}
    QString Emplacement::getnomEm(){return nom_emp;}
    int Emplacement::getdimension(){return dimension;}
    QString Emplacement::getreservation(){return reservation;}
    QString Emplacement::getliberation(){return liberation;}

    void Emplacement::setnum(int num){this->num=num;}
    void Emplacement::setnomEm(QString nom_emp){this->nom_emp=nom_emp;}
    void Emplacement::setdimension(int dimension){this->dimension=dimension;}
    void Emplacement::setreservation(QString reservation){this->reservation=reservation;}
    void Emplacement::setliberation(QString liberation){this->liberation=liberation;}



    bool Emplacement::ajouterEmplacement()
    {

             QSqlQuery query;
             query.prepare("INSERT INTO EMPLACEMENT (NUM, NOM_EMP, DIMENSION ,RESERVATION, LIBERATION) "
                           "VALUES (:num, :nom_emp, :dimension, :reservation, :liberation)");// prparation de requette
             query.bindValue(":num", num);
             query.bindValue(":nom_emp", nom_emp);
             query.bindValue(":dimension",dimension);
             query.bindValue(":reservation",reservation);
             query.bindValue(":liberation",liberation);
             return query.exec();
    }



/***********************************************************************************************/


    QSqlQueryModel* Emplacement::afficherEmplacement()
    {
         QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT *  FROM EMPLACEMENT ");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("dimension"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("reservation"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("liberation"));

         return model;
    }


 /***********************************************************************************************/


    bool Emplacement::supprimerEmplacement(int)
    {
        QSqlQuery query;
        query.prepare(" Delete from EMPLACEMENT where NUM=:NUM ");
        query.bindValue(":NUM",num);

        return query.exec();
    }




/***********************************************************************************************/



    bool Emplacement::modifierEmplacement(int num, QString nom_emp , int dimension , QString reservation, QString liberation)
    {
        QSqlQuery query;
        query.prepare("update EMPLACEMENT set nom_emp=:nom_emp,dimension=:dimension,reservation=:reservation,liberation=:liberation where num=:num");
        query.bindValue(":num",num);
        query.bindValue(":nom_emp",nom_emp);
        query.bindValue(":dimension",dimension);
        query.bindValue(":reservation",reservation);
        query.bindValue(":liberation",liberation);
        return query.exec();

    }



/******************************************************************************************************************************/

    QSqlQueryModel *  Emplacement::chercheEmplacement(QString recherche)
     {
         QSqlQueryModel * model= new QSqlQueryModel();
         model->setQuery("SELECT * FROM emplacement WHERE num LIKE '"+recherche+"%' OR nom_emp LIKE '"+recherche+"%' OR dimension LIKE '"+recherche+"%'");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_emp"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("dimension"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("reservation"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("liberation"));
         return model;
    }

/********************************************************************************************/



    QSqlQueryModel * Emplacement::triEmplacementParDimension()
    {

        QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM EMPLACEMENT order by dimension ASC");
               q->exec();
               model->setQuery(*q);
               return model;
    }

    ////////////////////
    QSqlQueryModel * Emplacement::triEmplacementParNom()
    {

        QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM EMPLACEMENT order by nom_emp ASC");
               q->exec();
               model->setQuery(*q);
               return model;
    }

    ////////////////////
    QSqlQueryModel * Emplacement::triEmplacementParNum()
    {

        QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM EMPLACEMENT order by num ASC");
               q->exec();
               model->setQuery(*q);
               return model;
    }



/***********************************************************************************/
/*
QSqlQueryModel * Emplacement :: Historique(QString annee )
{
    QSqlQuery  q ;
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q.prepare("SELECT * FROM Emplacement where reservation LIKE  '%"+annee+"'  ");
           q.exec();
           model->setQuery(q);
           return model;
}

*/







