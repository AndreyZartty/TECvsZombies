#include "modificarcurso1.h"
#include "ui_modificarcurso1.h"
#include <QDebug>

modificarCurso1::modificarCurso1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modificarCurso1)
{
    ui->setupUi(this);

    //SETEA LA IMAGEN
    QPixmap imagenFondo(":/tileversions.png");
    imagenFondo = imagenFondo.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, imagenFondo);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    this->saveGeometry();
}

modificarCurso1::~modificarCurso1()
{
    delete ui;
}

void modificarCurso1::on_upgrade_clicked()
{
    emit actualizarCurso();
}

void modificarCurso1::on_delete_2_clicked()
{
    emit eliminarCurso();
}
