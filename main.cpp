#include "avion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    avion w;
    w.show();
    return a.exec();
}
