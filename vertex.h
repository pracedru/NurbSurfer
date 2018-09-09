#ifndef VECTOR_H
#define VECTOR_H

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

    std::string toString(){
        std::string value = "";
        value += "x: " + std::to_string(x);
        value += " y: " + std::to_string(y);
        value += " z: " + std::to_string(z);
        return value;
    }
};

#endif // VECTOR_H
