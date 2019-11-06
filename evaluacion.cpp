#include "evaluacion.h"
#include <tablero.h>
#include <nodo.h>

Evaluacion::Evaluacion()
{

}

void Evaluacion::evaluar(nodo*g){
    actual = g;
    imagen->setPixmap(QPixmap(":/car.png"));
    imagen->setScaledContents(true);

    animation->setDuration(1000);

    connect(this,SIGNAL(termino()),g,SLOT(atacar()));
    animation->setStartValue(QRect(corx,cory,50,50));
    animation->setEndValue(QRect(g->x,g->y,50,50));
    animation->start();
}
void Evaluacion::setOrigen(int x, int y){
    corx = x;
    cory = y;
}

void Evaluacion::llegaEvaluacion(){
    qDebug()<<"Llega";
    emit termino();
}

void Evaluacion::setParent(Tablero * h){
    imagen = new QLabel(h);
    animation = new QPropertyAnimation(imagen,"geometry");
    connect(animation,SIGNAL(finished()),this,SLOT(llegaEvaluacion()));
}
