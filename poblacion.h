#ifndef POBLACION_H
#define POBLACION_H

#include "estudiante.h"
#include "list.h"
#include <vector>


class Poblacion
{
public:
    Poblacion(string _nombrePoblacion);
    int getGeneracion();
    void setGeneracion(int Generacion);
    void insertarEstudiante(Estudiante* estudiante);
    void insertarCopia(Estudiante* estudiante);
    List getEstudiantes();
    List getCopia();
    List getPadres();
    void setPadres();
    void setMejor();
    Estudiante* getMejor();
    string getNombrePoblacion();
    void nuevageneracion();
    vector <List*> getGeneraciones();



private:
    string nombrePoblacion;
    List estudiantes;
    List copia;
    List padres;
    int generacion=1;
    Estudiante* mejor;
    vector <List*> generaciones;
};

#endif // POBLACION_H
