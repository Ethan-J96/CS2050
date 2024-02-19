#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DynamicArray.h"
// function prototypes
//void displayArray(int* array, int size);
void displayArray(const int* const array, int size);
//void getData (int* const array, int size);
int* getData(int& sizeOfDynArray);
void createAndDisplayDynamicArray(int size);

//main program execution
int main(){
    int  values[5] = {325, 879, 120, 459, 735};
    int* valuePtr  = values;  // valuePtr is a pointer to values.
    std::cout << "valuePtr:   " << valuePtr  << std::endl;
    std::cout << "*valuePtr:  " << *valuePtr << std::endl << std::endl;
    double  payRate = 10.25;
    double* ratePtr = &payRate;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "address of payRate:      " << ratePtr  << std::endl;
    std::cout << "value stored in payRate: " << *ratePtr << std::endl << std::endl;
    *ratePtr = 12.50;
    std::cout << "altered value of payRate:  " << payRate << std::endl << std::endl;
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
    std::cout << "address of price:  " <<  price << std::endl;
    std::cout << "value of price:    " << *price << std::endl << std::endl;
    delete price;     // de-allocates the memory (the OS will mark it as "available")
    price = nullptr;  // null the pointer so that it cannot be dereferenced again.
    //int sizeOfDynArray;
    //std::cout << "How many values would you like to enter?  ";
    //std::cin  >> sizeOfDynArray;
    //int* dynArray = new int[sizeOfDynArray];
    //getData(dynArray, sizeOfDynArray);
    //displayArray(dynArray, sizeOfDynArray);
    //delete [] dynArray;
    //dynArray = nullptr; // null the pointer for safety.
    int sizeOfDynArray;
    int* dynArray = getData(sizeOfDynArray);
    displayArray(dynArray, sizeOfDynArray);
    delete [] dynArray;
    dynArray = nullptr;   // null the pointer for safety.
    // Create a dynamic array with a size of 5
    DynamicArray arr(5);

    // Test the 'at' method and demonstrate pass-by-reference characteristics
    try {
        // Read and print an element
        std::cout << "Element at index 2: " << arr.at(2) << std::endl;

        // Modify an element
        arr.at(3) = 42;
        std::cout << "Modified element at index 3: " << arr.at(3) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

//function definitions
/*void displayArray(int* array, int size)
{
   std::cout << "Array values:  \n";
   for (int i = 0; i < size; ++i){
        std::cout << array[i] << std::endl;
    }
    std::cout << std::endl;
}
*/
void displayArray(const int* const array, int size)
{
    const int* const end = array + size;                         // mark the end of the array
    std::cout << "Array values:  \n";
    for (const int* current = array; current != end; current++){ // "moves" current toward end
        std::cout << *current << std::endl;
    }
    std::cout << std::endl;
}
/*void getData (int* const array, int size)
{
    for (int i = 0; i < size; ++i){
        std::cout << "Enter value " << (i + 1) << ":  ";
        std::cin  >> array[i];
    }
}
*/
int* getData (int& sizeOfDynArray)
{
   std::cout << "How many more values would you like to enter?  ";
   std::cin  >> sizeOfDynArray;
   int* dynamicArray = new int[sizeOfDynArray];
   for (int i = 0; i < sizeOfDynArray; ++i){
      std::cout << "Enter value " << (i + 1) << ":  ";
      std::cin  >> dynamicArray[i];
   }
   return dynamicArray;
}

void createAndDisplayDynamicArray(int size) {
    // Lots of comments to demonstrate understanding
    // Allocate memory for a dynamic integer array of 'size' elements
    int* darray = new int[size];
    // Fill the dynamic array with integers from 100 to 100 + size
    for (int i = 0; i < size; i++) {
        darray[i] = 100 + i;
    }
    // Display the elements of the dynamic array
    displayArray(darray,size);
    // Deallocate the dynamic array to release the memory it occupies
    delete[] darray;
    // Set the pointer to nullptr to avoid accessing the memory location after deallocation
    darray = nullptr;
    // At this point, the dynamic array no longer exists, and the memory it occupied has been returned to the system.
}