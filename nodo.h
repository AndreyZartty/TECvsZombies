#ifndef NODO_H
#define NODO_H
#include <QWidget>
#include <QToolButton>
#include <QDebug>
#include <curso.h>
#include <crearcurso.h>
#include <modificarcurso1.h>


class Tablero;

class nodo;
class nodo : public QWidget
{
    Q_OBJECT

public slots:
    void onClick();
    void modificarNodo();

    void actualizar();
    void eliminar();

public:
    nodo(int corx, int cory);
    void setParent(Tablero*);
    void eliminaCurso(Tablero*);
    void setVigilante(curso*);
    QToolButton * boton;
    curso *Curso= nullptr;
    nodo* matriz[10][10];
    int x;
    int y;
    int col;
    int fil;


signals:
    void cursoCreado(nodo*);
    void cursoEliminado(nodo*);
    void cursoActualizado(nodo*);

private:
    curso* vigilante;
    crearCurso *pantallaAgregarCurso;
    modificarCurso1 *pantallaModificarCurso;
};

#endif // NODO_H
