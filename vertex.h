#ifndef VECTOR_H
#define VECTOR_H

#include <QList>
#include <iostream>

struct Vertex{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    Vertex(){}

    Vertex(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    inline Vertex operator*(double rhs) {
        return Vertex(x*rhs, y*rhs, z*rhs);
    }
    inline Vertex operator+(Vertex rhs) {
        return Vertex(x+rhs.x, y+rhs.y, z+rhs.z);
    }

    QString to_string(){
        QString value = "";
        value += "x: " + QString::number(x);
        value += " y: " + QString::number(y);
        value += " z: " + QString::number(z);
        return value;
    }
    QList<double> get_xyz(){
        QList<double> retVal;
        retVal.append(x);
        retVal.append(y);
        retVal.append(z);
        return retVal;
    }
};

#endif // VECTOR_H
