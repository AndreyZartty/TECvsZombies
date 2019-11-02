#include "tablero.h"
#include "ui_tablero.h"
#include <nodo.h>
#include <QPalette>
#include <QRect>

Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{

    ui->setupUi(this);
    //AGREGA LOS BOTONES
    crearMatriz();
    this->setFixedSize(QSize(1200, 720));

    //AQUI AGREGA EL FONDO DEL TABLERO
    QPixmap imagenFondo(":/tileversions.png");
    imagenFondo = imagenFondo.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, imagenFondo);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    this->saveGeometry();

    //LABEL COLOR NEGRO NIVEL 1
    QLabel *imagenNegro =new QLabel("");
    imagenNegro->setGeometry(25,200,20,20);
    QPixmap negro(":/black.jpg");
    negro = negro.scaled(imagenNegro->size(),Qt::IgnoreAspectRatio);
    imagenNegro->setPixmap(negro);
    imagenNegro->setParent(this);
    imagenNegro->setVisible(true);

    //LABEL COLOR AZUL NIVEL 2
    QLabel *imagenAzul =new QLabel("");
    imagenAzul->setGeometry(25,250,20,20);
    QPixmap azul(":/blue.jpg");
      azul = azul.scaled(imagenAzul->size(),Qt::IgnoreAspectRatio);
    imagenAzul->setPixmap(azul);
    imagenAzul->setParent(this);
    imagenAzul->setVisible(true);


    //LABEL COLOR AMARILLO NIVEL 3
    QLabel *imagenAmarillo =new QLabel("");
    imagenAmarillo->setGeometry(25,300,20,20);
    QPixmap amarillo(":/yellow.png");
    amarillo = amarillo.scaled(imagenAmarillo->size(),Qt::IgnoreAspectRatio);
    imagenAmarillo->setPixmap(amarillo);
    imagenAmarillo->setParent(this);
    imagenAmarillo->setVisible(true);

    //LABEL NIVEL 1
    QLabel *labelTexto =new QLabel("NIVEL 1");
    labelTexto->setGeometry(50,200,120,20);
    labelTexto->setParent(this);
    labelTexto->setVisible(true);

    //LABEL NIVEL 2
    QLabel *labelTexto2 =new QLabel("NIVEL 2");
    labelTexto2->setGeometry(50,250,120,20);
    labelTexto2->setParent(this);
    labelTexto2->setVisible(true);

    //LABEL NIVEL 3
    QLabel *labelTexto3 =new QLabel("NIVEL MAX");
    labelTexto3->setGeometry(50,300,120,20);
    labelTexto3->setParent(this);
    labelTexto3->setVisible(true);

}



Tablero::~Tablero()
{
    delete ui;
}

//BUsca los nodos adyacentes segun el alcance
void Tablero::generarAdyacentes(nodo* seleccionado){
    qDebug()<<"aqui en tablero"<<seleccionado;
    int alcance = seleccionado->Curso->getAlcance();

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


//ELIMINA LOS NODOS ADYACENTES AL ELIMINAR CURSO
void Tablero::eliminarAdyacentes(nodo* seleccionado){
    qDebug()<<"aqui en tablero"<<seleccionado;
    int alcance = seleccionado->Curso->getAlcance();

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


