#ifndef MODIFICARCURSO1_H
#define MODIFICARCURSO1_H

#include <QWidget>

namespace Ui {
class modificarCurso1;
}

class modificarCurso1 : public QWidget
{
    Q_OBJECT

public:
    explicit modificarCurso1(QWidget *parent = nullptr);
    ~modificarCurso1();

private slots:
    void on_upgrade_clicked();

    void on_delete_2_clicked();

private:
    Ui::modificarCurso1 *ui;

signals:
    void eliminarCurso();
    void actualizarCurso();
};

#endif // MODIFICARCURSO1_H
