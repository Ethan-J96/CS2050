#include "Rectangle.h"
#include <iostream>
using namespace std;
Rectangle::Rectangle(double x, double y, double w, double h) : Shape{x,y}, width{w}, height{h} {
    cout << "DEBUG: Executing Triangle constructor...\n" << endl;
}
void Rectangle::write(ostream& fout) const{
    Shape::write(fout);
    cout << "Width: " << width << " Height: " << height << endl;
}
Rectangle::Rectangle(istream& in) : Shape(in){
    in >> width;
    in >> height;
}
Rectangle::~Rectangle(){
    cout << "executing Rectangle destructor" << endl;
}