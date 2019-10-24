#ifndef NODEG_H
#define NODEG_H

#include "estudiante.h"

class NodeG {
public:
    NodeG();
    NodeG(NodeG* _nxtPtr, Estudiante* _data);
    void set_data(Estudiante* _data);
    void set_nxtNd(NodeG* node);
    Estudiante* get_data();
    NodeG* get_nxtPtr();
private:
    Estudiante* data;
    NodeG* nxtPtr;
};

#endif // NODEG_H
