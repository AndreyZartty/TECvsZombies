#ifndef TORRE_H
#define TORRE_H


/**
 * Header de Torre
 *
 * @since 02/05/19
 */


class Torre {

    int tipo;

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

public:
    Torre(int tipo);

    ///Getters & Setters

    int getTipo();
    void setEvaluaciones();
    void Upgrade();
    int getEvaluacion();


};

#endif // TORRE_H
