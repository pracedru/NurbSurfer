#include "nurbssurface.h"

NurbsSurface::NurbsSurface()
{

}

void NurbsSurface::set_controls(QList<Vertex> new_controls_1, QList<Vertex> new_controls_2)
{
    this->nurbs1.set_controls(new_controls_1);
    this->nurbs2.set_controls(new_controls_2);
}

//void NurbsSurface::addControls(QList<Vertex> newControls)
//{
//    if (this->controls.length() > 0){
//        if (newControls.length()!= this->controls[0].length())
//            return;
//    }
//    this->controls.append(newControls);
//    this->controlCount1 = this->controls.length();
//    this->controlCount2 = this->controls[0].length();
//    QList<Vertex> controls1;
//    for (int i = 0; i < this->controlCount1; i++){
//        controls1.append(this->controls[i][0]);
//    }
//    this->nurbs1.setControls(controls1);
//    this->nurbs2.setControls(this->controls[0]);
//}

double NurbsSurface::R(int i, int j, int n, double u, double v)
{
    if (true)
        return nurbs1.N(i, n, u) * nurbs2.N(j, n, v);
    else {
        double num = this->nurbs1.N(i, n, u) * this->nurbs2.N(j, n, v) * this->weights[i][j];
        double denom = 0.0;
        for (int p = 0; p < this->nurbs1.get_control_count(); p++)
            for(int q = 0; q < this->nurbs2.get_control_count(); q++)
                denom += this->nurbs1.N(p, n, u) * this->nurbs2.N(q, n, v) * this->weights[p][q];
        return num / denom;
    }
}

Vertex NurbsSurface::S(double u, double v)
{
    Vertex s;
    int n = this->degree;
    if (u == 1)
        u = 0.999999999;
    if (v == 1)
        v = 0.999999999;
    for (int i = 0; i < this->nurbs1.get_control_count(); i++){
        for (int j = 0; j < this->nurbs2.get_control_count(); j++){
            Vertex P = this->nurbs1.get_control(i) + this->nurbs2.get_control(j);
            s = s + P*this->R(i, j, n, u, v);
        }
    }
    return s;
}

QList<Vertex> NurbsSurface::range(int divisions1, int divisions2)
{
    QList<Vertex> surf;

    return surf;
}
