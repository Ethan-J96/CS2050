#include <iostream>
#include "ElasticArray.h"

int main(){
    ElasticArray this_requires_a_default_ctor;

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

    test_ElasticArray_copy_ctor();


ElasticArray range_loop_test{10};
for(int i = 0; i < 10; ++i){       // fill the array with a "normal" for loop
    range_loop_test.at(i) = (i+1); // using sequential values in each element
}
// Now, print the array using a range-based for:
for(int v : range_loop_test){
    std::cout << v << "\t";
}

void front();
void back();
void push_back(10);
int pop_back();
void shrink_to_fit();
iterator begin();
iterator end();

ElasticArray operator+(const ElasticArray& arr) const;

}