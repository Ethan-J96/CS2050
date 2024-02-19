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

    // Overloaded add operator (fraction plus int)

    Fraction f3(3, 4);

    std::cout << "f3: " << f3 << std::endl;

    std::cout << "f3 + 2: ";
    Fraction f4 = f3 + 2;
    std::cout << f4 << std::endl;

    std::cout << "2 + f3: ";
    Fraction f5 = 2 + f3;
    std::cout << f5 << std::endl;

    // Overloaded add operator (fraction plus fraction)
    Fraction f6(1, 2);

    std::cout << "f3 + f6: ";
    Fraction f7 = f3 + f6;
    std::cout << f7 << std::endl;

    std::cout << "f6 + f3: ";
    Fraction f8 = f6 + f3;
    std::cout << f8 << std::endl;

    // Associativity and cascading
    std::cout << "f3 + f6 + f7: ";
    Fraction f9 = f3 + f6 + f7;
    std::cout << f9 << std::endl;

    // Overloaded subtraction operator (fraction minus int)
    std::cout << "f3 - 2: ";
    Fraction f10 = f3 - 2;
    std::cout << f10 << std::endl;

    std::cout << "2 - f3: ";
    Fraction f11 = 2 - f3;
    std::cout << f11 << std::endl;

    // Overloaded subtraction operator (fraction minus fraction)
    std::cout << "f3 - f6: ";
    Fraction f12 = f3 - f6;
    std::cout << f12 << std::endl;

    std::cout << "f6 - f3: ";
    Fraction f13 = f6 - f3;
    std::cout << f13 << std::endl;

    // Overloaded multiplication operator (fraction times int)
    std::cout << "f3 * 2: ";
    Fraction f14 = f3 * 2;
    std::cout << f14 << std::endl;

    std::cout << "2 * f3: ";
    Fraction f15 = 2 * f3;
    std::cout << f15 << std::endl;

    // Overloaded multiplication operator (fraction times fraction)
    std::cout << "f3 * f6: ";
    Fraction f16 = f3 * f6;
    std::cout << f16 << std::endl;

    std::cout << "f6 * f3: ";
    Fraction f17 = f6 * f3;
    std::cout << f17 << std::endl;

    // Overloaded division operator (fraction divided by int)
    std::cout << "f3 / 2: ";
    Fraction f18 = f3 / 2;
    std::cout << f18 << std::endl;

    std::cout << "2 / f3: ";
    Fraction f19 = 2 / f3;
    std::cout << f19 << std::endl;

    // Overloaded division operator (fraction divided by fraction)
    std::cout << "f3 / f6: ";
    Fraction f20 = f3 / f6;
    std::cout << f20 << std::endl;

    std::cout << "f6 / f3: ";
    Fraction f21 = f6 / f3;
    std::cout << f21 << std::endl;

    // Comparison operators
    std::cout << "f3 < f6: " << (f3 < f6) << std::endl;
    std::cout << "f3 > f6: " << (f3 > f6) << std::endl;
    std::cout << "f3 <= f6: " << (f3 <= f6) << std::endl;
    std::cout << "f3 >= f6: " << (f3 >= f6) << std::endl;
    std::cout << "f3 == f6: " << (f3 == f6) << std::endl;
    std::cout << "f3 != f6: " << (f3 != f6) << std::endl;
    int i = 2;
    // Comparison with an integer on the right
    std::cout << "f1 < i: " << (f1 < i) << std::endl;
    std::cout << "f1 > i: " << (f1 > i) << std::endl;
    std::cout << "f1 <= i: " << (f1 <= i) << std::endl;
    std::cout << "f1 >= i: " << (f1 >= i) << std::endl;
    std::cout << "f1 == i: " << (f1 == i) << std::endl;
    std::cout << "f1 != i: " << (f1 != i) << std::endl;

    // Comparison with an integer on the left
    std::cout << "i < f1: " << (i < f1) << std::endl;
    std::cout << "i > f1: " << (i > f1) << std::endl;
    std::cout << "i <= f1: " << (i <= f1) << std::endl;
    std::cout << "i >= f1: " << (i >= f1) << std::endl;
    std::cout << "i == f1: " << (i == f1) << std::endl;
    std::cout << "i != f1: " << (i != f1) << std::endl;

    // Testing stream insertion
    std::cout << "f1 (w/ <<):   " << f1 << std::endl;

    Fraction f(0,1);
    // Test input with an integer
    std::cout << "Enter a fraction (e.g., 3/5): ";
    std::cin >> f;
    std::cout << "You entered: " << f << std::endl;

    // Test input with a fraction
    std::cout << "Enter another fraction (e.g., 1/4): ";
    std::cin >> f;
    std::cout << "You entered: " << f << std::endl;
}