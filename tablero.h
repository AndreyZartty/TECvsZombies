#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <nodo.h>

namespace Ui {
class Tablero;
}

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    void mover();
    void crearMatriz();
    ~Tablero();

private:
    Ui::Tablero *ui;
    nodo* matriz[10][10];
    QPropertyAnimation *animation;

};

#endif // TABLERO_H
