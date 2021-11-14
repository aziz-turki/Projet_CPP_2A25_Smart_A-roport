#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
//CRUDS
class Employe

{
public:
    Employe();
    Employe(int,QString,QString,QString,QDate,int,QString,QString);
    int getCIN();
    QString getnom();
    QString getprenom();
    QString getsexe();
    QDate getdate_naissance();
    int getnum_tel();
    QString getemail();
    QString getadress();



    void setCIN(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    void setdate_naissance(QDate);
    void setnum_tel(int);
    void setemail(QString);
    void setadress(QString);


    bool ajouterEmploye();
    QSqlQueryModel* afficherEmploye();
    bool supprimerEmploye(int);
    bool supprimerTout();
    bool modifierEmploye(int,QString,QString,QString,QDate,int,QString,QString);
    QSqlQueryModel* RechercheEmploye(int,QString,QString);
    QSqlQueryModel * trierEmployeParCIN();
    QSqlQueryModel * trierEmployeParNom();
    QSqlQueryModel * trierEmployeParDate();
    void CREATION_PDF_Employe();


private:
    int CIN,num_tel;
    QString nom,prenom,sexe,email,adress;
    QDate date_naissance;
};

#endif // EMPLOYES_H
