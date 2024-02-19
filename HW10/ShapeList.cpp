#include "ShapeList.h"
#include "Shape.h"

void ShapeList::add(Shape* newShape) {
    push_back(newShape);
}

void ShapeList::write(ostream& strm_out) const {
    for (const Shape* shape : *this) {
        shape->write(strm_out);
        strm_out << std::endl;  // Add a newline to separate shapes in the output
    }
}

ostream& operator<<(ostream& strm_out, const ShapeList& shapes) {
    shapes.write(strm_out);
    return strm_out;
}

void ShapeList::erase() {
    for (auto shape : *this) {
        delete shape;
    }
    clear();
}

Shape* ShapeList::findClosestTo (double p_x, double p_y) const{
    if(empty()){
        return;
    }
    int currentMinDistance = 9999;
    Shape* closestshape = nullptr;
    for(Shape* shape : *this){
        double distance = shape->getDistanceto(p_x,p_y);
        if(distance < currentMinDistance){
            currentMinDistance = distance;
            closestShape = shape;
        }
    }
    return closestShape;
}

ShapeList::~ShapeList() {
  erase();
}
