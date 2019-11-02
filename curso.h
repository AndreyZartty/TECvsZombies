#ifndef CURSO_H
#define CURSO_H
#include <QPixmap>
#include <string>
#include <evaluacion.h>


using namespace std;

class curso : public QWidget
{
    Q_OBJECT
public:
    curso();
    string nombre;
    QPixmap imagen;
    int alcance;
    Evaluacion *examen;

};

#endif // CURSO_H
