#include "Foo.h"
#include "UniquePtr.h"
#include <iostream>
using namespace std;
int main(){/*
    std::cout << "Creating first object...\n";
    UniquePtr p1{new Foo};
    {
        std::cout << "Creating second object with short lifetime...\n";
        UniquePtr p2{new Foo};
        std::cout << "Second object is about to go out of scope...\n";
    }
    std::cout << "Second object should be gone.\n"; */
    UniquePtr<Foo> p1{"cuh"};
    cout << "Testing '->' operator using 'serial()': " << p1->serial() << endl;
    cout << "Testing '*' operator using 'tag()': " << (*p1).tag() << endl;
    UniquePtr<Foo[]>    array_of_Foos{5};     // managed array of 5 `Foo`s.
    UniquePtr<double[]> array_of_doubles{10}; // managed array of 10 `double`s.
}