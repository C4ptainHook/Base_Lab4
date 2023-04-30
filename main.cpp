#include "lab4.h"

int main() {
    double firstarg =  validateInput();
    cout<<"A - coefficient ="<<firstarg<<'\n';
    double secarg =  validateInput();
    cout<<"B - coefficient ="<<secarg<<'\n';
    double thirdarg =  validateInput();
    cout<<"C - coefficient ="<<thirdarg<<'\n';
    Line firstline(firstarg,secarg,thirdarg);
    firstline.display();
    Line secondline = firstline;
    secondline.display();
    Line thirdline;
    thirdline.display();
    firstline||secondline;
    ++thirdline;
    thirdline.display();
    thirdline.findCross();
}
