#include "modificarcurso1.h"
#include "ui_modificarcurso1.h"
#include <QDebug>

modificarCurso1::modificarCurso1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modificarCurso1)
{
    ui->setupUi(this);
}

modificarCurso1::~modificarCurso1()
{
    delete ui;
}

void modificarCurso1::on_upgrade_clicked()
{
    qDebug()<<"upgrade";
    emit actualizarCurso();
}

void modificarCurso1::on_delete_2_clicked()
{
    qDebug()<<"delete";
    emit eliminarCurso();
}
