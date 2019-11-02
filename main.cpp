#include "mainwindow.h"
#include "poblacion.h"
#include "tablero.h"


#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tablero w;
    w.show();
    int random = 28 / 10;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;

    Poblacion *xd = new Poblacion("lol");
    xd->nuevageneracion();
    xd->nuevageneracion();


    return a.exec();
}
