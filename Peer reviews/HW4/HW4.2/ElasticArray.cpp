/**
 *******************************************************************************
 * @file    ElasticArray.cpp
 * @brief   This .cpp file is the implementation file for the class ElasticArray2

 * @remarks
 *      Course:        Computer Science 2124, Fall 2023
 *      Due Date:      Sunday, 1st October, 2023
 *      Instructor:    Mr. Mark Gilland
 *
 * @author  Shreyansh Bakhariya
 * @date    1st October, 2023
 *******************************************************************************
**/


#include "ElasticArray.h"
#include <iostream>
#include <stdexcept>

ElasticArray::ElasticArray(int size) : _size(size) {
    _array = new int[size];
    std::cout << "ElasticArray created with size " << size << std::endl;
}

ElasticArray::~ElasticArray() {
    delete[] _array;
    std::cout << "ElasticArray destroyed, memory freed." << std::endl;
}

int ElasticArray::size() const {
    return _size;
}

int& ElasticArray::at(int i) {
    if (i < 0 || i >= _size) {
        throw std::out_of_range("Array index out of range.");
    }
    return _array[i];
}

int* ElasticArray::getData(){
    return _array;
}

int ElasticArray::front() const {
    if (_size == 0) {
        throw std::out_of_range("Cannot retrieve a value from an empty container.");
    }
    return _array[0];
}

int ElasticArray::back() const {
    if (_size == 0) {
        throw std::out_of_range("Cannot retrieve a value from an empty container.");
    }
    return _array[_size - 1];
}

ElasticArray::ElasticArray(const ElasticArray& source) : _size(source._size) {
    _array = new int[_size];
    std::copy(source._array, source._array + _size, _array);
}

ElasticArray& ElasticArray::operator=(const ElasticArray& source) {
    if (this == &source) {
        return *this; 
    }

    delete[] _array;

    _size = source._size;
    _array = new int[_size];
    std::copy(source._array, source._array + _size, _array);

    return *this;
}

void ElasticArray::push_back(int value) {
    if (_size == _max_size) {
        int new_max_size = (_max_size == 0) ? 16 : _max_size * 2;
        int* new_array = new int[new_max_size];
        for (int i = 0; i < _size; ++i) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
        _max_size = new_max_size;
    }
    _array[_size++] = value;
}

int ElasticArray::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("Cannot perform pop_back() on an empty container.");
    }
    return _array[--_size];
}

void ElasticArray::shrink_to_fit() {
    if (_size == 0) {
        delete[] _array;
        _array = nullptr;
        _max_size = 0;
    } else {
        int* new_array = new int[_size];
        for (int i = 0; i < _size; ++i) {
            new_array[i] = _array[i];
        }
        delete[] _array;
        _array = new_array;
        _max_size = _size;
    }
}

ElasticArray ElasticArray::operator+(const ElasticArray& rhs) const {
    ElasticArray result(_size + rhs._size);
    for (int i = 0; i < _size; ++i) {
        result._array[i] = _array[i];
    }
    for (int i = 0; i < rhs._size; ++i) {
        result._array[_size + i] = rhs._array[i];
    }
    result._size = _size + rhs._size;
    return result;
}