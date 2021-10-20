#ifndef EMPLOY_H
#define EMPLOY_H
#include <iostream>
#include <string>

using namespace std;

class EMPLOYE{

    private:
        int CIN;
        string nom;
        string prenom;
        int Date_naiss;
        string sexe;
        int num_tel;
        string email;
        string adress;

    public:
        int getCINEmp()const{return CIN;}
        string getNomEmp()const{return nom;}
        string getPrenomEmp()const{return prenom;}
        void ajouteremploye();
        void supprimeremploye();
        void modifieremploye();
        void chercheremploye();

};



#endif // EMPLOY_H
