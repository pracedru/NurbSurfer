#include "nurbs.h"


Nurbs::Nurbs()
{
}

Nurbs::~Nurbs()
{
    this->free_mem();
}

void Nurbs::free_mem(){
    if (this->controlCount>0){
        delete [] this->controls;
        delete [] this->knots;
        delete [] this->weights;
    }
}

void Nurbs::set_controls(QList<Vertex> controls)
{
    int newControlCount = controls.length();
    this->free_mem();
    if (newControlCount > 0){
        this->controls = new Vertex[newControlCount];
        this->weights = new double[newControlCount];
        this->knots = new double[newControlCount + this->degree + 1];
        for (int i = 0; i < newControlCount; i++){
            this->controls[i] = controls[i];
            this->weights[i] = 1.0;
        }
        for (int i = 0; i < this->degree; i++)
            this->knots[i] = 0.0;

        for (int i = 0; i < newControlCount - this->degree + 1; i++){
            double k = (double)i / ((double)newControlCount-(double)this->degree);
            this->knots[i+this->degree] = k;
        }

        for (int i = 0; i < this->degree; i++)
            this->knots[newControlCount + 1 + i] = 1.0;
    }
    this->controlCount = newControlCount;
}

QList<Vertex> Nurbs::get_controls()
{
    QList<Vertex> controls;
    for (int i = 0; i < controlCount; i++)
        controls.append(this->controls[i]);
    return controls;
}

Vertex Nurbs::get_control(int index)
{
    if (index < controlCount && index >= 0){
        return this->controls[index];
    }
    return Vertex();
}

double Nurbs::g(int i, int n, double u)
{
    double num = this->knots[i + n] - u;
    double denom = this->knots[i + n] - this->knots[i];
    if (denom == 0.0)
        denom = 1.0e-30;
    return num / denom;
}

double Nurbs::f(int i, int n, double u)
{
    double num = u - this->knots[i];
    double denom = this->knots[i + n] - this->knots[i];
    if (denom == 0.0)
        denom = 1.0e-30;
    return num / denom;
}

double Nurbs::N(int i, int n, double u)
{
    if (n == 0){
        if (this->knots[i] <= u && u < this->knots[i + 1])
            return 1.0;
        else if ((u == this->knots[i + 1]) && (i + 2 == this->controlCount+3))
            return 1.0;
        return 0.0;
    }
    double retval = this->f(i, n, u) * this->N(i, n - 1, u) + this->g(i + 1, n, u) * this->N(i + 1, n - 1, u);
    return retval;
}

double Nurbs::R(int i, int n, double u)
{
    if (true)
        return this->N(i, n, u);
    else {
        double num = this->N(i, n, u) * this->weights[i];
        double denom = 0.0;
        for (int j = 0; j < this->controlCount; j++)
            denom += this->N(j, n, u) * this->weights[j];
        if (denom == 0)
            denom = 1e-99;
        return num / denom;
    }
}

Vertex Nurbs::C(double u)
{
    Vertex c;
    if (u>=1)
        u = 0.9999999999999;
    int n = this->degree;
    for (int i = 0; i < this->controlCount; i++){
        Vertex P = this->controls[i];
        c = c + P * this->R(i, n, u);
    }
    return c;
}

QList<Vertex> Nurbs::range(int divisions)
{
    QList<Vertex> verts;
    double divs = (double)divisions;
    double numerator = divs-1;
    for (double i = 0; i < divs; i++){
        double c = i/numerator;
        verts.append(this->C(c));
    }
    return verts;
}

QList<double> Nurbs::get_knots()
{
    QList<double> knots;
    for (int i = 0; i < this->controlCount+this->degree+1; i++)
        knots.append(this->knots[i]);
    return knots;
}

void Nurbs::set_knots(QList<double> newKnots)
{
    if (newKnots.length() == this->controlCount+this->degree + 1)
        for (int i = 0; i < newKnots.length(); i++)
            this->knots[i] = newKnots[i];
}

void Nurbs::set_degree(int degree)
{
    this->degree = degree;
}

