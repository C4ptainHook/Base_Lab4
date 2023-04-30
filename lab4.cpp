#include "lab4.h"
void Line::setC(double par){ *c=par;}

void Line::setB(double par){ *b=par;}

void Line::setA(double par){ *a=par;}

double Line::getC() const{ return *c;}

double Line::getB() const{ return *b;}

double Line::getA() const{ return *a;}

void Line::display(){cout<<std::setprecision(1)<<std::fixed<<"["<<*this->a<<"*X+("<<*this->b<<")*Y+("<<*this->c<<")=0]"<<endl;}

bool Line::operator || ( Line& obj) {
    if(*this->a/obj.getA()==*this->b/obj.getB()&&*this->b/obj.getB()==*this->c/obj.getC())
    {
        cout<<"Line are parallel"<<endl;
        return true;
    }
    else{
        cout<<"Line are NOT parallel"<<endl;
        return false;}
}
Line Line::operator++() {
    double angle = atan2(-*this->a, *this->b);  // Calculate the angle between the line and the x-axis
    angle += M_PI / 180.0;  // Rotate the angle one degree clockwise
    double r = hypot(*this->a, *this->b);  // Calculate the length of the line segment
    *this->a = (-r * sin(angle));  // Calculate the new coefficients of the line
    *this->b = (r * cos(angle));
    return *this;
}
Line& Line::operator=(const Line& obj){
    if(this != &obj){
        delete this->a; delete this->b; delete this->c;
        this->a = new double();
        this->b = new double();
        this->c = new double();
        *this->a = obj.getA();
        *this->b = obj.getB();
        *this->c = obj.getC();
    }
    return *this;
}
Line::Line(){
    this->a = new double(); this->b = new double(); this->c = new double();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution <double> dist(-100, 100);
    *this->a=dist(gen);
    *this->b=dist(gen);
    *this->c=dist(gen);
}
Line::Line(const Line& obj){
    this->a = new double(); this->b = new double(); this->c = new double();
    *this->a=obj.getA();
    *this->b=obj.getB();
    *this->c=obj.getC();
}
void Line::findCross() {
    cout<<std::setprecision(2)<<std::fixed<<"Line cross X-axis in ("<<-*this->c/(*this->a)<<",0)"<<endl;
    cout<<std::setprecision(2)<<std::fixed<<"Line cross Y-axis in (0,"<<-*this->c/(*this->b)<<")"<<endl;
}

double validateInput() {
    static short count=0;
    switch(count){
        case 0: {cout<<"Enter A coefficient:"; break;}
        case 1: {cout<<"Enter B coefficient:"; break;}
        case 2: {cout<<"Enter C coefficient:"; break;}
    }
    std::string number;
    double value;
    bool valid = false;
    do {
        try {
            std::getline(std::cin, number);
            size_t pos;
            value = std::stod(number, &pos);
            if (pos < number.size()) {
                throw std::invalid_argument("Symbols after the value");
            }
            valid = true;
        } catch (std::exception& exp) {
            std::cerr << "Error: " << exp.what() << ". Invalid input. Try again!" << std::endl;
        }
    } while (!valid);
    count++;
    return value;
}