#include <iostream>
#include "Circle.h"
#include "Shape.h"
#include "Square.h"

using namespace std;

int main(){
    Circle c1{0, 0, 1};
    Square s1{1, 0.5, 2.3};
    cout << "c1: " << c1 << endl;
    cout << "s1: " << s1 << endl;
}