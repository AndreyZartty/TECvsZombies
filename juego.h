#ifndef JUEGO_H
#define JUEGO_H


#include "estudiante.h"
#include "poblacion.h"
#include "cuadricula.h"
#include "astar.h"
#include "backtracking.h"
#include "list.h"


/**
 * Header de Juego
 *
 * @since 30/04/17
 */

/**
 * Constructor de Juego;;
 */
class Juego {
private:

    Cuadricula* cuadricula;
    AStar* aStarAlgorithm;
    Backtracking* backtrackingAlgorithm;
    Node* nodoInicio;
    Node* nodoFinal;
    Poblacion *poblacion1;
    List MejoresP1;
    Estudiante *EstudianteAStar;
    int muertos;



public:

    ///Constructor
    Juego();

    ///Metodos
    void doAStar();
    void doBacktracking();
    void generateTowers(int ctt);

    ///Getters & Setters
    Cuadricula* getCuadricula();
    void setCuadricula(Cuadricula* _cuadricula);
    AStar* getAStarAlgorithm();
    void setAStarAlgorithm(AStar* _aStarAlgorithm);
    Backtracking* getBacktrackingAlgorithm();
    void setBacktrackingAlgorithm(Backtracking* _backtrackingAlgorithm);
    Poblacion* getPoblacion1();
    List getMejoresP1();
    void setMejoresP1(List mejores);
    void setEstudianteAStar(Estudiante *aStar);
    Estudiante *getEstudianteAStar();
    int getMuertos();


};

#endif // JUEGO_H
