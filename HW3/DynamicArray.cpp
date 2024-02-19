#include "DynamicArray.h"
#include <stdexcept>

DynamicArray::DynamicArray(int size){
    if(size > 0){
        int* earray = new int[size];
        _array = earray;
        _size = size;
        //if(_array != nullptr){
        //    std::cout << "yup";
        //}
    }
}
int& DynamicArray::at(int i) {
    // Check if 'i' is out of bounds
    if (i < 0 || i >= _size) {
        throw std::out_of_range("Array index out of range.");
    }
    // Return the array element at the specified index
    return _array[i];
}
DynamicArray::~DynamicArray(){
    delete[] _array;
    _array = nullptr;
    //std::cout << "yep";
}