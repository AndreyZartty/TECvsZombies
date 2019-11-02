#include "tablero.h"
#include "ui_tablero.h"
#include <nodo.h>
#include <QPalette>

Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{

    ui->setupUi(this);
    crearMatriz();
    this->setFixedSize(QSize(1200, 720));
    QPixmap imagenFondo(":/tileversions.png");
            imagenFondo = imagenFondo.scaled(this->size(), Qt::IgnoreAspectRatio);
            QPalette palette;
            palette.setBrush(QPalette::Background, imagenFondo);
        this->setAutoFillBackground(true);
        this->setPalette(palette);
        this->saveGeometry();
}

Tablero::~Tablero()
{
    delete ui;
}

//BUsca los nodos adyacentes segun el alcance
void Tablero::generarAdyacentes(nodo* seleccionado){
    qDebug()<<"aqui en tablero"<<seleccionado;
    int alcance = seleccionado->Curso->alcance;

    for(int y = -alcance; y<alcance+1;y++){
        for (int x = -alcance;x<alcance+1;x++){
            if (seleccionado->col+x<10 && seleccionado->col+x>-1 && seleccionado->fil+y<10 && seleccionado->fil+y>-1){
                if (x==0 && y==0){
                    qDebug()<<"Mismo nodo"<<endl;
                }else{
                    matriz[seleccionado->col+x][seleccionado->fil+y]->setVigilante(matriz[seleccionado->col][seleccionado->fil]->Curso);
                }
            }
        }
    }
}

void Tablero::eliminarAdyacentes(nodo* seleccionado){
    qDebug()<<"aqui en tablero"<<seleccionado;
    int alcance = seleccionado->Curso->alcance;

    for(int y = -alcance; y<alcance+1;y++){
        for (int x = -alcance;x<alcance+1;x++){
            if (seleccionado->col+x<10 && seleccionado->col+x>-1 && seleccionado->fil+y<10 && seleccionado->fil+y>-1){
                if (x==0 && y==0){
                    qDebug()<<"Mismo nodo"<<endl;
                }else{
                    matriz[seleccionado->col+x][seleccionado->fil+y]->setVigilante(nullptr);
                }
            }
        }
    }
}



void Tablero::crearMatriz(){
    nodo *temp;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            temp = new nodo(i,j);
            matriz[i][j]=temp;
            temp->setParent(this);
        }
    }

}


void Tablero::mover(){

    QLabel *h;
    h = new QLabel("hola", this);
    h->setPixmap(QPixmap(":/house.png"));
    h->setScaledContents(true);

    animation = new QPropertyAnimation(h,"geometry");
    animation->setDuration(2000);
    animation->setStartValue(QRect(0,0,100,100));
    animation->setEndValue(QRect(900,200,100,100));
    animation->start();
}


