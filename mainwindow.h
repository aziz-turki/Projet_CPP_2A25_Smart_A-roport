#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employes.h"
#include "avion.h"
#include "emplacement.h"
#include "arduino.h"

#include "smtp.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
/*****************************Employe************************************/

    void on_pushButton_Ajouter_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Afficher_clicked();
    void on_pushButton_MIseAJour_clicked();
    void on_lineEdit_recherche_textChanged();
    void on_pushButton_PDF_clicked();
    void on_pushButton_Reset_clicked();
    void on_pushButton_login_clicked();
    void on_comboBox_tri_activated();
    void on_table_employe_clicked(const QModelIndex &index);

/***********************************************************/

/******************************Avion**********************************/

    void on_pushButton_ajouteravion_clicked();
    void on_pushButton_afficheravion_clicked();
    void on_pushButton_supprimeravion_clicked();
    void on_pushButton_miseajouravion_clicked();
    void on_lineEdit_Rechercheavion_textChanged();
    void on_comboBox_trier_avion_activated();
    void on_table_avion_clicked(const QModelIndex &index);


/***********************************************************/

/*******************************Emplacement**********************************/

    void on_pushButton_ajouter_Emplacement_clicked();

    void on_pushButton_afficher_Emplacement_clicked();

    void on_pushButton_supprimer_Emplacement_clicked();

    void on_pushButton_modifier_Emplacement_clicked();

    void on_comboBox_trier_Emplacement_activated();



/*********************************************************/


/*********************************************************/

    void on_pushButton_gestion_employer_clicked();

    void on_pushButton_gestion_avion_clicked();

    void on_pushButton_emplacement_clicked();

    void on_pushButton_retour_employer_clicked();

    void on_pushButton_retour_avion_clicked();

    void on_pushButton_retour_emplacement_clicked();
    void update_label();


    void on_lineEdit_recherche_emplacement_textChanged();

    void on_table_Emplacement_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QStringList files;
    Employe E;
    avion A,A1;
    Emplacement Em;
    QByteArray data; // variable contenant les données reçues
    Arduino a; // objet temporaire
};
#endif // MAINWINDOW_H
