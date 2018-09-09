#ifndef NURBSSURFACE_H
#define NURBSSURFACE_H

#include "nurbs.h"

#include <QObject>

class NurbsSurface : public QObject
{
    Nurbs nurbs1;
    Nurbs nurbs2;
    Q_OBJECT
public:
    explicit NurbsSurface(QObject *parent = nullptr);

signals:

public slots:
};

#endif // NURBSSURFACE_H
