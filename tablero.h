#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <nodo.h>
#include <vector>
#include <workerrevisar.h>
#include <evaluacion.h>


class estudiante;

namespace Ui {
class Tablero;
}

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    void crearMatriz();
    void crearEvaluaciones();
    void varas();
    ~Tablero();
public slots:
    void generarAdyacentes(nodo*);
    void revisaNodos();
    void crearEva(nodo*);


private:
    Ui::Tablero *ui;
    nodo* matriz[10][10];
    QPropertyAnimation *animation;
    workerRevisar *revisa;
    vector<estudiante*> listaEstudiantes;
    vector<Evaluacion*> listaEvaluaciones;
    Evaluacion *p;

};

#endif // TABLERO_H
