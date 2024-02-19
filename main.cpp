#include <iostream>
int main(){
    int x = 10;
    int *p1 = &x;
    float y = 10;
    float* p2 = &y;
    char c = 'a';
    char *p3 = &c;
    double d = 30;
    double * p4 = &d;

    std::cout << *p1 << *p2 << *p3 << *p4 << std::endl;
}