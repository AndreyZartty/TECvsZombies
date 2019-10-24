#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "nodeg.h"
#include "estudiante.h"

class List{

public:
    NodeG* getPointerHead();
    void setPointerHead(NodeG* head);
    NodeG* getLast();
    void insertFirst(Estudiante *estudiante);
    int getSize();
    void insertLast(Estudiante *estudiante);
    Estudiante* recorrer(int indice);
    Estudiante* sacar(int indice);
    void swap(Estudiante *xp, Estudiante *yp);
    void bubbleSort();
    void vaciar();

private:

    NodeG* pointerHead= nullptr;

};
#endif // LIST_H
