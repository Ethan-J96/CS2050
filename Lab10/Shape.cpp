#include "Shape.h"
#include <iostream>

Shape::Shape( double x, double y ) : ref_x{x}, ref_y{y} {
    cout << "DEBUG: Executing Shape constructor...\n";
}
void Shape::write(std::ostream& fout) const{
    fout << "Coordinates: (" << ref_x << "," << ref_y << ")" << std::endl;
}
std::ostream& operator<<(std::ostream& fout, const Shape& s){
    s.write(fout);
    return fout;
}