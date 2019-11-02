#ifndef NODO_H
#define NODO_H
#include <QWidget>
#include <QToolButton>
#include <QDebug>
#include <curso.h>
#include <crearcurso.h>
#include <vector>

class estudiante;
class Tablero;

class nodo;
class nodo : public QWidget
{
    Q_OBJECT

public slots:
    void onClick();
    void modificarNodo();
    void atacar();

public:
    nodo(int corx, int cory);
    void setParent(Tablero*);
    void setVigilante(curso*);
    bool isFree();
    void agregarEstudiante(estudiante *);
    void eliminarEstudiante(estudiante *);
    bool tieneVigilante();
    void solicitarEvaluacion(nodo*);

    QToolButton * boton;
    curso *Curso= nullptr;
    nodo* matriz[10][10];
    int x;
    int y;
    int col;
    int fil;
    Tablero* par;
    vector<estudiante*> listaEstudiantes;


signals:
    void cursoCreado(nodo*);

private:

    curso* vigilante=nullptr;
    crearCurso *p;
};

#endif // NODO_H
