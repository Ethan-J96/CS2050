
#include "array_functions.h"
#include "Rectangle.h"
#include "c_string_utils.h"
#include <cstring>

int main(){
    // int array
    srand(42);// seed for rng
    int i_array[1000]; // create instance of array
    fill_random(i_array, 1000); // use function to fill array with random numbers 

    std::cout << "Array average : " << average(i_array, 1000) << std::endl; // print the average of the previously made array

    // character array
    int array_size = 15;
    char c_array[15][15]; // create instance of 2d array
    make_puzzle(c_array,array_size); // fill the 2d array with random letters
    print_puzzle(c_array,array_size); // print the 2d array as a box so the user can identify the underlying structure of a 2d array

    // rectangle
    Rectangle r_array[20];
    print_rectangles(r_array,20);

    // strings
//char example[]{ 'H', 'e', 'l', 'l', 'o', '\0' };
//char example2[]{ "Hello" };
    char state[]{ "Arkansas" };
    std::cout << state << " has " << strlen(state)
          << " (logical) characters and occupies "
          << sizeof(state) << " bytes.\n";

    std::cout << state << " has " << my_strlen(state)
          << " (logical) characters and occupies "
          << sizeof(state) << " bytes.\n";

}
