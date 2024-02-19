#include "ThinArrayWrapper.h"
#include "ArrayWrapper.h"
#include "StringWrapper.h"
int main(){
    //testing the super thin array wrapper
    struct SuperThinArrayWrapper STAW;
    for(int i = 0; i < 20; i++){
        STAW.array[i] = i*10;
    }
    print_array(STAW);
    
    //testin the thin array wrapper
    std::cout << ThinArrayWrapper::size << '\n';
    struct ThinArrayWrapper TAW;
    std::cout << TAW.size << '\n';
    //fill_array_v0(TAW); replaced by newer version
    //fill_array_v1(TAW); replaced by newer version
    struct ThinArrayWrapper TAW2 = fill_array_v2(); // newest version of fill array, locally creates and returns a filled array
    print_array(TAW2);

    // testing the array wrapper
    ArrayWrapper AW(30);
    for(int i = 0; i < AW.get_size(); i++){
        AW.set(i, i);
    }
    for(int i = 0; i < AW.get_size(); i++){
        std::cout << i+1 << ": " << AW.get(i) << std::endl;
    }

/* 
The following code is from the homework document
*/
////////////////////////////////////////////////////////////////////////////////
    ArrayWrapper catch_example_array(20);
    for(int i = 0; i < catch_example_array.get_size(); ++i){
        catch_example_array.set(i, (i+1));
    }
    int selected_index = 0;
    while(selected_index >= 0){
        std::cout << "Enter an index to print the item.  (-1 to stop): ";
        std::cin  >> selected_index;
        if(selected_index != -1){
            try{
                int value = catch_example_array.get(selected_index);
                std::cout << "The item at index " << selected_index
                        << " is " << value << '\n';
            }
            catch(std::out_of_range){
                std::cout << "The index " << selected_index 
                        << " is not a valid index.\n";
                std::cout << "Valid indices are 0 to "
                        << catch_example_array.get_size() - 1
                        << '\n';
                // Reset to allow the loop to continue if index was negative.
                selected_index = 0;  
            }
        }
    }
//////////////////////////////////////////////////////////////////////////////////

    const char* sampleText = "Hello, World!";

    // Create a StringWrapper object
    StringWrapper strWrapper(sampleText);

    // Test get() and set() methods
    std::cout << "Original String: ";
    strWrapper.write();
    std::cout << std::endl;

    // Get and display characters at various indices
    std::cout << "Character at index 0: " << strWrapper.get(0) << std::endl;
    std::cout << "Character at index 7: " << strWrapper.get(7) << std::endl;

    // Set a character at index 0
    strWrapper.set(0, 'M');
    std::cout << "Modified String: ";
    strWrapper.write();
    std::cout << std::endl;

    // Read a new line from the user
    std::cout << "Enter a new string: ";
    strWrapper.readline();
    std::cout << "New String: ";
    strWrapper.write();
    std::cout << std::endl;
}