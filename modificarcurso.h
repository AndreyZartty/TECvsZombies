#ifndef MODIFICARCURSO_H
#define MODIFICARCURSO_H
#include "iostream"
#include <iostream>
#include <QWidget>

namespace Ui {
class modificarCurso;
}

class modificarCurso : public QWidget
{
    Q_OBJECT

public:
    explicit modificarCurso(QWidget *parent = nullptr);
    ~modificarCurso();

private slots:

    void on_pushButton_clicked();

    void on_delete_2_clicked();

signals:
    void cursoActualizado();
    void cursoEliminado();

public:
    Ui::modificarCurso *interfazGrafica;
};

#endif // MODIFICARCURSO_H
