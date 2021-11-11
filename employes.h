#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>

class Employe

{
public:
    Employe();
    Employe(int,QString,QString,QString,QString,int,QString,QString);
    int getCIN();
    QString getnom();
    QString getprenom();
    QString getsexe();
    QString getdate_naissance();
    int getnum_tel();
    QString getemail();
    QString getadress();


    void setCIN(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    void setdate_naissance(QString);
    void setnum_tel(int);
    void setemail(QString);
    void setadress(QString);


    bool ajouterEmploye();
    QSqlQueryModel* afficherEmploye();
    bool supprimerEmploye(int);
    bool modifierEmploye(int,QString,QString,QString,QString,int,QString,QString);
    QSqlQueryModel* RechercheEmploye(int);
    QSqlQueryModel * trierEmploye();
    void CREATION_PDF_Employe();


private:
    int CIN,num_tel;
    QString nom,prenom,sexe,date_naissance,email,adress;

};

#endif // EMPLOYES_H
