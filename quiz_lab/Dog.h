#ifndef DOG_H_
#define DOG_H_
#include <iostream>
#include <string>
#include "Animal.h"

using namespace std;

class Dog : public Animal {
public:
    string breed;

    Dog(string n, int a, string b) : Animal(n, a), breed(b) {} //constructor

    void speak() const override{ //Override the speak method to print a message specific to dogs
        cout << name << " barks." << endl;
    }
    ~Dog(){cout<<"destructing dog"<<endl;}

    void displayInfo() override{ //Display generic information as well as information unique to dog derived class (breed)
    Animal::displayInfo();
    cout << "Breed: " << breed << endl;
    }
};

#endif