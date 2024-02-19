#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"
#include <iostream>
using namespace std;
class Rectangle : public Shape {
    public:
        Rectangle(double x, double y, double w, double h);
        void write(ostream& fout) const;
        Rectangle(istream& in);
        ~Rectangle();
    private:
        double width;
        double height;
};

#endif