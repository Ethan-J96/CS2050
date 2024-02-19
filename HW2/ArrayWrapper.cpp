#include "ArrayWrapper.h"
#include <stdexcept>
int ArrayWrapper::get_size() const{
    return size;
}
int ArrayWrapper::get(int index) const{
    if(index >= 0 && index <= size){
        return array[index];
    }
    else{
        throw std::out_of_range{"Array index out of bounds."};
    }
}
void ArrayWrapper::set(int index, int value){
    if(index >= 0 && index <= size){
        array[index] = value;
    }
    else{
        throw std::out_of_range{"Array index out of bounds."};
    }
}

