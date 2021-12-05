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
    QString getnom();
    int getdimension();
    QString getreservation();
    QString getliberation();
    void setnum(int);
    void setnom(QString);
    void setdimension(int);
    void setreservation(QString);
    void setliberation(QString);
    bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier(int,QString,int ,QString,QString);
   QSqlQueryModel *  chercheEmplacement(QString);
   QSqlQueryModel * triEmplacementParDimension();
   QSqlQueryModel * triEmplacementParNom();
   QSqlQueryModel * triEmplacementParNum();

    private:

        int num,dimension;
    QString nom, reservation,liberation;
};

#endif // EMPLACEMENT_H
