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
Fraction Fraction::operator+ (int i){
    int n = (i*denominator)+numerator;
    int d = denominator; 
    return Fraction(n,d);
}
Fraction Fraction::operator+ (Fraction& op2) { // fraction + fraction
    int d = denominator*op2.denominator;
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    int n = n1 + n2;
    return Fraction(n,d);
}

Fraction operator+ (int i, Fraction& f){ // int + fraction
    return f + i;
}

std::ostream& operator<< (std::ostream& outfile, const Fraction& f){
    f.write(outfile);
    return outfile;
}
std::istream& operator>> (std::istream& infile, Fraction& f){
    char discard;
    infile >> f.numerator >> discard >> f.denominator;
    if(discard == '/'){
        return infile;
    }
    else{
        throw std::invalid_argument("Input stream was invalid...");
    }
    throw std::invalid_argument("Input stream was invalid...");
}

//subtraction 
Fraction Fraction::operator- (int i) { // fraction - int
    int n = numerator - (i * denominator);
    int d = denominator;
    return Fraction(n,d);
}
Fraction Fraction::operator- (Fraction& op2) { // fraction - fraction 
    int d = denominator * op2.denominator;
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    int n = n1 - n2;
    return Fraction(n,d);
}
//multiplication
Fraction Fraction::operator* (int i) { // fraction * int
    Fraction new_fraction(numerator * i, denominator);
    return new_fraction;
}
Fraction Fraction::operator* (Fraction& op2) { // fraction * fraction
    Fraction new_fraction(numerator*op2.numerator, denominator*op2.denominator);
    return Fraction(numerator*op2.numerator, denominator*op2.denominator);
}

//division 
Fraction Fraction::operator/ (int i) { // fraction / int
    int n = numerator*1;
    int d = denominator * i;
    return Fraction(n,d);
}
Fraction Fraction::operator/ (Fraction& op2) { // fraction / fraction
    int n = numerator * op2.denominator;
    int d = op2.numerator * denominator;
    return Fraction(n,d);
}

//comparison operators
//less than
bool Fraction::operator< (int i){ // fraction < int
    if(numerator < denominator*i){
        return true;
    }
    return false;
}
bool Fraction::operator< (Fraction& op2){ // fraction < fraction
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    if(n1 < n2){
        return true;
    }
    return false;
}

//greater than
bool Fraction::operator> (int i){ // fraction > int
    if(numerator > denominator*i){
        return true;
    }
    return false;
}
bool Fraction::operator> (Fraction& op2){ // fraction > fraction
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    if(n1 > n2){
        return true;
    }
    return false;
}

//less than or equal to
bool Fraction::operator<= (int i){ // fraction <= int
    if(numerator <= denominator*i){
        return true;
    }
    return false;
}
bool Fraction::operator<= (Fraction& op2){ // fraction <= fraction
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    if(n1 <= n2){
        return true;
    }
    return false;
}

//greater than or equal to
bool Fraction::operator>= (int i){ // fraction >= int
    if(numerator >= denominator*i){
        return true;
    }
    return false;
}
bool Fraction::operator>= (Fraction& op2){ // fraction >= fraction
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    if(n1 >= n2){
        return true;
    }
    return false;
}

// equal to
bool Fraction::operator== (int i){ // fraction == int
    if(numerator == denominator*i){
        return true;
    }
    return false;
}
bool Fraction::operator== (Fraction& op2){ // fraction == fraction
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    if(n1 == n2){
        return true;
    }
    return false;
}

// not equal to
bool Fraction::operator!= (int i){ // fraction != int
    if(numerator != denominator*i){
        return true;
    }
    return false;
}
bool Fraction::operator!= (Fraction& op2){ // fraction != fraction
    int n1 = numerator * op2.denominator;
    int n2 = op2.numerator * denominator;
    if(n1 != n2){
        return true;
    }
    return false;
}

//private function
void Fraction::reduce(){
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}

Fraction operator- (int i, Fraction& f){ // int - fraction
    return f-i;
}
Fraction operator* (int i, Fraction& f){ // fraction * int
    return f*i;
}
Fraction operator/ (int i, Fraction&f){ // int / fraction
    int n = i * f.getDenominator();
    int d = f.getNumerator();
    return Fraction(n, d);
}
bool operator< (int i, Fraction& f){ // int < fraction
    return f>i;
}
bool operator<= (int i, Fraction& f){ // int <= fraction
    return f>=i;
}
bool operator>(int i, Fraction& f){ // int > fraction
    return f<i;
}
bool operator>= (int i, Fraction& f){ // int >= fraction
    return f<=i;
}
bool operator== (int i, Fraction& f){ // int == fraction
    return f==i;
}
bool operator!= (int i, Fraction& f){ // int != fraction
    return f!=i;
}