#ifndef EVALUACION_H
#define EVALUACION_H
#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
#include <QDebug>

class Evaluacion : public QWidget
{
    Q_OBJECT

public:
    Evaluacion();
    void setOrigen1(int x, int y);
    void evaluar1(int xfinal, int yfinal);
    int corx1;
    int cory1;
    void setParent1();

    QLabel *imagen1;
public slots:
    void llegaEvaluacion1();
signals:
    void termino1();
private:
    QPropertyAnimation *animation;
};

#endif // EVALUACION_H
