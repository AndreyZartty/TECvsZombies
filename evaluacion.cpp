#include "evaluacion.h"

Evaluacion::Evaluacion()
{

}

void Evaluacion::evaluar1(int x, int y){
    imagen1->setText("???");
    imagen1->setScaledContents(true);

    animation->setDuration(1000);
    animation->setEndValue(QRect(x,y,50,50));
    animation->start();

}
void Evaluacion::setOrigen1(int x, int y){
    corx1 = x;
    cory1 = y;
}

void Evaluacion::llegaEvaluacion1(){
    qDebug()<<"Llega";
}

void Evaluacion::setParent1(){

}
