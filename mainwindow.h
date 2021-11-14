#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employes.h"

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

    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_MIseAJour_clicked();

    void on_pushButton_Recherche_clicked();

    void on_pushButton_Trier_clicked();

    void on_pushButton_PDF_clicked();

    //QModelIndex on_table_employe_activated(QModelIndex &index);

    void on_pushButton_Reset_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
};
#endif // MAINWINDOW_H
