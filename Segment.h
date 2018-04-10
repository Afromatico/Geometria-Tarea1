//
// Created by kyoko on 04-04-18.
//

#include "Vector.h"
#include <iostream>


#ifndef TAREA1_VECTOR_H
#define TAREA1_VECTOR_H

#endif //TAREA1_VECTOR_H


template <class T> class Segment{

public:
    Segment(Point<T>, Point<T>);
    Segment(Segment&);

    Point<T> getPoint1();
    Point<T> getPoint2();
    T getLength();

    bool operator==(Segment segment);

    Vector<T> orient(Point<T>);

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Segment<U>& segment);


    template <class U>
    friend std::istream& operator>>(std::istream& in, const Segment<U>& segment);


private:
    Point<T> point1;
    Point<T> point2;
    T length;

};

template <class T>
Segment<T>::Segment(Point<T> p1, Point<T> p2)
:   point1(p1),
    point2(p2)
{
    length = Vector<T>(p2-p1).mod();
}

template <class T>
Segment<T>::Segment(Segment &segment)
: point1(segment.point1),
  point2(segment.point2)
{
    length = segment.length;
}

template <class T>
Point<T> Segment<T>::getPoint1() {
    return point1;
}

template <class T>
Point<T> Segment<T>::getPoint2() {
    return point2;
}

template <class T>
T Segment<T>::getLength(){
    return length;
}


template <class T>
bool Segment<T>::operator==(Segment<T> segment){
    return segment.point1 == point1 and segment.point2 == point2;
}

template <class T>
Vector<T> Segment<T>::orient(Point<T> point) {
    return Vector<T>(point2-point1)*Vector<T>(point-point2);
}

template <class T>
std::ostream& operator<<(std::ostream &out, const Segment<T>& segment) {
    out << segment.point1 << segment.point2;
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, const Segment<T>& segment) {
    in >> segment.point1 >> segment.point2;
    return in;
}