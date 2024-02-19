#include "ElasticArray.h"
#include <stdexcept>

//ctor
ElasticArray::ElasticArray(int size){
    _array = new int[size];
    _size = size;
    _max_size = size;
    for (int i = 0; i < _size; i++) {
        _array[i] = 0; // Initialize elements to zero
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
    return _array[_size - 1];
}

void ElasticArray::push_back(int a){//insert parameter into end of arrray
    if(_size < _max_size){ // if the physical size is greater than the logical size then add the new element to the end of the array
        _array[_size] = a;
        _size++;
    }
    else if (_max_size == 0){ // if the physical size is zero, set it to 16.
        _max_size = 16;
        _array = new int[_max_size];
        _array[_size] = a;
        _size++;
    }
    else if (_max_size == _size){ // if there is no more space to add another element, double the size of the physical array
                                //, copy the data into the new array, free the previous array, and point the original pointer
                                // to the zeroth element of the new array 
        _max_size *= 2;
        int* copy = new int[_max_size];
        for (int i = 0; i < _size; i++) {
            copy[i] = _array[i];
        }
        /*for(int* it = begin(); it != end(); it++){ //could do it with pointer arithmetic
            *copy = *it;
            copy++;
        }*/
        delete[] _array; // free the array
        _array = copy; 
        _array[_size] = a;
        _size++;
    }
}
int ElasticArray::pop_back(){//return value of the item at end of the array and then remove it 
    int pop = 0;
    if(_array == nullptr || _size == 0 || _max_size == 0){
        throw std::out_of_range("Cannot perform pop_back on an empty container.");
    }
    else{
        pop = _array[_size-1];
        _size = _size - 1;
    }
    return pop;
}
void ElasticArray::shrink_to_fit(){//shrink the internal storage to match the current logical size
    if(_max_size > 0 && _size == 0){
        delete[] _array;
        _array = nullptr;
        _max_size = 0;
    }
    else if (_max_size > 0 && _size < _max_size) {
        int* copy = new int[_size];
        for (int i = 0; i < _size; i++) {
            copy[i] = _array[i];
        }
        delete[] _array; // free the array
        _array = copy; 
        _max_size = _size;
    }
}
int* ElasticArray::begin(){//return an iterator to the front of the array
    //int* it = &(_array[0]);
    //return it;
    return &_array[0];
}
int* ElasticArray::end(){//return an iterator to the next byte following the end of the array
    return &_array[_size];
}

ElasticArray::~ElasticArray(){
    delete[] _array;
    _array = nullptr;
    //std::cout << "yep";
}