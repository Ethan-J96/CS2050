#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "Polygon.h"
#include "Point2D.h"
#include <sstream>
#include<fstream>
#include "ShapeList.h"

#include <vector>

using namespace std;

int main() {
  ifstream fin("oop10in.txt");
  if (!fin) {
    cout << "Input file could not be opened!  Exiting!\n";
    exit(1);
  }

  ShapeList shapes;

    while ( !fin.eof() ) {
        string line;
        getline(fin, line, ';');
        istringstream iss(line);
        string object_type;
        iss >> object_type;
        if ( object_type == "Square" ) {

            // TODO: add a Square object to the list from the file
            shapes.add(new Square(iss));
        } 
        else if ( object_type == "Circle" ) {

            // TODO: add a Circle object to the list from the file
            shapes.add(new Circle(iss));
        } 
        else if ( object_type == "Polygon" ) {
            int totalCount = 0;
            Point2D* vertices = new Point2D[100];
            double x;
            double y;
            while (iss >> x){
                iss >> y;
                vertices[totalCount] = Point2D(x, y);
                totalCount++;
            }
            Point2D* tempVertices = new Point2D[totalCount];
            for (int i = 0; i < totalCount; i++){
                tempVertices[i] = vertices[i];
            }

            delete[] vertices;
            vertices = tempVertices;

            shapes.add(new Polygon(vertices, totalCount));
        } 
        else if ( object_type != "" ) {
            cout << "Unexpected object type: " << object_type << endl;
            exit( 2 );
        }
    }

  cout << "Object locations:\n" << shapes << endl;

  return 0;
}