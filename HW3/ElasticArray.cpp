#include "ElasticArray.h"
#include <stdexcept>

//ctor
ElasticArray::ElasticArray(int size){
    if(size > 0){
        int* darray = new int[size];
        _array = darray;
        _size = size;
        //if(_array != nullptr){
        //    std::cout << "yup";
        //}
    }
}

//accessors + bounds checking is included for exception throw
int& ElasticArray::at(int i) {
    // Check if 'i' is out of bounds
    if (i < 0 || i >= _size) {
        throw std::out_of_range("Array index out of range.");
    }
    // Return the array element at the specified index
    return _array[i];
}
int ElasticArray::front(){
    if(_array == nullptr){
        throw std::out_of_range("Array is empty");
    }
    return _array[0];
}
int ElasticArray::back(){
    if(_array == nullptr){
        throw std::out_of_range("Array is empty");
    }
    return _array[_size];
}

//destructor, release the mem and null the pointer 
ElasticArray::~ElasticArray(){
    delete[] _array;
    _array = nullptr;
    //std::cout << "yep";
}