#include <iostream>
#include <cassert>
#include "Polygon.h"

int main() {


    std::cout << "Inician los test" << std::endl;

    Point<double> p1(5.0, -3.0);
    Point<double> p2(2.0, 5.0);
    Point<int> p3(5, -3);
    Point<int> p4(-5, -3);

    Point<double> p5 = p1 + p2;

    std::cout << p1 << p2 << p3 << p4 << p5 << std::endl;


    std::cout << "Se crearon los puntos" << std::endl;

    assert(p1 == Point<double>(5.0, -3.0));

    assert(p3 == Point<int>(5, -3));

    std::cout << "Suma entre dos puntos definidos como flotantes" << std::endl;

    assert(p3 + p4 == Point<int>(0, -6));

    std::cout << "Suma entre dos puntos Integer" << std::endl;

    assert(p1 - p2 == Point<double>(3.0, -8.0));

    std::cout << "Resta entre dos puntos definidos como flotantes" << std::endl;

    assert(p3 - p4 == Point<int>(10, 0));

    std::cout << "Suma entre dos puntos Integer" << std::endl;

    Vector<double> v1(p1);
    Vector<double> v2(2.0, 5.0);
    Vector<int> v3(p3);
    Vector<int> v4(-5, -3);
    Vector<double> v5 = v1 + v2;

    std::cout << v1 << v2 << v3 << v4 << v5 << std::endl;

    assert(v1 == Vector<double>(5.0, -3.0));

    assert(v3 == Vector<int>(5, -3));

    assert(v3 + v4 == Vector<int>(0, -6));

    assert(v1 - v2 == Vector<double>(3.0, -8.0));

    assert(v3 - v4 == Vector<int>(10, 0));

    assert(v1 % v2 == -5.0);

    assert(v1 * v2 == Vector<double>(0.0, 0.0, 31.0));

    Segment<double> s1(Point<double>(0.0, 5.0), Point<double>(5.0,10.0));

    std::cout << s1 <<s1.orient(Point<double>(5.0,5.0)) << std::endl;

    Point<double> p11(-3.0,-1.0);
    Point<double> p12(6.0,-1.0);
    Point<double> p13(7.0,3.0);
    Point<double> p14(2.0,5.0);
    Point<double> p15(-8.0,3.0);
    Point<double> p16(-8.0,0.0);

    Segment<double> s2(p11,p12);
    Segment<double> s3(p12,p13);
    Segment<double> s4(p13,p14);
    Segment<double> s5(p14,p15);
    Segment<double> s6(p15,p16);
    Segment<double> s7(p16,p11);

    std::vector<Point<double> > vP;
    std::vector<Segment<double> > vS;

    vP.push_back(p1);
/*    vP.push_back(p12);
    vP.push_back(p13);
    vP.push_back(p14);
    vP.push_back(p15);
    vP.push_back(p16);

    vS.push_back(s2);
    vS.push_back(s3);
    vS.push_back(s4);
    vS.push_back(s5);
    vS.push_back(s6);
    vS.push_back(s7);






    Polygon<double> poly(vP,vS);

    std::cout << "Finalizo el programa" << std::endl;*/
    return 0;
}