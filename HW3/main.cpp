#include "ElasticArray.h"
#include "DynamicArray.h"
#include <iostream>

//prototype for test function
void test_ElasticArray_copy_ctor(ElasticArray a);

int main(){
    int size = 10;
    //construct an elastic array and display its contents
    ElasticArray eArray(size);
    for(int i = 0; i < size; i++){
        std::cout << i+1 << ": " << eArray.at(i) << std::endl;
    }
    //default construct an elastic array
    ElasticArray this_requires_a_default_ctor;

/*
    //testing what happens without a copy constructor
    DynamicArray source_array{5};
    DynamicArray destination_array{5};

    for(int i = 0; i < source_array.size(); ++i){
        source_array.at(i) = (i + 1); // fills with {1,2,3,4,5}
    }
    // Try to copy:
    destination_array = source_array;    // doesn't do what you want it to do...

    // change the supposed "copy":
    for(int i = 0; i < destination_array.size(); ++i){
        destination_array.at(i) *= 2;      // double all the values in the "copy"
    }

    // Now let's have a look at the original array. (It *should* be the same
    // as before... but is it?)
    std::cout << "Original array should be:\n";
    std::cout << "1\t2\t3\t4\t5\n";
    std::cout << "It is:\n";
    for(int i = 0; i < source_array.size(); ++i){
        std::cout << source_array.at(i) << '\t';
    }
    std::cout << std::endl;
*/

    //testing what happens with a copy constructor
    ElasticArray _source_array{5};
    ElasticArray _destination_array{5};

    for(int i = 0; i < _source_array.size(); ++i){
        _source_array.at(i) = (i + 1); // fills with {1,2,3,4,5}
    }
    // Try to copy:
    _destination_array = _source_array;    // doesn't do what you want it to do...

    // change the supposed "copy":
    for(int i = 0; i < _destination_array.size(); ++i){
        _destination_array.at(i) *= 2;      // double all the values in the "copy"
    }

    // Now let's have a look at the original array. (It *should* be the same
    // as before... but is it?)
    std::cout << "Original array should be:\n";
    std::cout << "1\t2\t3\t4\t5\n";
    std::cout << "It is:\n";
    for(int i = 0; i < _source_array.size(); ++i){
        std::cout << _source_array.at(i) << '\t';
    }
    std::cout << std::endl;


    std::cout << "If copy constructor is working the array should be:\n";
    std::cout << "1\t2\t3\t4\t5\n";
    test_ElasticArray_copy_ctor(_source_array);
    std::cout << "It is:\n";
    for(int i = 0; i < _source_array.size(); ++i){
        std::cout << _source_array.at(i) << '\t';
    }
    std::cout << std::endl;
    
}

void test_ElasticArray_copy_ctor(ElasticArray a){
    for(int i = 0; i < a.size(); ++i){
        a.at(i) = 999;  // just a value that will be easy to notice when printed.
    }
}