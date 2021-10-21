#include "avion.h"
#include "ui_avion.h"

avion::avion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::avion)
{
    ui->setupUi(this);
}

avion::~avion()
{
    delete ui;
}

