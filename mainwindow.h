#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "emplacement.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pbajouter_clicked();

    void on_pbsupp_clicked();

   // void on_pbmodifier_clicked();



    void on_pbafficher_clicked();

    void on_pb_miseajour_clicked();

private:
    Ui::MainWindow *ui;
    Emplacement E;
};

#endif // MAINWINDOW_H
