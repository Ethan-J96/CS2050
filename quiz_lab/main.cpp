#include "Animal.h"
#include "Dog.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Animal* animal = new Dog("Buddy", 3, "Golden Retriever");
    animal->speak();
    animal->displayInfo();
    // TODO: Call the displayInfo method using the 'animal' pointer

    delete animal;
    return 0;
}