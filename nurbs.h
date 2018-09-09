#ifndef NURBS_H
#define NURBS_H

#include "nurbs_global.h"
#include <vertex.h>
#include <QVector>
#include <QObject>

class NURBSSHARED_EXPORT Nurbs : QObject
{
    Q_OBJECT
    double *knots;
    double *weights;
    Vertex *controls;
    int degree = 2;
    int controlCount = 0;

    void free_mem();
public:
    explicit Nurbs(QObject *parent = nullptr);
    ~Nurbs();
    void setControls(QVector<Vertex> controls);
    double g(int i, int n, double u);
    double f(int i, int n, double u);
    double N(int i, int n, double u);
    double R(int i, int n, double u);
    Vertex C(double u);
    QVector<Vertex> range(int divisions);

};

#endif // NURBS_H
