//
// Created by kyoko on 02-04-18.
//

#include <type_traits>
#include <iostream>

#ifndef TAREA1_POINT_H
#define TAREA1_POINT_H

#endif //TAREA1_POINT_H

template <class T> class Point{

public:
    Point(T x, T y);
    Point(T x, T y, T z);
    Point(Point&);

    T getX();
    T getY();
    T getZ();


    Point operator+(Point point) const;
    Point operator-(Point point) const;
    bool operator==(Point point) const;

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Point<U>& point);


    template <class U>
    friend std::istream& operator>>(std::istream& in, const Point<U>& point);


private:
    T m_x;
    T m_y;
    T m_z;

};

template <class T>
Point<T>::Point(T x, T y){
    m_x = x;
    m_y = y;
    m_z = 0;
}

template <class T>
Point<T>::Point(T x, T y, T z){
    m_x = x;
    m_y = y;
    m_z = z;
}

template <class T>
Point<T>::Point(Point &point) {
    m_x = point.getX();
    m_y = point.getY();
    m_z = point.getZ();
}

template <class T>
Point<T> Point<T>::operator+(Point<T> point) const{
    return Point(point.m_x + m_x, point.m_y + m_y, point.m_z + m_z);
}

template <class T>
Point<T> Point<T>::operator-(Point<T> point) const{
    return Point(m_x - point.m_x, m_y - point.m_y, m_z - point.m_z);
}


template <class T>
T Point<T>::getX() {
    return this->m_x;
}

template <class T>
T Point<T>::getY() {
    return this->m_y;
}

template <class T>
T Point<T>::getZ() {
    return this->m_z;
}


template <class T>
bool Point<T>::operator==(Point<T> point) const{
    return point.m_x == m_x and point.m_y == m_y and point.m_z == m_z;
}

template <class T>
std::ostream& operator<<(std::ostream &out, const Point<T>& point) {
    out << "(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, const Point<T>& point) {
    std::cout << "Introducir valores para ( x, y, z) :";
    in >> point.m_x >> point.m_y >> point.m_z;
    in.ignore();
    return in;
}