#include "ElasticArray.h"
#include <iostream>

//prototype for test function
void test_ElasticArray_copy_ctor(ElasticArray a);

int main(){
    /*
    int size = 10;
    //construct an elastic array and display its contents
    ElasticArray eArray(size);
    for(int i = 0; i < size; i++){
        std::cout << i+1 << ": " << eArray.at(i) << std::endl;
    }
    //default construct an elastic array
    ElasticArray this_requires_a_default_ctor;

    //testing what happens with a copy constructor
    ElasticArray _source_array{5};
    ElasticArray _destination_array{5};

    for(int i = 0; i < _source_array.size(); ++i){
        _source_array.at(i) = (i + 1); // fills with {1,2,3,4,5}
    }
    // Try to copy:
    _destination_array = _source_array;   

    // change the supposed "copy":
    for(int i = 0; i < _destination_array.size(); ++i){
        _destination_array.at(i) *= 2;      // double all the values in the copy
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
*/
    // HW 4 testing
    /*
    ElasticArray range_loop_test{10};
    for(int i = 0; i < 10; ++i){       // fill the array with a "normal" for loop
        range_loop_test.at(i) = (i+1); // using sequential values in each element
    }
    // Now, print the array using a range-based for:
    for(int v : range_loop_test){
        std::cout << v << "\t";
    }
    */
    // Create an ElasticArray object
    ElasticArray arr(10);
    // Test push_back
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    arr.shrink_to_fit();

    // Test size and capacity
    std::cout << "Size: " << arr.size() << std::endl;
    std::cout << "Capacity: " << arr.capacity() << std::endl;

    // Test indexing
    std::cout << "Element at index 1: " << arr[1] << std::endl;

    // Test front and back
    std::cout << "Front element: " << arr.front() << std::endl;
    std::cout << "Back element: " << arr.back() << std::endl;

    // Test pop_back
    int popped = arr.pop_back();
    std::cout << "Popped element: " << popped << std::endl;

    // Test begin and end
    int* it = arr.begin();
    int* end = arr.end();
    std::cout << "Elements in the array: ";
    while (it != end) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Test copy constructor and assignment operator
    ElasticArray arr2 = arr; // Copy constructor
    ElasticArray arr3;
    arr3 = arr2; // Assignment operator
    std::cout << "arr2 size: " << arr2.size() << std::endl;
    std::cout << "arr3 size: " << arr3.size() << std::endl;

    // Test concatenation
    ElasticArray arr4(3);
    arr4.push_back(4);
    arr4.push_back(5);
    ElasticArray arr5;
    arr5 = arr + arr4;
    std::cout << "Concatenated array size: " << arr5.size() << std::endl;
    // Test shrink_to_fit
    arr5.shrink_to_fit();
    std::cout << "Shrunk array capacity: " << arr5.capacity() << std::endl;
}

void test_ElasticArray_copy_ctor(ElasticArray a){
    for(int i = 0; i < a.size(); ++i){
        a.at(i) = 999;  // just a value that will be easy to notice when printed.
    }
}

