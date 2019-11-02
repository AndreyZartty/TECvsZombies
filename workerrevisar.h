#ifndef WORKERREVISAR_H
#define WORKERREVISAR_H

#include <QThread>
#include <QObject>

class workerRevisar : public QThread
{
    Q_OBJECT

public:
    explicit workerRevisar(QObject *parent=0);
    bool terminado;
signals:
    void progreso();
protected:
    void run() override;
};

#endif // WORKERREVISAR_H
