#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <QPropertyAnimation>
#include <QLabel>
#include <tablero.h>
#include <nodo.h>
#include <vector>
#include <QWidget>

#include <iostream>
#include <vector>
#include "cuadricula.h"

#define ZONE_SIZE 10

using namespace std;

class Estudiante;

class Estudiante : public QWidget
{
    Q_OBJECT

public:
    ///Constructores
    Estudiante(int generacion);
    Estudiante(int generacion, Estudiante *padre1, Estudiante *parte2);

    ///Metodos
    void morir();
    void mutacion(string *gen);
    void restarResistencia(int valor);

    ///Getters & Setters
    void setNombre(string Nombre);
    void setVida(int generation);

    void setVelocidad(int Velocity);
    void setResistenciaArqueros(int RArq);
    void setResistenciaMagos(int RM);
    void setResistenciaArtilleros(int RArt);
    void setResistenciaLanzaFuegos(int RLF);

    void setPathToGoal(vector<int> _pathToGoal);
    void setNombrePadre1(string _nombre);
    void setNombrePadre2(string _nombre);
    void setGeneracion(int _generacion);

    void setMutante(bool muto);
    void setTipo();
    void setTipo(int tipoPadre1, int tipoPadre2);



    void setCuadricula(Cuadricula* _cuadricula);

    int getVida();
    int getVelocidad();
    int getResistenciaArqueros();
    int getResistenciaMagos();
    int getResistenciaArtilleros();
    int getResistenciaLanzaFuegos();
    string getNombre();
    bool getMuerto();
    vector<int> getPathToGoal();
    Cuadricula* getCuadricula();
    string getNombrePadre1();
    string getNombrePadre2();
    int getGeneracion();
    bool getMutante();
    int getTipo();
    void caminar(nodo*,nodo*);
    QLabel *h;
    void setParent(Tablero*);
    void buscarCamino();
    void salioNodoActual();
    void setNodoActual(nodo*);
    void siendoEvaluado(int impacto);
    nodo *actual=nullptr;
    Estudiante();
    vector<nodo*> camino;




private:

    string nombre;
    int tipo; ///Tipo #1: Ogro, Tipo #2: Elfo Oscuro, Tipo #3: Harpia, Tipo #4: Mercenario
    int vida;
    int velocidad;
    int resistenciaArqueros;
    int resistenciaMagos;
    int resistenciaArtilleros;
    int resistenciaLanzaFuegos;

    bool muerto=false;

    bool mutante = false;
    vector<int> pathToGoal;

    Cuadricula* cuadricula;
    /*int hits[ZONE_SIZE*ZONE_SIZE][24];*/

    string nombrePadre1;
    string nombrePadre2;

    int generacion;
    QPropertyAnimation *animation;

    int numNodo=0;

public slots:
    void termino();


};

#endif // ESTUDIANTE_H
