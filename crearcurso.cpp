#include "crearcurso.h"
#include "ui_crearcurso.h"
#include <QDebug>

crearCurso::crearCurso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crearCurso)
{
    ui->setupUi(this);
}

crearCurso::~crearCurso()
{
    delete ui;
}

void crearCurso::on_bttnArqueros_clicked()
{
    Curso= new curso();
    Curso->imagen = QPixmap(":/torre1");
    Curso->alcance=1;
    emit cursoCreado();
}

void crearCurso::on_bttnLanzaFuego_clicked()
{

    Curso= new curso();
    Curso->imagen = QPixmap(":/torre2");
    Curso->alcance=2;
    emit cursoCreado();
}

void crearCurso::on_bttnArtilleros_clicked()
{

    Curso= new curso();
    Curso->imagen = QPixmap(":/torre3");
    Curso->alcance=3;
    emit cursoCreado();
}

void crearCurso::on_bttnMagos_clicked()
{

    Curso= new curso();
    Curso->imagen = QPixmap(":/torre4");
    Curso->alcance=1;
    emit cursoCreado();
}
