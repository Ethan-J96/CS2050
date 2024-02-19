#include "Shape.h"
#include "Point2D.h"
#include "Polygon.h"
#include <iostream>

using namespace std;

Polygon::Polygon(const Point2D* vertices, int vertex_count) : Shape(vertices[0].x, vertices[0].y), vertices(new Point2D[vertex_count]), vertex_count(vertex_count) {
  this->vertices = new Point2D[vertex_count];
  for (int i = 0; i < vertex_count; i++) {
    this->vertices[i] = vertices[i];
  }
  this->vertex_count = vertex_count;
}

Polygon::~Polygon() {
  delete[] vertices;
}

void Polygon::write(ostream& strm_out) const {
        strm_out << "Polygon: ";
        for (int i = 0; i < vertex_count; i++) {
            strm_out << vertices[i] << " ";
        }
    }

std::ostream& operator<<(std::ostream& strm_out, const Polygon& p) {
    p.write(strm_out);
    return strm_out;
}
