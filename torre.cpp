#include "torre.h"
#include <iostream>

using namespace std;

/**
 * Representa una Torre
 *
 * @since 02/05/19
 */

Torre::Torre(int _tipo) {
    tipo = _tipo;
    if(tipo == 1){ /// TIPO 1 : Arquero
        cantidadCreditos = 1;
        horasDedicadas = 3;
        exigencia = 1;
        velocidad = 1;
        alcance = 1;
        tiempoRegeneracion = 5;
        tiempoRecarga = 5;
    }
    else if(tipo == 2){ /// TIPO 2 : Mago
        cantidadCreditos = 2;
        horasDedicadas = 6;
        exigencia = 3;
        velocidad = 1;
        alcance = 2;
        tiempoRegeneracion = 5;
        tiempoRecarga = 5;
    }
    else if(tipo == 3){ /// TIPO 3 : Artillero
        cantidadCreditos = 3;
        horasDedicadas = 9;
        exigencia = 5;
        velocidad = 3;
        alcance = 2;
        tiempoRegeneracion = 3;
        tiempoRecarga = 3;
    }
    else if(tipo == 4){ /// TIPO 4 : Lanza Fuego
        cantidadCreditos = 4;
        horasDedicadas = 16;
        exigencia = 5;
        velocidad = 5;
        alcance = 3;
        tiempoRegeneracion = 1;
        tiempoRecarga = 1;
    }
    setEvaluaciones();
}


int Torre::getTipo() {
    return tipo;
}

void Torre::setEvaluaciones() {
    int prom = cantidadCreditos + horasDedicadas + exigencia + velocidad + tiempoRecarga + tiempoRegeneracion;
    evaluacion = prom/10;
}

void Torre::Upgrade() {
    if(upgrade == 3){
        cout << "Esta torre esta en su maximo nivel" << endl;
    }
    else{
        upgrade++;
        horasDedicadas += 5;
        exigencia += 5;
        setEvaluaciones();
    }
}

int Torre::getEvaluacion()
{
    return evaluacion;
}
