#ifndef EVALUACION_H
#define EVALUACION_H
#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
#include <QDebug>

class Tablero;
class nodo;

class Evaluacion;
class Evaluacion : public QWidget
{
    Q_OBJECT

public:
    Evaluacion();
    void setOrigen(int x, int y);
    void evaluar(nodo*);
    int corx;
    int cory;
    void setParent(Tablero *parent);

    QLabel *imagen;
    nodo* actual;
public slots:
    void llegaEvaluacion();
signals:
    void termino();
private:
    QPropertyAnimation *animation;
};

#endif // EVALUACION_H
