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

Emplacement::Emplacement()
{
num=0,dimension=0;
nom=" ",reservation=" ",liberation=" ";
}
Emplacement::Emplacement(int num,QString nom,int dimension,QString reservation,QString liberation)
{ this->num=num;
    this->nom=nom;
this->dimension=dimension;
this->reservation=reservation;
this->liberation=liberation;}

  int Emplacement::getnum(){return num;}

  QString Emplacement::getnom(){return nom;}

  int Emplacement::getdimension(){return dimension;}
  QString Emplacement::getreservation(){return reservation;}
  QString Emplacement::getliberation(){return liberation;}
  void Emplacement::setnum(int num){this->num=num;}
  void Emplacement::setnom(QString nom){this->nom=nom;}
    void Emplacement::setdimension(int dimension){this->dimension=dimension;}
      void Emplacement::setreservation(QString reservation){this->reservation=reservation;}


  bool Emplacement::ajouter()


  {
      QSqlQuery query;
      QString num_string= QString::number(num);
      QString dimension_string= QString::number(dimension);
            query.prepare("INSERT INTO Emplacement (Num, Nom,dimension,reservation,liberation) "
                          "VALUES (:num, :nom,:dimension,:reservation,:liberation )");
            query.bindValue(":num", num_string);
            query.bindValue(":nom", nom);
            query.bindValue(":dimension", dimension_string);
             query.bindValue(":reservation", reservation);
             query.bindValue(":liberation", liberation);

           return query.exec();


  }

 bool Emplacement::supprimer(int num)
{  QSqlQuery query;
 QString num_string= QString::number(num);
       query.prepare("Delete from Emplacement where num=:num");
       query.bindValue(0, num);

      return query.exec();
}
QSqlQueryModel* Emplacement::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM emplacement ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dimension"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("reservation"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("liberation"));
    return model;
}
bool Emplacement::modifier(int num,QString nom,int dimension,QString reservation,QString liberation)
{

    QSqlQuery query;
    query.prepare("update Emplacement set nom=:nom,dimension=:dimension,reservation=:reservation,liberation=:liberation where num=:num");
    query.bindValue(":num",num);
    query.bindValue(":nom",nom);
    query.bindValue(":dimension",dimension);
    query.bindValue(":reservation",reservation);
    query.bindValue(":liberation",liberation);
    return query.exec();

}






