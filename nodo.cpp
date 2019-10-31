#include "nodo.h"
#include <crearcurso.h>

nodo::nodo(int corx, int cory):x(corx),y(cory)
{
    boton = new QToolButton();
    boton->setGeometry(x,y,50,50);
    p = new crearCurso();
    connect(boton,SIGNAL(clicked()),this, SLOT(onClick()));
    connect(p,SIGNAL(cursoCreado()),this,SLOT(modificarNodo()));
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
    delete (p);
}

