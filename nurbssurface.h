#ifndef NURBSSURFACE_H
#define NURBSSURFACE_H

#include "nurbs.h"

#include <QObject>

class NurbsSurface : public QObject
{
    Nurbs nurbs1;
    Nurbs nurbs2;        
    int degree = 2;
    double **weights;
    Q_OBJECT
    NurbsSurface(const NurbsSurface &);
public:
    NurbsSurface();
    void set_controls(QList<Vertex> new_controls_1, QList<Vertex> new_controls_2);
    double R(int i, int j, int n, double u, double v);
    Vertex S(double u, double v);
    QList<Vertex> range(int divisions1, int divisions2);
signals:

public slots:
};

#endif // NURBSSURFACE_H
