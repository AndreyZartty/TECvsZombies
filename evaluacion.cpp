#include "evaluacion.h"

Evaluacion::Evaluacion()
{

}

void Evaluacion::evaluar(int x, int y){
    imagen->setText("???");
    imagen->setScaledContents(true);

    animation->setDuration(1000);
    animation->setEndValue(QRect(x,y,50,50));
    animation->start();

}
void Evaluacion::setOrigen(int x, int y){
    corx = x;
    cory = y;
}

void Evaluacion::llegaEvaluacion(){
    qDebug()<<"Llega";
}

void Evaluacion::setParent(){
    imagen = new QLabel();
    animation = new QPropertyAnimation(imagen,"geometry");
    animation->setStartValue(QRect(corx,cory,50,50));
    connect(animation,SIGNAL(finished()),this,SLOT(llegaEvaluacion()));
}
