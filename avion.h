#ifndef AVION_H
#define AVION_H
#include <iostream>
#include <string>
//test tutoriel git
using namespace  std ;
class avion {
private:

    int code ;
    string nom ;
    string directin ;
    string localisation ;
    int durée vol ;
    bool retard ;
public :
    string getNomAvi()const{return getNomAvi();}
    int getCodeAvi()const {return getCodeAvi();}
    int getduréeAvi()const {return getduréeAvi();}
    bool getRetardAvi()const {return getRetardAvi();}
    string getDirectionAvi()const{return getDirectionAvi() ;}
    string getLocalisationAvi()const{return getLocalisationAvi() ;}

 void ajouterAvi();
 void supprimerAvi(float);
 void chercherAvi(avion *a);
 void trierAvi(avion a);
 void imprimer (avion a) ;
 void miseajourAvi(avion a);
 void pdfAvi();
 void insertionimageAvi(avion a);


}

#endif // AVION_H
