#include "modificarcurso.h"
#include "ui_modificarcurso.h"
#include <QPalette>
#include <QPushButton>
#include <QStyleFactory>
#include <iostream>
#include <QDebug>

using namespace std;

modificarCurso::modificarCurso(QWidget *parent) :
    QWidget(parent),
    interfazGrafica(new Ui::modificarCurso)
{
    interfazGrafica->setupUi(this);
    this->setGeometry(20,20,400,500);
    QPixmap imagenFondo(":/tileversions.png");
        imagenFondo = imagenFondo.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, imagenFondo);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    this->saveGeometry();

}

modificarCurso::~modificarCurso()
{
    delete interfazGrafica;
}


void modificarCurso::on_pushButton_clicked()
{
    qDebug()<<"ll";
}

void modificarCurso::on_delete_2_clicked()
{

}
