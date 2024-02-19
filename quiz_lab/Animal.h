#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string name;
    int age;

    Animal(string n, int a) : name(n), age(a) {} // constructor
    virtual void speak() const{ // virtual function named 'speak' that prints a generic message
        cout << "makes a sound. " << endl;
    }
    virtual ~Animal(){cout<<"destructing animal"<<endl;}


    virtual void displayInfo() { // display generic animal info
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

#endif