#include "tablero.h"
#include "ui_tablero.h"
#include <nodo.h>
#include <estudiante.h>


Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{

    ui->setupUi(this);
    revisa = new workerRevisar;
    connect(revisa,SIGNAL(progreso()),this,SLOT(revisaNodos()));
    revisa->start();
    crearMatriz();
}

Tablero::~Tablero()
{
    delete ui;
}


void Tablero::revisaNodos(){
    for (int ind=0; ind<listaEstudiantes.size();ind++){
        int ex=listaEstudiantes[ind]->h->x();
        int ey=listaEstudiantes[ind]->h->y();
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                int nodoX=matriz[i][j]->x;
                int nodoY=matriz[i][j]->y;
                listaEstudiantes[ind]->salioNodoActual();
                if(ex+50<=nodoX+50 && ex+50>=nodoX && ey+50<=nodoY+50 && ey+50>=nodoY){
                    if (listaEstudiantes[ind]->actual==nullptr){
                        listaEstudiantes[ind]->setNodoActual(matriz[i][j]);
                    }
                 }
            }
        }
    }
}

void Tablero::generarAdyacentes(nodo* seleccionado){
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



void Tablero::crearMatriz(){
    nodo *temp;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            temp = new nodo(i,j);
            matriz[i][j]=temp;
            temp->setParent(this);
        }
    }
    estudiante *e = new estudiante();
    e->setParent(this);
    e->buscarCamino(matriz);
    listaEstudiantes.push_back(e);
}
