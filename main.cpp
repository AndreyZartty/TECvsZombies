#include "tablero.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tablero w;
    w.show();

    return a.exec();
}
