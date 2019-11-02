QT       += core gui multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TEMPLATE = app
TARGET = TECvsZombies

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astar.cpp \
    backtracking.cpp \
    cuadricula.cpp \
    estudiante.cpp \
    juego.cpp \
    list.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    nodeg.cpp \
    poblacion.cpp \
    crearcurso.cpp \
    curso.cpp \
    modificarcurso1.cpp \
    nodo.cpp \
    stats.cpp \
    tablero.cpp \
    torre.cpp
    evaluacion.cpp \
    workerrevisar.cpp

HEADERS += \
    evaluacion.h \
    workerrevisar.h
    astar.h \
    backtracking.h \
    cuadricula.h \
    estudiante.h \
    juego.h \
    list.h \
    mainwindow.h \
    node.h \
    nodeg.h \
    poblacion.h \
    crearcurso.h \
    curso.h \
    modificarcurso1.h \
    nodo.h \
    stats.h \
    tablero.h \
    torre.h

FORMS += \
    crearcurso.ui \
    modificarcurso1.ui \
    stats.ui \
    tablero.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    yellow.png

RESOURCES += \
    recursos.qrc
