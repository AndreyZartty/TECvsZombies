#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include "poblacion.h"

namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    void setPoblacion(Poblacion *pob);
    Poblacion* getPobla();
    void setData();
    ~Stats();

private:
    Ui::Stats *ui;
    Poblacion *Pobla;
};

#endif // STATS_H
