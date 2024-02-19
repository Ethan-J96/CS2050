#include "Fraction.h"
#include <stdexcept>
#include "gcd.h"

//standard constructor 
Fraction::Fraction (int n, int d){
    if(d == 0){ // validity check
        throw std::overflow_error("Zero denominator is not allowed.");
    }
    else{
        numerator = n;
        denominator = d;
    }
    reduce();
}

//method operators
Fraction Fraction::add (int i) const{
    int n = (i*denominator)+numerator;
    int d = denominator; 
    return Fraction(n,d);
}

//output
void Fraction::write(std::ostream& strm) const{
    strm << numerator << "/" << denominator;
}

//overloaded operators 
Fraction Fraction::operator+ (int i) const{
    int n = (i*denominator)+numerator;
    int d = denominator; 
    return Fraction(n,d);
}
Fraction Fraction::operator+ (const Fraction& op2) const{ // fraction + fraction
    int d = denominator*op2.denominator;
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    int n = n1 + n2;
    return Fraction(n,d);
}

Fraction operator+ (int i, const Fraction& f){ // int + fraction
    int n = (i*f.denominator)+f.numerator;
    int d = f.denominator; 
    return Fraction(n,d);
}

std::ostream& operator<< (std::ostream& outfile, const Fraction& f){
return outfile << f.numerator<<"/"<<f.denominator;
}

//private function
void Fraction::reduce(){
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}