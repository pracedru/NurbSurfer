#ifndef NURBSSURFACE_H
#define NURBSSURFACE_H

#include "nurbs.h"

#include <QObject>

class NurbsSurface : public QObject
{
    Nurbs nurbs1;
    Nurbs nurbs2;
    QList<QList<Vertex>> controls;
    int controlCount1 = 0;
    int controlCount2 = 0;
    int degree = 2;
    double **weights;
    Q_OBJECT
    NurbsSurface(const NurbsSurface &);
public:
    NurbsSurface();
    void setControls(QList<QList<Vertex>> newControls);
    void addControls(QList<Vertex> newControls);
    double R(int i, int j, int n, double u, double v);
    Vertex S(double u, double v);
    QList<Vertex> range(int divisions1, int divisions2, bool with_normals=false);
signals:

public slots:
};

#endif // NURBSSURFACE_H
