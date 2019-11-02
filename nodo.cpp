#include "nodo.h"
#include <crearcurso.h>
#include <tablero.h>
#include <algorithm>
#include <estudiante.h>


nodo::nodo(int col, int fil):x(120+col*80),y(50+fil*60),col(col),fil(fil)
{
    boton = new QToolButton();
    boton->setGeometry(x,y,50,50);
    p = new crearCurso();
    connect(boton,SIGNAL(clicked()),this, SLOT(onClick()));
    connect(p,SIGNAL(cursoCreado()),this,SLOT(modificarNodo()));
}

void nodo::setParent(Tablero *parent){
    par = parent;
    connect(this,SIGNAL(cursoCreado(nodo*)),parent,SLOT(generarAdyacentes(nodo*)));
    boton->setParent(parent);
}

void nodo::agregarEstudiante(estudiante *e){
    listaEstudiantes.push_back(e);
}

void nodo::eliminarEstudiante(estudiante *e){
    std::vector<estudiante*>::iterator position = std::find(listaEstudiantes.begin(),listaEstudiantes.end(),e);
    if (position != listaEstudiantes.end()){
        listaEstudiantes.erase(position);
    }
}
void nodo::atacar(){
    for (int est=0;est<listaEstudiantes.size();est++){
        listaEstudiantes[est]->siendoEvaluado(5);
    }
}

bool nodo::tieneVigilante(){
    return vigilante!=nullptr;
}

void nodo::solicitarEvaluacion(nodo*target){
    /*
    connect(vigilante->examen,SIGNAL(termino()),this,SLOT(atacar()));
    vigilante->examen->evaluar(target->x,target->y);*/
    vigilante->examen->imagen->setParent(par);
    vigilante->examen->evaluar(100,100);
    qDebug()<<vigilante;
}

void nodo::onClick(){
    p->show();
    qDebug()<<"Toca el botón"<<boton;
    qDebug()<<"En el nodo"<<this;
}

bool nodo::isFree(){
    return Curso==nullptr;
}


void nodo::modificarNodo(){
    Curso = p->Curso;
    Curso->examen->setParent();
    Curso->examen->setOrigen(x,y);
    boton->setIconSize(QSize(50,50));
    boton->setIcon(Curso->imagen);
    emit cursoCreado(this);
    delete (p);
}

void nodo::setVigilante(curso* v){
    boton->setIcon(QPixmap(":/boat.png"));
    vigilante = v;
}

