#include<iostream>
#include "Circle.h"
#include "Shape.h"
#include "Square.h"
#include "ShapeList.h"
#include <fstream>

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
  while ( fin.good( ) ) {
    string object_type;
    fin >> object_type;
    if ( object_type == "Square" ) {
        Square* sq = new Square{ fin };
        shapes2.add( sq );
    } else if ( object_type == "Circle" ) {
        Circle* circ = new Circle{ fin };
        shapes2.add( circ );
    } else {
        cout << "Unexpected object type: " << object_type << endl;
        exit( 2 );
    }
 }

  cout << "Object locations:\n" << shapes2 << endl;

  shapes2.erase();

  return 0;
}
