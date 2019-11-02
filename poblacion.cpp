#include "poblacion.h"

Poblacion::Poblacion(string _nombrePoblacion)
{
    List *listagen = new List();
    nombrePoblacion = _nombrePoblacion;
    char vocales [] = {"aeiou"};
    char consonantes [] = {"bcdfghjlmnprstv"};
    string nombre;
    setGeneracion(1);
    for (int i=0; i <10; i++){
        nombre = "";
        Estudiante* estudiante = new Estudiante(getGeneracion());
        for (int i = 3; i > 0; i--){
            int r1 = rand() % 14;
            int r2 = rand() % 4;
            char letra1 = consonantes[r1];
            char letra2 = vocales[r2];
            string s1 (1, letra1);
            string s2 (1, letra2);
            nombre = nombre+s1+s2;
        }
        estudiante->setNombre(nombre);
        estudiante->setGeneracion(generacion);
        insertarEstudiante(estudiante);
        insertarCopia(estudiante);
        listagen->insertLast(estudiante);
        cout<< "Se ha creado el estudiante: "<< estudiante->getNombre() <<" gen: "<<getGeneracion()<<" vida: "<<estudiante->getVida()<< " tipo: " << estudiante->getTipo() <<endl ;
        if(estudiante->getMutante()){
            mutantes++;
        }
    }
    setMejor();
    generaciones.push_back(listagen);
    setPadres();
    probaMut = (1.0000/99.0000) / 10.0000*generacion;
    probInv = (1.0000/149.0000) / 10.0000*generacion;


}

int Poblacion::getGeneracion()
{
    return generacion;
}

void Poblacion::setGeneracion(int Generacion)
{
    generacion = Generacion;
}

void Poblacion::insertarEstudiante(Estudiante *estudiante)
{
    estudiantes.insertLast(estudiante);
}

void Poblacion::insertarCopia(Estudiante *estudiante)
{
    copia.insertLast(estudiante);
}

List Poblacion::getEstudiantes()
{
    return estudiantes;
}

List Poblacion::getPadres(){
    return padres;
}

void Poblacion::setPadres(){
    //padres.getPointerHead()->set_nxtNd(nullptr);
    //padres.setPointerHead(nullptr);
    padres.vaciar();
    estudiantes.bubbleSort();
    for (int i=8;i>0;i--) {
        padres.insertFirst(estudiantes.recorrer(i));
    }
    /*
    List ltemp = gladiadores;
    Gladiador *gtemp;
    for (int i=8;i>0;i--) {
        gtemp=ltemp.recorrer(0);
        int x;
        for (int j=0;j<ltemp.getSize();j++) {
            if(ltemp.recorrer(j)->getResistencia()>gtemp->getResistencia()){
                gtemp=ltemp.recorrer(j);
                x= j;
            }
        }
        //ltemp.sacar(x);
        padres.insertLast(ltemp.sacar(x));
    }
    */
    for (int h=0;h<padres.getSize();h++) {
        cout<<"ltemp "<<padres.recorrer(h)->getNombre()<<endl;
    }

}

string Poblacion::getNombrePoblacion(){
    return nombrePoblacion;
}

void Poblacion::setMejor(){
    Estudiante* temp;
    mejor=estudiantes.recorrer(0);
    for(int i=0;i<estudiantes.getSize();i++){
        temp = estudiantes.recorrer(i);
        if(temp->getVida()>mejor->getVida()){
            mejor=temp;
        }
    }
}

Estudiante* Poblacion::getMejor(){
    cout<<"El mejor de la poblacion "<< nombrePoblacion <<" es: "<<mejor->getNombre()<<endl;
    estudiantes.bubbleSort();
    return mejor;
}

void Poblacion::nuevageneracion(){
    //cout<<"oooh1"<<endl;
    setGeneracion(generacion+=1);
    //cout<<generacion<<endl;
    setPadres();

    List *listgeneracion = new List();

    Estudiante* temp;
    for (int i=0;i<estudiantes.getSize();i++) {
        if (estudiantes.recorrer(i)->getGeneracion() == getGeneracion()-5 || estudiantes.recorrer(i)->getMuerto()){

        }else {
            temp = estudiantes.recorrer(i);
        }
    }

    char vocales [] = {"aeiou"};
    char consonantes [] = {"bcdfghjlmnprstv"};
    string nombre;

    for (int i=0; i <8; i+=2){
        nombre = "";
        Estudiante* estudiante = new Estudiante(getGeneracion(),padres.recorrer(i),padres.recorrer(i+1));
        for (int i = 3; i > 0; i--){
            int r1 = rand() % 14;
            int r2 = rand() % 4;
            char letra1 = consonantes[r1];
            char letra2 = vocales[r2];
            string s1 (1, letra1);
            string s2 (1, letra2);
            nombre = nombre+s1+s2;
        }
        estudiante->setNombre(nombre);
        estudiante->setGeneracion(generacion);
        estudiante->setNombrePadre1(padres.recorrer(i)->getNombre());
        estudiante->setNombrePadre2(padres.recorrer(i+1)->getNombre());
        insertarEstudiante(estudiante);
        insertarCopia(estudiante);
        listgeneracion->insertLast(estudiante);
        cout<< "Se ha creado el estudiante: "<< estudiante->getNombre() <<" gen: "<<getGeneracion()<<" vida: "<<estudiante->getVida()<< " tipo: " << estudiante->getTipo() << " hijo de: "<< estudiante->getNombrePadre1() << " y " << estudiante->getNombrePadre2() <<endl;
        if(estudiante->getMutante()){
            mutantes++;
        }
    }

    for (int i=0; i <8; i+=2){
        nombre = "";
        Estudiante* estudiante = new Estudiante(getGeneracion(),padres.recorrer(i+1),padres.recorrer(i));
        for (int i = 3; i > 0; i--){
            int r1 = rand() % 14;
            int r2 = rand() % 4;
            char letra1 = consonantes[r1];
            char letra2 = vocales[r2];
            string s1 (1, letra1);
            string s2 (1, letra2);
            nombre = nombre+s1+s2;
        }
        estudiante->setNombre(nombre);
        estudiante->setGeneracion(generacion);
        estudiante->setNombrePadre1(padres.recorrer(i+1)->getNombre());
        estudiante->setNombrePadre2(padres.recorrer(i)->getNombre());
        insertarEstudiante(estudiante);
        insertarCopia(estudiante);
        listgeneracion->insertLast(estudiante);
        cout<< "Se ha creado el estudiante: "<< estudiante->getNombre() <<" gen: "<<getGeneracion()<<" vida: "<<estudiante->getVida()<< " tipo: " << estudiante->getTipo() << " hijo de: "<< estudiante->getNombrePadre1() << " y " << estudiante->getNombrePadre2() <<endl;
        if(estudiante->getMutante()){
            mutantes++;
        }
    }
    generaciones.push_back(listgeneracion);
    estudiantes.bubbleSort();
    probaMut = (1/99) / 10*generacion;
    probInv = (1/149) / 10*generacion;
}

vector <List*> Poblacion::getGeneraciones() {
    return generaciones;
}

int Poblacion::getMutantes()
{
    return mutantes;
}

double Poblacion::getProbaMut()
{
    return probaMut;
}

double Poblacion::getProbaInv()
{
    return probInv;
}
