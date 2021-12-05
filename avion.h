#ifndef AVION_H
#define AVION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qdatetimeedit.h>
#include<qdatetime.h>
#include <QVariant>
#include <QComboBox>

class avion
{
public:
    avion();
    avion(int,QString,QString,QString,QString,int);
    int get_code();
    QString get_depart();
    int get_nbplace();
    QString get_arrivee();
    QString get_prix();
    QString get_duree();

      void setcode(int);
      void setdepart(QString);
      void setnbplace(int);
      void setarrivee(QString);
      void setprix(QString);
      void setduree(QString);


    bool ajouterAvion();

    bool supprimerAvion(int);

    void CREATION_PDF_Avion();

    QSqlQueryModel *afficherAvion();

    bool modifierAvion(int,QString,QString,QString,QString,int);

    QSqlQueryModel* RechercheAvion(QString);

    QSqlQueryModel * trieravionParCodeAvion();
    QSqlQueryModel * trieravionParnbplace();
    QSqlQueryModel * trieravionParprix();






private:
    int code;
    QString depart;
    QString arrivee ;
    QString duree ;
    QString prix ;
    int nbplace;

};


#endif
