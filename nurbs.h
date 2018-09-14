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
    bool hasWeights = false;
    void free_mem();
    Nurbs(const Nurbs &);
public:
    explicit Nurbs();
    ~Nurbs();
    void set_controls(QList<Vertex> controls);
    QList<Vertex> get_controls();
    int get_control_count() { return this->controlCount; }
    Vertex get_control(int index);
    double g(int i, int n, double u);
    double f(int i, int n, double u);
    double N(int i, int n, double u);
    double R(int i, int n, double u);
    Vertex C(double u);
    QList<Vertex> range(int divisions);    
    QList<double> get_knots();
    void set_knots(QList<double> newKnots);
    void set_degree(int degree);

};

#endif // NURBS_H
