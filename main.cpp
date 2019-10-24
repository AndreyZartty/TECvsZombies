#include "mainwindow.h"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    int random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    random = rand() % 4 + 1;
    cout << random << endl;
    return a.exec();
}
