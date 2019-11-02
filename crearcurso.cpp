#include "crearcurso.h"
#include "ui_crearcurso.h"
#include <QDebug>

crearCurso::crearCurso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::crearCurso)
{
    ui->setupUi(this);
    QPixmap imagenFondo(":/tileversions.png");
        imagenFondo = imagenFondo.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, imagenFondo);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    this->saveGeometry();

}

crearCurso::~crearCurso()
{
    delete ui;
}

void crearCurso::on_bttnArqueros_clicked()
{
    Curso= new curso(1);
    Curso->imagen = QPixmap(":/torre1");
    //Curso->alcance=1;
    emit cursoCreado();
}

void crearCurso::on_bttnLanzaFuego_clicked()
{

    Curso= new curso(4);
    Curso->imagen = QPixmap(":/torre2");
    //Curso->alcance=2;
    emit cursoCreado();
}

void crearCurso::on_bttnArtilleros_clicked()
{

    Curso= new curso(3);
    Curso->imagen = QPixmap(":/torre3");
    //Curso->alcance=3;
    emit cursoCreado();
}

void crearCurso::on_bttnMagos_clicked()
{

    Curso= new curso(2);
    Curso->imagen = QPixmap(":/torre4");
    //Curso->alcance=1;
    emit cursoCreado();
}
