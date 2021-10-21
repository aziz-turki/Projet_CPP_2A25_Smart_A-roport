#ifndef AVION_H
#define AVION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class avion; }
QT_END_NAMESPACE

class avion : public QMainWindow
{
    Q_OBJECT

public:
    avion(QWidget *parent = nullptr);
    ~avion();

private:
    Ui::avion *ui;
};
#endif // AVION_H
