#ifndef CREARCURSO_H
#define CREARCURSO_H

#include <QWidget>
#include <curso.h>

namespace Ui {
class crearCurso;
}

class crearCurso : public QWidget
{
    Q_OBJECT

public:
    explicit crearCurso(QWidget *parent = nullptr);
    curso *Curso;
    ~crearCurso();

private slots:
    void on_bttnArqueros_clicked();

    void on_bttnLanzaFuego_clicked();

    void on_bttnArtilleros_clicked();

    void on_bttnMagos_clicked();
signals:
    void cursoCreado();

private:
    Ui::crearCurso *ui;

};

#endif // CREARCURSO_H
