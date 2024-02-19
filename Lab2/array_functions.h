#ifndef ARRAY_FUNCTIONS_H_
#define ARRAY_FUNCTIONS_H_
#include "Rectangle.h"
#include <iostream>
#include <cstdlib>
void fill_random(int* array, int array_size); // take an array and its size as parameters
// and assign a random number between 1 and 1000 to each element 
double average(int* array, int array_size); // take an array and its size and calculate 
// the average of the array 
void make_puzzle(char c_array[][15], int array_size); // fill a 2d array with random characters a through z
void print_puzzle(char c_array[][15], int array_size); // print a 2d array
void print_rectangles(Rectangle r_array[], int r_array_size); // print an array of type rectangle class in the format "1: 1 x 1"
void random_rectangles(Rectangle r_array[], int r_array_size);

void make_puzzle(char c_array[][15], int array_size){
    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < array_size; j++){ // nested for loop to fill every element before moving to the next row
            c_array[i][j] = (static_cast<char>(rand() % 26 + 'a'));
        }
    }
}
void print_puzzle(char c_array[][15], int array_size){
    for(int i = 0; i < array_size; i++){
        for(int j = 0; j < array_size; j++){
            std::cout << c_array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
void fill_random(int* array, int array_size){
    for(int i = 0; i < array_size; i++){
        array[i] = (rand() % 1000 +1);
    }
}
double average(int* array, int array_size){
    int total = 0;
    for(int i = 0; i < array_size; i++){
        total += array[i];
    }
    return static_cast<double>(total) / array_size;
}

void print_rectangles(Rectangle r_array[], int r_array_size){
    for(int i = 0; i < r_array_size; i++){
        std::cout << i+1 << ": " << r_array[i].get_length() << " x " << r_array[i].get_width() << std::endl;
    }
}

void random_rectangles(Rectangle r_array[], int r_array_size){
    for(int i = 0; i < r_array_size; i++){
        r_array[i].set_length(rand() % 100 + 1);
        r_array[i].set_width(rand() % 100 + 1);
    }
}

#endif