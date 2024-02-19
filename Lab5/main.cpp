#include "Fraction.h"
#include <iostream>
//    using std::cout;
//    using std::endl;
int main(){

    //write testing
    Fraction f1 {3, 5};
    std::cout << "f1: ";
    f1.write();
    std::cout << std::endl;

    //add testing
    Fraction f2 = f1.add(2);
    std::cout << "f2: ";
    f2.write();
    std::cout << std::endl;

    //overloaded add operator (fraction plus int)
    Fraction f4 = f1 + 2;
    std::cout << "f4: ";
    f4.write();
    std::cout << std::endl;

    //overloaded add operator (fraction plus fraction)
    std::cout << "f1 + f2: ";
    Fraction f5 = f1 + f2;
    f5.write();
    std::cout << std::endl;
        
    std::cout << "f2 + f1: ";
    Fraction f6 = f2 + f1;
    f6.write();
    std::cout << std::endl;

    //associativity and cascading 
    Fraction f3 = f2 + f1;
    std::cout << "f1 + f2 + f3: ";
    Fraction f7 = f1 + f2 + f3;
    f7.write();
    std::cout << std::endl;

    // int plus fraction
    std::cout << " 1 + f1:      ";
    Fraction f8 = 1 + f1;
    f8.write();
    std::cout << std::endl;

    // stream insertion operator 
    std::cout << "f1: ";
    f1.write(std::cout);
    std::cout << std::endl;

    std::cout << "f1 (w/ <<):   " << f1 << std::endl;
}