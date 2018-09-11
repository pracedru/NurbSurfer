#ifndef NURBS_H
#define NURBS_H

#include "nurbs_global.h"
#include <vertex.h>
#include <QList>
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
    Nurbs(const Nurbs &);
public:
    explicit Nurbs();
    ~Nurbs();
    void setControls(QList<Vertex> controls);
    double g(int i, int n, double u);
    double f(int i, int n, double u);
    double N(int i, int n, double u);
    double R(int i, int n, double u);
    Vertex C(double u);
    QList<Vertex> range(int divisions);    
    QList<double> getKonts();
    void setKnots(QList<double> newKnots);

};

#endif // NURBS_H
