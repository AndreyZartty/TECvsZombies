#include "juego.h"

/**
 * Representa el Juego
 *
 * @since 30/04/19
 */


/**
 * Constructor de Juego
 */
Juego::Juego() {

    cuadricula = new Cuadricula();
    cuadricula->addPosibleTowerIdList();
    nodoInicio = cuadricula->getNodoInicial();
    nodoFinal = cuadricula->getNodoFinal();
    aStarAlgorithm = new AStar(cuadricula);
    backtrackingAlgorithm = new Backtracking(cuadricula);

    ///Poblaciones
    poblacion1 = new Poblacion("Stark");

    MejoresP1 = poblacion1->getPadres();

    for(int i = 0; i < MejoresP1.getSize() ; i++){
        MejoresP1.recorrer(i)->setCuadricula(cuadricula);
    }
    MejoresP1.bubbleSort();
    int random = rand() % (MejoresP1.getSize()-1);
    EstudianteAStar = MejoresP1.recorrer(random);
    MejoresP1.swap(EstudianteAStar,MejoresP1.getLast()->get_data());
}


///Metodos


/**
 * Inicia el algoritmo A*.
 */
void Juego::doAStar() {

    ///Repone sus booleans
    aStarAlgorithm->setInitializedStartGoal(false);
    aStarAlgorithm->setFoundGoal(false);

    ///Busca el camino
    aStarAlgorithm->findPath(nodoInicio, nodoFinal);

    ///Se rota el path
    aStarAlgorithm->rotatePath();
    ///Ingresa el path a su respectivo gladiador
    EstudianteAStar->setPathToGoal(aStarAlgorithm->getPathToGoal());

    /*  ///Se generara una matriz con los hits que le hacen las torres y sus respectivos tipos
    gladiador1->generateHits();*/

}

/**
 * Inicia el algoritmo Backtracking.
 */
void Juego::doBacktracking() {

    ///Repone sus booleans
    backtrackingAlgorithm->setInitializedStartGoal(false);
    backtrackingAlgorithm->setFoundGoal(false);

    ///Busca el camino
    backtrackingAlgorithm->findPath(nodoInicio,nodoFinal);

    ///Se rota el path
    backtrackingAlgorithm->rotatePath();
    ///Ingresa el path a su respectivo gladiador
    for(int i = 0; i < MejoresP1.getSize()-1 ; i++){
        MejoresP1.recorrer(i)->setPathToGoal(aStarAlgorithm->getPathToGoal());
    }

    /* ///Se generara una matriz con los hits que le hacen las torres y sus respectivos tipos
    gladiador2->generateHits();*/

}

/**
 * Inicia ambos algoritmos y previamente establece todas sus condiciones de inicio
 */
void Juego::generateTowers(int ctt) {

    cout << "Generating Towers\n" << endl;

    ///Se crea un contador
    int c = 0;

    ///Cantidad de Torres
    int ct = ctt;

    while (c < ct) {

        ///Genera las Torres
        int evaluatingTower = cuadricula->newTower();

        ///Se evalua si hay mas posibilidades para colocar torres
        if (evaluatingTower == -1) {
            cout << "No se pueden asignar mas torres" << endl;
            c=ct;
        }
        else {

            ///Imprime solo las torres
            cuadricula->printTorres();

            for (int i = 0 ; i < cuadricula->getSize() ; i++) {
                for (int j = 0 ; j < cuadricula->getSize() ; j++) {

                    int id = ((i) * (cuadricula->getSize()) + (j));

                    cuadricula->getNode(id)->setInAStarPath(false);
                    cuadricula->getNode(id)->setInBacktrackingPath(false);

                }

            }

            ///Hace el algortimo A*
            doAStar();
            aStarAlgorithm->showPath();

            ///Hace el algoritmo Backtracking
            doBacktracking();
            backtrackingAlgorithm->showPath();

            ///Verificacion de si el algortimo A* ha sido completado
            if (aStarAlgorithm->isFoundGoal()) {
                if (backtrackingAlgorithm->isFoundGoal()) {
                    cout << "Backtracking Completed" << endl;
                    c++;
                } else {

                    ///Rechaza la torre evaluada
                    cout << "Backtracking Failed" << endl;
                    cout << "La torre de id "<< evaluatingTower << " bloquea el camino" << endl;
                    cuadricula->addToVerifiedNot(evaluatingTower);
                    cuadricula->deleteTower(evaluatingTower);

                }
                cout << "A* Completed" << endl;
            } else {
                ///Rechaza la torre evaluada
                cout << "A* Failed" << endl;
                cout << "La torre de id "<< evaluatingTower << " bloquea el camino" << endl;
                cuadricula->addToVerifiedNot(evaluatingTower);
                cuadricula->deleteTower(evaluatingTower);
            }

            ///Verificacion de si el algortimo Backtracking ha sido completado

        }

    }

    cuadricula->resetVerifiedNot();

    ///Imprime los caminos
    cuadricula->printTorres();

    ///IMPRIMIR VECTOR DE TORRES
    cout << "Tower Id's: ";
    for (int i = 0; i < cuadricula->getTowerIdList().size(); i++) {

        if (i == 0) {
            cout << "[" << cuadricula->getTowerIdList()[i] << ", ";
        } else if (i == cuadricula->getTowerIdList().size() - 1) {
            cout << cuadricula->getTowerIdList()[i] << "]\n" << endl;
        } else {
            cout << cuadricula->getTowerIdList()[i] << ", ";
        }

    }

    ///IMPRIMIR VECTOR DE POSIBLES TORRES

    cout << "PosibleTower Id's: ";
    for (int i = 0; i < cuadricula->getPosibleTowerIdList().size(); i++) {

        if (i == 0) {
            cout << "[" << cuadricula->getPosibleTowerIdList()[i] << ", ";
        } else if (i == cuadricula->getPosibleTowerIdList().size() - 1) {
            cout << cuadricula->getPosibleTowerIdList()[i] << "]\n" << endl;
        } else {
            cout << cuadricula->getPosibleTowerIdList()[i] << ", ";
        }

    }

}


///Getters & Setters


/**
 * Getter de Cuadricula de Juego.
 * @return Cuadricula
 */
Cuadricula* Juego::getCuadricula() {
    return cuadricula;
}

/**
 * Setter de Cuadricula de Juego.
 * @param _cuadricula
 */
void Juego::setCuadricula(Cuadricula* _cuadricula) {
    cuadricula = _cuadricula;
}

/**
 * Getter de aStarAlgorithm de Juego.
 * @return A*
 */
AStar* Juego::getAStarAlgorithm(){
    return aStarAlgorithm;
}

/**
 * Setter de aStarAlgorithm de Juego.
 * @param _aStarAlgorithm
 */
void Juego::setAStarAlgorithm(AStar* _aStarAlgorithm) {
    aStarAlgorithm = _aStarAlgorithm;
}

/**
 * Getter del backtrackingAlgorithm de Juego.
 * @return _backtrackingAlgorithm
 */
Backtracking* Juego::getBacktrackingAlgorithm() {
    return backtrackingAlgorithm;
}

/**
 * Setter del backtrackingAlgorithm de Juego.
 * @param _backtrackingAlgorithm
 */
void Juego::setBacktrackingAlgorithm(Backtracking* _backtrackingAlgorithm) {
    backtrackingAlgorithm = _backtrackingAlgorithm;
}


/**
 * Getter de poblacion1 de Juego.
 * @return poblacion1
 */
Poblacion* Juego::getPoblacion1() {
    return poblacion1;
}


List Juego::getMejoresP1()
{
    return MejoresP1;
}


void Juego::setMejoresP1(List mejores)
{
    MejoresP1 = mejores;
}

