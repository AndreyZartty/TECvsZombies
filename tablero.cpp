#include "tablero.h"
#include "ui_tablero.h"
#include <nodo.h>

Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{

    ui->setupUi(this);
    crearMatriz();
}

Tablero::~Tablero()
{
    delete ui;
}

void Tablero::crearMatriz(){
    nodo *temp;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            temp = new nodo(200+i*80,50+j*60);
            temp->boton->setParent(this);
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
