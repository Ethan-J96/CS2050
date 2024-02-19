#include "ShapeList.h"
#include "Shape.h"

#include<iostream>

void ShapeList::add(Shape* newShape) {
    push_back(newShape);
}

void ShapeList::write(std::ostream& strm_out) const {
  for (const auto& item : *this) {
    item->write( strm_out );
    strm_out << '\n';
  }
}

std::ostream& operator<<(std::ostream& strm_out, const ShapeList& shapes) {
    shapes.write(strm_out);
    return strm_out;
}

void ShapeList::erase() {
    for (auto shape : *this) {
        delete shape;
    }
    clear();
}

ShapeList::~ShapeList() {
  erase();
}
