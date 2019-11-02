#include "estudiante.h"

estudiante::estudiante()
{

}
void estudiante::termino(){
    if (numNodo==camino.size()) {
        qDebug()<<"termino";
    }else if(numNodo==camino.size()-1){
        caminar(camino[numNodo],nullptr);
    } else {
        caminar(camino[numNodo],camino[numNodo+1]);
    }
    numNodo=numNodo+1;
}

void estudiante::setNodoActual(nodo *act){
    actual = act;
    actual->agregarEstudiante(this);
    if (actual->tieneVigilante()){
        actual->solicitarEvaluacion(actual);
    }
}

void estudiante::salioNodoActual(){
    if (actual!=nullptr){
        int nodoX=actual->x;
        int nodoY=actual->y;
        if(!(h->x()+50<=nodoX+50 && h->x()+50>=nodoX && h->y()+50<=nodoY+50 && h->y()+50>=nodoY)){
            actual->eliminarEstudiante(this);
            actual=nullptr;
        }
    }
}
void estudiante::siendoEvaluado(int impacto){
    qDebug()<<impacto;
}
void estudiante::caminar(nodo* ini, nodo* fin){

    h->setPixmap(QPixmap(":/est1.png"));
    h->setScaledContents(true);

    animation->setDuration(2000);

    if(ini==nullptr){
        animation->setStartValue(QRect(0,0,50,50));
    } else {
        animation->setStartValue(QRect(ini->x,ini->y,50,50));
    }

    if (fin == nullptr){
        animation->setEndValue(QRect(900,500,50,50));
    } else {
        animation->setEndValue(QRect(fin->x,fin->y,50,50));
    }
    animation->start();

}

void estudiante::buscarCamino(nodo *matriz[10][10]){
    nodo *inicio;
    nodo *actual;
    nodo *final;
    inicio= matriz[0][0];
    final= matriz[9][9];
    int col=0;
    int fil=0;
    actual=inicio;
    camino.push_back(actual);
    while (actual!=final){
        int caso=0;
        caso=rand()%3;
        if (caso==0){
            if ((col+1)<10 && matriz[col+1][fil]->isFree()){
                col=col+1;
                actual=matriz[col][fil];
                camino.push_back(actual);
            }

        }else if (caso==1 ){
            if ((fil+1)<10 && matriz[col][fil+1]->isFree()){
                fil=fil+1;
                actual=matriz[col][fil];
                camino.push_back(actual);
            }

        }else if (caso ==2){
            if((col+1)<10 && (fil+1)<10 && matriz[col+1][fil+1]->isFree()){
                col=col+1;
                fil=fil+1;
                actual=matriz[col][fil];
                camino.push_back(actual);
            }
        }
    }
    caminar(nullptr,inicio);
}

void estudiante::setParent(Tablero *parent){
    h = new QLabel(parent);
    animation = new QPropertyAnimation(h,"geometry");
    connect(animation,SIGNAL(finished()),this,SLOT(termino()));
}
