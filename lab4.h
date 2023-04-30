#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
using std::cout;
using std::endl;
class Line {
    double *a, *b, *c;

public:
    double getA() const;
    double getB() const;
    double getC() const;
    void setA(double par);
    void setB(double par);
    void setC(double par);
    void display();
    Line(double A, double B, double C){a = new double(); b = new double(); c = new double(); *a=A; *b=B; *c=C;}
    Line();
    ~Line(){
        delete a; delete b; delete c;
    }
    bool operator || ( Line& obj);
    Line operator++();
    Line& operator=(const Line& obj);
    Line(const Line& obj);
    void findCross();
};

double validateInput();
#ifndef LAB_4_LAB4_H
#define LAB_4_LAB4_H

#endif //LAB_4_LAB4_H
