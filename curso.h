#ifndef CURSO_H
#define CURSO_H
#include <QPixmap>
#include <string>

using namespace std;


class curso
{
public:
    string nombre;
    QPixmap imagen;
    int tipo;
    curso(int tipo);

    ///Getters & Setters

    int getTipo();
    void setEvaluaciones();
    bool Upgrade();
    int getEvaluacion();
    int getAlcance();
    int getUpgrade();

private:
    int cantidadCreditos;
    int horasDedicadas;
    int exigencia;
    int velocidad;
    int alcance;
    int tiempoRegeneracion;
    int tiempoRecarga;
    int upgrade = 1;
    int evaluacion;


};

#endif // CURSO_H
