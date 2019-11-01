#include "estudiante.h"

#include <math.h>
#include <time.h>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

//#include "list.h"

using namespace std;


/**
 * Representa un Estudiante
 *
 * @since 24/10/19
 */


/**
 * Constructor de Estudiante.
 * @param generacion
 */
Estudiante::Estudiante(int generacion)
{
    if (generacion == 1){

        setTipo();
        if(getTipo() == 1){ /// Ogro

            int random = 5 + rand() % (5-1); /// 5 = Resistentes
            setResistenciaArqueros(random);

            random = 1 + rand() % (5-1); /// 1 = Debiles
            setResistenciaMagos(random);

            random = 1 + rand() % (5-1); /// 1 = Debiles
            setResistenciaArtilleros(random);

            random = 1 + rand() % (5-1); /// 1 = Debiles
            setResistenciaLanzaFuegos(random);

            random = 1 + rand() % (5-1); /// 1 = Lentos
            setVelocidad(random);
        }
        else if(getTipo() == 2){ /// Elfo

            int random = 5 + rand() % (5-1); /// 5 = Resistentes
            setResistenciaArqueros(random);

            random = 5 + rand() % (5-1); /// 5 = Resistentes
            setResistenciaMagos(random);

            random = 1 + rand() % (5-1); /// 1 = Debiles
            setResistenciaArtilleros(random);

            random = 1 + rand() % (5-1); /// 1 = Debiles
            setResistenciaLanzaFuegos(random);

            random = 3 + rand() % (5-1); /// 3 = Velocidad media
            setVelocidad(random);
        }
        else if(getTipo() == 3){ /// Harpia

            int random = 3 + rand() % (5-1); /// 3 = Resistencia media(Solo son atacados por Artilleros y lanzafuego)
            setResistenciaArqueros(random);

            random = 3 + rand() % (5-1); /// 3 = Resistencia media(Solo son atacados por Artilleros y lanzafuego)
            setResistenciaMagos(random);

            random = 3 + rand() % (5-1); /// 3 = Resistencia media(Solo son atacados por Artilleros y lanzafuego)
            setResistenciaArtilleros(random);

            random = 3 + rand() % (5-1); /// 3 = Resistencia media(Solo son atacados por Artilleros y lanzafuego)
            setResistenciaLanzaFuegos(random);

            random = 3 + rand() % (5-1); /// 3 = Velocidad media
            setVelocidad(random);
        }
        else if(getTipo() == 4){ /// Mercenario

            int random = 5 + rand() % (5-1); /// 5 = Resistentes
            setResistenciaArqueros(random);

            random = 5 + rand() % (5-1); /// 5 = Resistentes
            setResistenciaMagos(random);

            random = 5 + rand() % (5-1); /// 5 = Resistentes
            setResistenciaArtilleros(random);

            random = 1 + rand() % (5-1); /// 1 = Debiles
            setResistenciaLanzaFuegos(random);

            random = 5 + rand() % (5-1); /// 5 = Muy Rapido
            setVelocidad(random);
        }
        setVida(generacion);
    }
    else {
        cout << "Introduzca los padres si no es la primera generacion" << endl;
    }
}


///Conversiones

/**
 * Convierte un numero de decimal a binario.
 * @param n
 * @return resultado
 */
string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string res;
    for (int i = 3; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            res+="1";
        else
            res+= "0";
    }
    return res;
}

/**
 * Convierte un numero de binario a decimal.
 * @param binario
 * @return resultado
 */
int binToDec(int binario)
{
    int exp,digito;
    int decimal;

    exp=0;
    decimal=0;
    while(((int)(binario/10))!=0)
    {

        digito = (int)binario % 10;
        decimal = decimal + digito * pow(2,exp);
        exp++;
        binario=(int)(binario/10);
    }
    decimal=decimal + binario * pow(2,exp);
    //cout << endl << "Decimal: " << decimal << endl;
    return decimal;
}

/**
 * Constructor de Estudiante.
 * @param generacion
 * @param padre1
 * @param padre2
 */
Estudiante::Estudiante(int generacion, Estudiante *padre1, Estudiante *padre2)
{
    int random1 = 1 + rand() % (100-1);
    if (generacion == 1){
        cout << "No introduzca padres, ya que no es de la primera generacion" << endl;
    }
    else {
        string cromosomaVelo1 = decToBinary(padre1->getVelocidad()).substr(0,2);
        string cromosomaVelo2 = decToBinary(padre2->getVelocidad()).substr(2,4);

        string cromosomaRArq1 = decToBinary(padre1->getResistenciaArqueros()).substr(0,2);
        string cromosomaRArq2 = decToBinary(padre2->getResistenciaArqueros()).substr(2,4);

        string cromosomaRM1 = decToBinary(padre1->getResistenciaMagos()).substr(0,2);
        string cromosomaRM2 = decToBinary(padre2->getResistenciaMagos()).substr(2,4);

        string cromosomaRArt1 = decToBinary(padre1->getResistenciaArtilleros()).substr(0,2);
        string cromosomaRArt2 = decToBinary(padre2->getResistenciaArtilleros()).substr(2,4);

        string cromosomaRLF1 = decToBinary(padre1->getResistenciaLanzaFuegos()).substr(0,2);
        string cromosomaRLF2 = decToBinary(padre2->getResistenciaLanzaFuegos()).substr(2,4);

        string *arr[]={&cromosomaVelo1,&cromosomaVelo2,&cromosomaRArq1,&cromosomaRArq2,&cromosomaRM1,&cromosomaRM2,&cromosomaRArt1,&cromosomaRArt2,&cromosomaRLF1,&cromosomaRLF2};
        //cout<<padre1->getInteligencia()<<endl;
        //cout<<cromosomaInte1<<endl;
        if (random1<=5){
            int random2 = 0 + rand() % (7-0);
            mutacion(arr[random2]);
            setMutante(true);
        }
        setVelocidad(binToDec(atoi((cromosomaVelo1+cromosomaVelo2).c_str())));
        setResistenciaArqueros(binToDec(atoi((cromosomaRArq1+cromosomaRArq2).c_str())));
        setResistenciaMagos(binToDec(atoi((cromosomaRM1+cromosomaRM2).c_str())));
        setResistenciaArtilleros(binToDec(atoi((cromosomaRArt1+cromosomaRArt2).c_str())));
        setResistenciaLanzaFuegos(binToDec(atoi((cromosomaRLF1+cromosomaRLF2).c_str())));
        setVida(generacion);
    }
}


///Metodos


/**
 * Genera una mutación en el algortimo genético.
 * @param gen
 */
void Estudiante::mutacion(string *gen){
    cout<<"mutacion de gen: "<<*gen;
    int random = rand() % 2;
    if (random==1){
        if(gen->substr(0,1)=="1"){
            *gen="0"+gen->substr(1,2);
        }else {
            *gen="1"+gen->substr(1,2);
        }
    }else {
        if(gen->substr(1,2)=="1"){
            *gen=gen->substr(0,1)+"0";
        }else {
            *gen=gen->substr(0,1)+"1";
        }
    }
    cout<<" a: "<<*gen<<endl;
}

///Getters & Setters


void Estudiante::setNombre(string Nombre)
{
    nombre = Nombre;
}


void Estudiante::setVida(int generation)
{
    if(getGeneracion() == generation - 5){
        muerto=true;
    }
    else{
        int Vida = 0;
        Vida += 2*resistenciaArqueros;
        Vida += 2*resistenciaMagos;
        Vida += 2*resistenciaArtilleros;
        Vida += 2*resistenciaLanzaFuegos;
        vida = Vida;
    }

}


void Estudiante::setVelocidad(int Velocity)
{
    velocidad = Velocity;
}

void Estudiante::setResistenciaArqueros(int RArq)
{
    resistenciaArqueros = RArq;
}

void Estudiante::setResistenciaMagos(int RM)
{
    resistenciaMagos = RM;
}
void Estudiante::setResistenciaArtilleros(int RArt)
{
    resistenciaArtilleros = RArt;
}
void Estudiante::setResistenciaLanzaFuegos(int RLF)
{
    resistenciaLanzaFuegos = RLF;
}

void Estudiante::morir(){
    muerto=true;
}

bool Estudiante::getMuerto(){
    return muerto;
}

string Estudiante::getNombre()
{
    return nombre;
}


int Estudiante::getVida()
{
    return vida;
}


int Estudiante::getVelocidad()
{
    return velocidad;
}

int Estudiante::getResistenciaArqueros()
{
    return resistenciaArqueros;
}

int Estudiante::getResistenciaMagos()
{
    return resistenciaMagos;
}

int Estudiante::getResistenciaArtilleros()
{
    return resistenciaArtilleros;
}

int Estudiante::getResistenciaLanzaFuegos()
{
    return resistenciaLanzaFuegos;
}


vector<int> Estudiante::getPathToGoal() {
    return pathToGoal;
}

void Estudiante::setPathToGoal(vector<int> _pathToGoal) {
    pathToGoal = _pathToGoal;
}

void Estudiante::setNombrePadre1(string _nombre) {
    nombrePadre1 = _nombre;
}

void Estudiante::setNombrePadre2(string _nombre) {
    nombrePadre2 = _nombre;
}

string Estudiante::getNombrePadre1() {
    return nombrePadre1;
}

string Estudiante::getNombrePadre2() {
    return nombrePadre2;
}

void Estudiante::setGeneracion(int _generacion) {
    generacion = _generacion;
}

int Estudiante::getGeneracion() {
    return generacion;
}

bool Estudiante::getMutante()
{
    return mutante;
}

int Estudiante::getTipo()
{
    return tipo;
}


/* Metodo para setear tipo a estudiante que no es de la primera generacion
 */

void Estudiante::setTipo()
{
    int value = rand() % 4 +1;
    tipo = value;
}

/* Metodo para setear tipo a estudiante que no es de la primera generacion
 * @param tipoPadre1
 * @param tipoPadre2
 */

void Estudiante::setTipo(int tipoPadre1, int tipoPadre2){
    if(tipoPadre1 == tipoPadre2){
        tipo = tipoPadre1;
    }
    else{
        int value = rand() % 2 +1;
        if (value == 1){
            tipo = tipoPadre1;
        }
        else{
            tipo = tipoPadre2;
        }
    }
}

void Estudiante::setMutante(bool value)
{
    mutante = value;
}

Cuadricula* Estudiante::getCuadricula() {
    return cuadricula;
}

void Estudiante::setCuadricula(Cuadricula* _cuadricula) {
    cuadricula = _cuadricula;
}
