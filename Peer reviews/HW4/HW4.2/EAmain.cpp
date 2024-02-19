/**
 *******************************************************************************
 * @file    EAmain.cpp
 * @brief   This .cpp contains the main of this assignment and has codings of 
 *          DynamicArray done in lab and also the use of ElasticArray's instructions.
 *          It follows with ElasticArray2.

 * @remarks
 *      Course:        Computer Science 2124, Fall 2023
 *      Due Date:      Sunday, 1st October, 2023
 *      Instructor:    Mr. Mark Gilland
 *
 * @author  Shreyansh Bakhariya
 * @date    1st October, 2023
 *******************************************************************************
**/

#include <iostream>
#include <iomanip>
#include "ElasticArray.h"

using std::fixed;
using std::setprecision;

void displayArray(const int* const array, int size);
void getData(int* const array, int& size);
void test_ElasticArray_copy_ctor(ElasticArray a);


int main() {
    int values[5] = {325, 879, 120, 459, 735};
    int* valuePtr = values;

    std::cout << "valuePtr: " << valuePtr << std::endl;
    std::cout << "*valuePtr: " << *valuePtr << std::endl << std::endl;

    double payRate = 10.25;
    double* ratePtr = &payRate;
    std::cout << fixed << setprecision(2);
    std::cout << "address of payRate: " << ratePtr << std::endl;
    std::cout << "value stored in payRate: " << *ratePtr << std::endl << std::endl;

    *ratePtr = 12.50;
    std::cout << "altered value of payRate: " << payRate << std::endl;

    double grossPay;
    grossPay = payRate * 40;
    std::cout << "grossPay calculated with payRate:   " << grossPay << std::endl;
    grossPay = *ratePtr * 40;
    std::cout << "grossPay calculated using ratePtr:  " << grossPay << std::endl << std::endl;

    std::cout << "values[0]:  " << values[0] << std::endl;
    std::cout << "*valuePtr:  " << *valuePtr << std::endl;
    valuePtr++;
    std::cout << "values[1]:  " << values[1] << std::endl;
    std::cout << "*valuePtr after increment:  " << *valuePtr << std::endl << std::endl;

    displayArray(values, 5);

    double* price = new double;
    *price = 88.25;
    std::cout << "address of price:  " << price << std::endl;
    std::cout << "value of price:    " << *price << std::endl << std::endl;
    delete price;
    price = nullptr;

    int sizeOfDynArray;
    std::cout << "How many values would you like to enter?  ";
    std::cin >> sizeOfDynArray;
    
    if(sizeOfDynArray < 10 || sizeOfDynArray > 10000){
        std::cout << "Array is out of bounds." << std::endl;
        return 1;
    }

    ElasticArray dynArray(sizeOfDynArray);
    int* dataArray = dynArray.getData();

    for (int i = 0; i < dynArray.size(); ++i){
        dataArray[i] = 100;
    }

    std::cout << "ElasticArray contents: ";
    for (int i = 0; i < dynArray.size(); ++i) {
        std::cout << dynArray.at(i) << " ";
    }
    std::cout << std::endl;

    //ElasticArray

    ElasticArray emptyArray;
    std::cout << "Empty Array Size: " << emptyArray.size() << std::endl;

    ElasticArray testArray(5);
        for (int i = 0; i < testArray.size(); ++i){
        testArray.at(i) = i + 1;
    }

    std::cout << "Front: " << testArray.front() << std::endl;
    std::cout << "Back: " << testArray.back() << std::endl;

    ElasticArray copyArray = testArray;
    ElasticArray assignedArray(3);
    assignedArray = testArray;

    test_ElasticArray_copy_ctor(testArray);

    std::cout << "Original Array: ";
    for (int i = 0; i < testArray.size(); ++i){
        std::cout << testArray.at(i) << " ";
    }

    std::cout << std::endl;

    //ElasticArray2

    for (int i = 0; i < 10; ++i){
        testArray.push_back(i);
    }
    
    std::cout << "Popped element: " << testArray.pop_back() << std::endl; 
    std::cout << "Capacity: " << testArray.capacity() << std::endl;
    std::cout << "Size: " << testArray.size() << std::endl;
    std::cout << "Element at index 2: " << testArray[2] << std::endl;
    std::cout << "Elements in the Array: " << std::endl;
        for (int value : testArray){
            std::cout << value << " ";
        }
        std::cout << std::endl;

    testArray.shrink_to_fit();
    std::cout << "After shrinking, the Capacity is: " 
              << testArray.capacity() << std::endl;

    try {
        while(true){
            testArray.pop_back();
        }
    }

    catch (const std::out_of_range& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    ElasticArray range_loop_test{10};//Testing loop
        for(int i = 0; i < 10; ++i){       
            range_loop_test.at(i) = (i+1); 
        }

        for(int v : range_loop_test){
            std::cout << v << "\t";
        }    
            
    return 0;

}

void displayArray(const int* const array, int size) {
    const int* const end = array + size;
    std::cout << "Array values:  \n";
    for (const int* current = array; current != end; current++) {
        std::cout << *current << std::endl;
    }
    std::cout << std::endl;
}

void getData(int* const array, int& size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value " << (i + 1) << ":  ";
        std::cin >> array[i];
    }
}

void test_ElasticArray_copy_ctor(ElasticArray a){
    for (int i = 0; i < a.size(); ++i){
        a.at(i) = 999;
    }
}


