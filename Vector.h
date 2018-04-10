//
// Created by kyoko on 04-04-18.
//

#include "Point.h"
#include <iostream>
#include <cmath>


#ifndef TAREA1_VECTOR_H
#define TAREA1_VECTOR_H

#endif //TAREA1_VECTOR_H


template <class T> class Vector{

public:
    Vector(T x, T y);
    Vector(T x, T y, T z);
    Vector(Point<T>);
    Vector(Vector&);

    Point<T> getPoint();

    Vector operator+(Vector vector) const;
    Vector<T> operator*(Vector vector);
    T operator%(Vector vector);
    Vector operator-(Vector vector) const;
    bool operator==(Vector vector);
    T mod();

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Vector<U>& vector);


    template <class U>
    friend std::istream& operator>>(std::istream& in, const Vector<U>& vector);


private:
    Point<T> point;
};

template <class T>
Vector<T>::Vector(T x, T y)
        : point(Point<T>(x, y))
{}

template <class T>
Vector<T>::Vector(T x, T y, T z)
        : point(Point<T>(x, y, z))
{}

template <class T>
Vector<T>::Vector(Point<T> p)
: point(p)
{}

template <class T>
Vector<T>::Vector(Vector &vec)
: point(vec.point)
{}

template <class T>
Vector<T> Vector<T>::operator+(Vector<T> vec) const{
    return Vector<T>(point + vec.point);
}

template <class T>
Vector<T> Vector<T>::operator-(Vector<T> vec) const{
    return Vector<T>(point - vec.point);
}

template <class T>
Vector<T> Vector<T>::operator*(Vector<T> vector){
    T ux = point.getX(); T uy = point.getY(); T uz = point.getZ();
    T vx = vector.point.getX(); T vy = vector.point.getY(); T vz = vector.point.getZ();
    return Vector<T>(uy*vz-uz*vy,uz*vx-ux*vz,ux*vy-uy*vx);
}

template <class T>
T Vector<T>::operator%(Vector<T> vector){
    return point.getX()*vector.point.getX() +
           point.getY()*vector.point.getY() +
           point.getZ()*vector.point.getZ();
}



template <class T>
Point<T> Vector<T>::getPoint() {
    return point;
}


template <class T>
bool Vector<T>::operator==(Vector<T> vec){
    return vec.point == point;
}

template <class T>
std::ostream& operator<<(std::ostream &out, const Vector<T>& vec) {
    out << vec.point;
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, const Vector<T>& vec) {
    in >> vec.point;
    return in;
}

template <class T>
T Vector<T>::mod() {

    return std::sqrt((double)point.getX()*point.getX()+
                     (double)point.getY()*point.getY()+
                     (double)point.getZ()*point.getZ());
}
