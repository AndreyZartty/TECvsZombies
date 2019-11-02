#include "nodo.h"
#include <crearcurso.h>
#include <tablero.h>
#include <modificarcurso1.h>
#include <QPalette>
#include <iostream>

using namespace std;

//CONSTRUCTOR
nodo::nodo(int col, int fil):x(200+col*80),y(50+fil*60),col(col),fil(fil)
{
    Curso = nullptr;
    //boton es la torre
    boton = new QToolButton();

    //DEFINE EL TAMAÑO DE LOS BOTONES
    boton->setGeometry(x,y,45,45);
    boton->autoRaise();

    //AQUI PONE LA IMAGEN DE FONDO
    QPixmap imagenFondo(":/tileversions.png");
    imagenFondo = imagenFondo.scaled(boton->size());
    boton->setAutoFillBackground(true);

    //AQUI CREA EL COLOR DE LOS BOTONES
    QPalette palette = boton->palette();
    palette.setColor(QPalette::Button, QColor(Qt::black));
    boton->setPalette(palette);

    //LE PONE LA IMAGEN A LOS BOTONES
    boton->setIcon(imagenFondo);
    boton->setIconSize(QSize(42,42));


    //Pantalla con cursos por seleccionar
    pantallaAgregarCurso = new crearCurso();
    pantallaModificarCurso = new modificarCurso1();

    //Cuando se da click al nodo para agregar la torre
    connect(boton,SIGNAL(clicked()),this, SLOT(onClick()));

    //Cuando se escoge alguna torre, actualiza este
    connect(pantallaAgregarCurso,SIGNAL(cursoCreado()),this,SLOT(modificarNodo()));

    //Para eliminar la torre
    connect(pantallaModificarCurso,SIGNAL(eliminarCurso()),this,SLOT(eliminar()));
    connect(pantallaModificarCurso,SIGNAL(actualizarCurso()),this,SLOT(actualizar()));
}

//Eliminar el curso del nodo
void nodo::eliminar(){
    //AQui define la imagen
    QPixmap imagenFondo(":/tileversions.png");
    imagenFondo = imagenFondo.scaled(boton->size());

    //Le setea la imagen al botón
    boton->setIcon(imagenFondo);
    boton->setIconSize(QSize(50,50));
    //emite la señal
    emit cursoEliminado(this);

    //quita la pantalla de modificar
    pantallaModificarCurso->hide();
    //elimina el curso
    Curso= nullptr;
}

void nodo::actualizar(){
    if(Curso->Upgrade()){
        if(Curso->getUpgrade() == 2){
            boton->setIconSize(QSize(40,40));
            boton->setIcon(Curso->imagen);
            pantallaModificarCurso->hide();
            cout << "Upgrade 2" << endl;

        }
        else{
            boton->setIconSize(QSize(20,20));
            boton->setIcon(Curso->imagen);
            pantallaModificarCurso->hide();
            cout << "Upgrade 3" << endl;

        }
    }
    else{
        cout << "NO PUEDE ACTUALIZAR" << endl;
    }

}

//Cuando se selecciona un nodo y se agrega un curso, genera adyacentes
void nodo::setParent(Tablero *parent){
    connect(this,SIGNAL(cursoCreado(nodo*)),parent,SLOT(generarAdyacentes(nodo*)));
    connect(this,SIGNAL(cursoEliminado(nodo*)),parent,SLOT(eliminarAdyacentes(nodo*)));

    boton->setParent(parent);
}
/*
void nodo::eliminaCurso(Tablero *parent){
    connect(this,SIGNAL(cursoEliminado(nodo*)),parent,SLOT(eliminarAdyacentes(nodo*)));
    boton->setParent(parent);
}*/



//AL darle click al nodo
void nodo::onClick(){
    if (Curso==nullptr){
    pantallaAgregarCurso->show();
    qDebug()<<"Toca el botón"<<boton;
    qDebug()<<"En el nodo"<<this;

    //Se agrega la pantalla de eliminar y upgrade
    }else{
        pantallaModificarCurso->show();

    }
}
void nodo::modificarNodo(){
    //Este es el curso seleccionada
    Curso = pantallaAgregarCurso->Curso;
    boton->setIconSize(QSize(42,42));
    boton->setIcon(Curso->imagen);
    //Se define el tipo de torre
    emit cursoCreado(this);
    pantallaAgregarCurso->hide();
}


// Se define la torre vigilante, cual torre vigila los nodos
void nodo::setVigilante(curso* cursoSeleccionado){
    vigilante = cursoSeleccionado;
    if(cursoSeleccionado==nullptr){
        QPalette palette = boton->palette();
        palette.setColor(QPalette::Button, QColor(Qt::black));
        boton->setPalette(palette);
    } else {
        QPalette palette = boton->palette();
        palette.setColor(QPalette::Button, QColor(Qt::red));
        boton->setPalette(palette);
    }
}

