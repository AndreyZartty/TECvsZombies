#ifndef CURSO_H
#define CURSO_H
#include <QPixmap>
#include <string>

using namespace std;


class curso
{
public:
    curso();
    string nombre;
    QPixmap imagen;
    int alcance;
};

#endif // CURSO_H
