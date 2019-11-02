#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <nodo.h>
#include <vector>
#include <workerrevisar.h>

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
    void revisaNodos();
private:
    Ui::Tablero *ui;
    nodo* matriz[10][10];
    QPropertyAnimation *animation;
    workerRevisar *revisa;
    vector<estudiante*> listaEstudiantes;

};

#endif // TABLERO_H
