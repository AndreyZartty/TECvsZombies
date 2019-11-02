#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <nodo.h>
#include <vector>
#include <workerrevisar.h>
class List;
class Juego;



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
    ~Tablero();
public slots:
    void generarAdyacentes(nodo*);
    void eliminarAdyacentes(nodo*);
    void on_Stats_clicked();
    void revisaNodos();
    void on_aprobacionIndividual_clicked();
    void on_aprobacionColectiva_clicked();
private:
    Ui::Tablero *ui;
    nodo* matriz[10][10];
    QPropertyAnimation *animation;
    workerRevisar *revisa;
    vector<Estudiante*> listaEstudiantes;
    vector<List*> generaciones;
    Juego *game;
    int gen=1;

};

#endif // TABLERO_H
