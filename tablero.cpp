#include "tablero.h"
#include "ui_tablero.h"
#include <nodo.h>
#include <QPalette>
#include <QRect>
#include <QPushButton>
#include <unistd.h>

#include "stats.h"
#include "juego.h"

#include "poblacion.h"
#include "list.h"




Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{

    game = new Juego();
    ui->setupUi(this);
    //AGREGA LOS BOTONES
    revisa = new workerRevisar;
    connect(revisa,SIGNAL(progreso()),this,SLOT(revisaNodos()));
    revisa->start();
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

    //Boton para mostrar estadisticas
    QPushButton *Stats = new QPushButton("Mostrar estadisticas");
    Stats->setGeometry(30,600,150,20);
    Stats->setParent(this);
    Stats->show();
    connect(Stats,SIGNAL(clicked()),this, SLOT(on_Stats_clicked()));

    //Boton APROBACION INDIVIDUAL
    QPushButton *aprobacionIndividual = new QPushButton("Aprobación Individual");
    aprobacionIndividual->setGeometry(30,100,160,25);
    aprobacionIndividual->setParent(this);
    aprobacionIndividual->show();
    connect(aprobacionIndividual,SIGNAL(clicked()),this, SLOT(on_aprobacionIndividual_clicked()));

    //Boton APROBACION COLECTIVA
    QPushButton *aprobacionColectiva = new QPushButton("Aprobación Colectiva");
    aprobacionColectiva ->setGeometry(30,140,160,25);
    aprobacionColectiva->setParent(this);
    aprobacionColectiva->show();
    connect(aprobacionColectiva,SIGNAL(clicked()),this, SLOT(on_aprobacionColectiva_clicked()));


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

void Tablero::on_aprobacionIndividual_clicked()
{
    vector<int> torres;

    for (int i = 0 ; i < 10 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {

            if (!matriz[i][j]->isFree()) {

                torres.push_back(matriz[i][j]->id);

            }

        }

    }

    game->getCuadricula()->setTowers(torres);

    game->doBacktracking();
    vector<int> path = game->getBacktrackingAlgorithm()->getPathToGoal();
    vector<nodo*> pathNode;

    game->doAStar();
    vector<int>path2 = game->getAStarAlgorithm()->getPathToGoal();
    vector<nodo*> pathNode2;

    while(gen<3){
        listaEstudiantes.clear();
        generaciones[gen-1]->bubbleSort();
        for (int i=0;i<8;i++) {
            listaEstudiantes.push_back(generaciones[gen-1]->recorrer(i));

        }
        for(int c=0; c<path.size() ; c++){
         for (int i = 0 ; i < 10 ; i++) {
                for (int j = 0 ; j < 10 ; j++) {

                    if (matriz[i][j]->id == path[c]) {

                        pathNode.push_back(matriz[i][j]);

                    }

                }

            }
        }

        for(int i= 0 ; i < listaEstudiantes.size()-1; i++){
            listaEstudiantes[i]->camino = pathNode;

          //usleep(1000);
        }
        for(int i= 0 ; i < listaEstudiantes.size()-1; i++){
            listaEstudiantes[i]->buscarCamino();

        }


        for(int c=0; c<path2.size() ; c++){
            for (int i = 0 ; i < 10 ; i++) {
                for (int j = 0 ; j < 10 ; j++) {

                    if (matriz[i][j]->id == path2[c]) {

                        pathNode2.push_back(matriz[i][j]);

                    }

                }

            }
        }
        listaEstudiantes[listaEstudiantes.size()-1]->camino = pathNode2;
        listaEstudiantes[listaEstudiantes.size()-1]->buscarCamino();
        gen++;
    }

}

void Tablero::on_aprobacionColectiva_clicked()
{
    /*Estudiante *e = new Estudiante();
    e->setParent(this);
    e->buscarCamino(matriz);
    listaEstudiantes.push_back(e);*/
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

void Tablero::on_Stats_clicked()
{
    Poblacion *xd = new Poblacion("lol");
    Stats *eje = new Stats();
    eje->setModal(true);
    eje->setPoblacion(xd);
    eje->setData();
    eje->show();
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
    /*Estudiante *e = new Estudiante();
    e->setParent(this);
    e->buscarCamino(matriz);
    listaEstudiantes.push_back(e);*/


    Poblacion *e = new Poblacion("lol");

    for(int i = 0; i < 10; i++){
        e->nuevageneracion();
    }
    generaciones = e->getGeneraciones();
    for(int i= 0 ; i < generaciones.size(); i++){
        for(int j=0; j < generaciones[i]->getSize(); j++){
            generaciones[i]->recorrer(j)->setParent(this);
        }
    }

}


