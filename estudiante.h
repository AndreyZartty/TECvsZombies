#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <QPropertyAnimation>
#include <QLabel>
#include <tablero.h>
#include <nodo.h>
#include <vector>
#include <QWidget>

class estudiante;
class estudiante : public QWidget
{
    Q_OBJECT


public:
    estudiante();
    void caminar(nodo*,nodo*);
    QLabel *h;
    void setParent(Tablero*);
    void buscarCamino(nodo* matriz[10][10]);
    void salioNodoActual();
    void setNodoActual(nodo*);
    void siendoEvaluado(int impacto);
    nodo *actual=nullptr;

public slots:
    void termino();

private:
    vector<nodo*> camino;
    QPropertyAnimation *animation;

    int numNodo=0;

};

#endif // ESTUDIANTE_H
