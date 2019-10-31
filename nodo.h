#ifndef NODO_H
#define NODO_H
#include <QWidget>
#include <QToolButton>
#include <QDebug>
#include <curso.h>
#include <crearcurso.h>

class nodo;
class nodo : public QWidget
{
    Q_OBJECT

public slots:
    void onClick();
    void modificarNodo();

public:
    nodo(int corx, int cory);

    QToolButton * boton;
    curso *Curso= nullptr;
private:
    int x;
    int y;
    crearCurso *p;
};

#endif // NODO_H
