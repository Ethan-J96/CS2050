#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle : public Shape {
  public:
    Circle( double x, double y, double r );
    void write(ostream &fout) const;
  private:
    double radius;
};
std::ostream& operator<<(std::ostream& os, const Circle& );
#endif