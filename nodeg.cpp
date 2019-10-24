#include "nodeg.h"

NodeG :: NodeG(NodeG* _nxtPtr, Estudiante* _data) {
    nxtPtr = _nxtPtr;
    data = _data;
}
void NodeG::set_data(Estudiante* _data) {
    data = _data;
}
void NodeG::set_nxtNd(NodeG* _nxtNd) {
    nxtPtr = _nxtNd;
    //std::cout<<&_nxtNd<<std::endl;
}
Estudiante* NodeG::get_data() {
    //std::cout<<data<<std::endl;
    return data;
}
NodeG* NodeG::get_nxtPtr() {
    //std::cout<<nxtPtr<<std::endl;
    return nxtPtr;
}
