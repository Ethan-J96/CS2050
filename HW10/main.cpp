#include "Circle.h"
#include "Shape.h"
#include "Square.h"
#include "ShapeList.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <fstream>
#include<iostream>

using namespace std;

int main() {
  Circle c1{0, 0, 1};
  Square s1{1, 0.5, 2.3};
  cout << "c1: " << c1 << endl;
  cout << "s1: " << s1 << endl;

  cout << "Press <enter> to continue...";
  cin.get( );  // waits on another <enter> key
  ShapeList shapes;
  shapes.add( new Circle{1, 2.3, 3} );
  shapes.add( new Square{5, 5, 10.2} );
  shapes.add( new Triangle{ 5, 3, 9.8, 8});
  cout << "List via stream insertion operator:\n";
  cout << shapes << endl;
  cout << "\nList via write method:\n";
  shapes.write( cout );
  cout << endl;

 // Overloaded Constructors
  cout << "Press <enter> to continue...";
  cin.get( );  // waits on another <enter> key

  ifstream fin( "oop09in.txt" );
  if ( !fin ) {
    cout << "Input file could not be opened!  Exiting!\n";
    exit( 1 );
  }

  ShapeList shapes2;
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

            // TODO: add a Polygon object to the list from the file
            int totalVertices = 0;
            Point2D* vertices = new Point2D[100];
            double x;
            double y;

            while (iss >> x)
            {
                iss >> y;
                vertices[totalVertices] = Point2D(x, y);
                totalVertices++;
            }

            Point2D* tempVertices = new Point2D[totalVertices];
            for (int i = 0; i < totalVertices; i++)
            {
                tempVertices[i] = vertices[i];
            }

            delete[] vertices;
            vertices = tempVertices;

            shapes.add(new Polygon(vertices, totalVertices));
        } 
        else if ( object_type != "" ) {
            cout << "Unexpected object type: " << object_type << endl;
            exit( 2 );
        }
    }
  cout << "Object locations:\n" << shapes2 << endl;
  cout << "testing distanceto function" << endl;
  Shape shape(3.0, 4.0); // Create a Shape object with a reference point (3, 4)

  double point_x = 6.0;
  double point_y = 8.0;

  double distance = shape.getDistanceTo(point_x, point_y);

  std::cout << "Distance from the point (" << point_x << ", " << point_y << ") to the shape is: " << distance << std::endl;
  
  shapes2.erase();
  return 0;
}
