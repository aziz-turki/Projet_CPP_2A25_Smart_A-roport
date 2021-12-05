#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H
#include<QSqlQueryModel>
#include <QString>
class Emplacement
{
public:
    Emplacement();
    Emplacement(int, QString, int, QString, QString);
    int getnum();
    QString getnomEm();
    int getdimension();
    QString getreservation();
    QString getliberation();

    void setnum(int);
    void setnomEm(QString);
    void setdimension(int);
    void setreservation(QString);
    void setliberation(QString);

//////////////////


   bool ajouterEmplacement();
   QSqlQueryModel* afficherEmplacement();
   bool supprimerEmplacement(int);
   bool modifierEmplacement(int,QString,int ,QString,QString);
   QSqlQueryModel *  chercheEmplacement(QString);
   QSqlQueryModel * triEmplacementParDimension();
   QSqlQueryModel * triEmplacementParNom();
   QSqlQueryModel * triEmplacementParNum();

   //QSqlQueryModel * Historique(QString);

    private:

        int num,dimension;
    QString nom_emp, reservation,liberation;
};

#endif // EMPLACEMENT_H
