//
// Created by kyoko on 04-04-18.
//

#include "Segment.h"
#include <iostream>
#include <vector>


#ifndef TAREA1_VECTOR_H
#define TAREA1_VECTOR_H

#endif //TAREA1_VECTOR_H


template <class T> class Polygon{

public:
    Polygon(std::vector<Point<T>> pointsList, std::vector<Segment<T>> segmentsList);
    Polygon(Polygon&);

    Point<T> getPoint(int i);
    Point<T> getSegment(int i);
    T getLength();

    bool operator==(Polygon polygon);

    template <class U>
    friend std::ostream& operator<<(std::ostream& out, const Polygon<U>& polygon);


    template <class U>
    friend std::istream& operator>>(std::istream& in, const Polygon<U>& polygon);


private:
    std::vector<Point<T>> pointsList;
    std::vector<Segment<T>> segmentsList;
    T length;

};

template <class T>
Polygon<T>::Polygon(std::vector<Point<T>> psL, std::vector<Segment<T>> ssL)
:   pointsList(psL),
    segmentsList(ssL)
{
    T len = 0;
    for(Segment<T> seg : ssL){
        len += seg.getLength();
    }
    length = len;
}

template <class T>
Polygon<T>::Polygon(Polygon &polygon)
: pointsList(polygon.pointsList),
  segmentsList(polygon.segmentsList)
{
    length = polygon.length;
}

template <class T>
Point<T> Polygon<T>::getPoint(int i) {
    return pointsList.at(i);
}

template <class T>
Point<T> Polygon<T>::getSegment(int i) {
    return segmentsList.at(i);
}

template <class T>
T Polygon<T>::getLength(){
    return length;
}


template <class T>
bool Polygon<T>::operator==(Polygon<T> polygon){
    if(pointsList.size() != polygon.pointsList.size() or segmentsList.size() != polygon.segmentsList.size()){
        return false;
    }
    for(int i = 0; i < polygon.pointsList.size(); i++){
        if(polygon.pointsList.at(i) != pointsList.at(i)){
            return false;
        }
    }
    for(int i = 0; i < polygon.segmentsList.size(); i++){
        if(polygon.segmentsList.at(i) != segmentsList.at(i)){
            return false;
        }
    }
    return true;
}


template <class T>
std::ostream& operator<<(std::ostream &out, const Polygon<T>& polygon) {
    out << polygon.point1 << polygon.point2;
    return out;
}

template <class T>
std::istream& operator>>(std::istream &in, const Polygon<T>& polygon) {
    in >> polygon.point1 >> polygon.point2;
    return in;
}