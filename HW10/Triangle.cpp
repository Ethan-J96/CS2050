#include "Triangle.h"
#include "Shape.h"
#include<iostream>
using namespace std;
Triangle::Triangle(double x, double y, double b, double h) : Shape{x,y}, base{b}, height{h} {
    cout << "DEBUG: Executing Triangle constructor...\n" << endl;
}
void Triangle::write(ostream& fout) const{
    Shape::write(fout);
    fout << "Base: " << base << " Height: " << height << endl;
}
Triangle::Triangle(istream& in) : Shape( in ){
    in >> base;
    in >> height;
}
Triangle::~Triangle() {
  cout << "executing Triangle destructor" << endl;
}
