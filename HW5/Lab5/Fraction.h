#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

class Fraction {
public:
    // constructors
    Fraction (int n, int d);

    // accessors
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    
    // method operations
    Fraction add (int i) const;

    // i/o methods
    void write(std::ostream& strm=std::cout) const;

    // overload operators 
    //addition
    Fraction operator+ (int i); // fraction + int 
    Fraction operator+ (Fraction& op2); // fraction + fraction
    
    //subtraction 
    Fraction operator- (int i); // fraction - int
    Fraction operator- (Fraction& op2); // fraction - fraction 
    
    //multiplication
    Fraction operator* (int i); // fraction * int
    Fraction operator* (Fraction& op2); // fraction * fraction
    
    //division 
    Fraction operator/ (int i); // fraction / int
    Fraction operator/ (Fraction& op2); // fraction / fraction

    //comparison operators
    //less than
    bool operator< (int i); // fraction < int
    bool operator< (Fraction& op2); // fraction < fraction

    //greater than
    bool operator> (int i); // fraction > int
    bool operator> (Fraction& op2); // fraction > fraction

    //less than or equal to
    bool operator<= (int i); // fraction <= int
    bool operator<= (Fraction& op2); // fraction <= fraction

    //greater than or equal to
    bool operator>= (int i); // fraction >= int
    bool operator>= (Fraction& op2); // fraction >= fraction

    // equal to
    bool operator== (int i); // fraction == int
    bool operator== (Fraction& op2); // fraction == fraction

    // not equal to
    bool operator!= (int i); // fraction != int
    bool operator!= (Fraction& op2); // fraction != fraction

    
    friend std::istream& operator>> (std::istream& infile, Fraction& fraction); //stream extraction
    
private:
    int numerator   = 0;
    int denominator = 1;
    void reduce();
};
Fraction operator+ (int i, Fraction& f); // int + fraction
std::ostream& operator<< (std::ostream& outfile, const Fraction& f); // stream insertion
Fraction operator- (int i, Fraction& f); // int - fraction
Fraction operator* (int i, Fraction& f); // fraction * int
Fraction operator/ (int i, Fraction&f); // int / fraction
bool operator< (int i, Fraction& f); // int < fraction
bool operator<= (int i, Fraction& f); // int <= fraction
bool operator> (int i, Fraction& f); // int > fraction
bool operator>= (int i, Fraction& f); // int >= fraction
bool operator== (int i, Fraction& f); // int == fraction
bool operator!= (int i, Fraction& f); // int != fraction

#endif 