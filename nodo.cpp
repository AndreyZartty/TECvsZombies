#include "nodo.h"
#include <crearcurso.h>
#include <tablero.h>


nodo::nodo(int col, int fil):x(200+col*80),y(50+fil*60),col(col),fil(fil)
{
    boton = new QToolButton();
    boton->setGeometry(x,y,50,50);
    p = new crearCurso();
    connect(boton,SIGNAL(clicked()),this, SLOT(onClick()));
    connect(p,SIGNAL(cursoCreado()),this,SLOT(modificarNodo()));
}

void nodo::setParent(Tablero *parent){
    connect(this,SIGNAL(cursoCreado(nodo*)),parent,SLOT(generarAdyacentes(nodo*)));
    boton->setParent(parent);
}


void nodo::onClick(){
    p->show();
    qDebug()<<"Toca el botón"<<boton;
    qDebug()<<"En el nodo"<<this;
}

void nodo::modificarNodo(){
    Curso = p->Curso;
    boton->setIconSize(QSize(50,50));
    boton->setIcon(Curso->imagen);
    emit cursoCreado(this);
    delete (p);
}

void nodo::setVigilante(curso* v){
    boton->setIcon(QPixmap(":/boat.png"));
    vigilante = v;
}

