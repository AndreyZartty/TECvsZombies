#include "workerrevisar.h"
#include <unistd.h>
workerRevisar::workerRevisar(QObject *parent):QThread (parent)
{
    terminado=false;
}

void workerRevisar::run(){
    while(terminado==false){
        usleep(100000);
        emit progreso();
    }
}
