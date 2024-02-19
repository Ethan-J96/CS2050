#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Shape.h"
using namespace std;
class Triangle : public Shape{
    public:
        Triangle(double x, double y, double b, double h);
        void write(ostream& fout) const;
        Triangle(istream& in);
        ~Triangle();
    private:
        double base;
        double height;
};

#endif