#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>

class Employes
{
public:
    Employes();
    Employes(int,QString,QString);
    int getCIN();
    QString getnom();
    QString getprenom();
    void setCIN(int);
    void setnom(QString);
    void setprenom(QString);


private:
    int CIN;
    QString nom,prenom;
    int Date_naiss;
    QString sexe;
    int num_tel;
    QString email;
    QString adress;

};

#endif // EMPLOYES_H
