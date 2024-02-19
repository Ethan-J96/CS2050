#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

class Fraction {
public:
    // constructors
    Fraction (int n, int d);

    // method operations
    Fraction add (int i) const;

    // output
    void write(std::ostream& strm=std::cout) const;

    // overload operators 
    Fraction operator+ (int i) const; // fraction + int 
    Fraction operator+ (const Fraction& op2) const; // fraction + fraction
    friend Fraction operator+ (int i, const Fraction& f); // int + fraction
    friend std::ostream& operator<< (std::ostream& outfile, const Fraction& f); // stream insertion
private:
    int numerator   = 0;
    int denominator = 1;
    void reduce();
};

#endif 