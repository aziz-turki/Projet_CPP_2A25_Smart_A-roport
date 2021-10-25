#include "employes.h"

Employes::Employes()
{
CIN=0; nom=""; prenom="";
}

Employes::Employes(int CIN,QString nom,QString prenom)
{this->CIN=CIN; this->nom=nom; this->prenom=prenom;}

int Employes::getCIN(){return CIN;}

QString Employes::getnom(){return nom;}

QString Employes::getprenom(){return prenom;}

void Employes::setCIN(int CIN){this->CIN=CIN;}

void Employes::setnom(QString nom){this->nom=nom;}

void Employes::setprenom(QString prenom){this->prenom=prenom;}

.....
