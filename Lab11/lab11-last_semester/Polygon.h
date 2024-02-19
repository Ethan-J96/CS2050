#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include "Point2D.h"

#include<iostream>

class Polygon : public Shape {
public:
    Polygon(const Point2D* vertices, int vertex_count);
    ~Polygon();
    void write(std::ostream& strm_out) const;

    // disallow copies by ctor and by assignment
    Polygon(const Polygon&) = delete;
    Polygon& operator=(const Polygon&) = delete;

private:
    Point2D* vertices = nullptr;
    int vertex_count = 0;
};

std::ostream& operator<<(std::ostream& strm_out, const Polygon& p);

#endif
