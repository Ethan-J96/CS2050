#include "StudentArrayV1.h"
#include "StudentArrayV2.h"
#include "StudentArrayV3.h"
#include "StudentArrayV4.h"
#include "Student.h"
#include <iostream>
int main( ) {
      // version 1 testing 
    StudentArrayV1 cs1114;

    std::cout << "contents of cs1114:\n";
    cs1114.write( );

        // version 2 testing 
    std::cout << "Enter the number of students for version 2: ";
    int number_of_students;
    std::cin >> number_of_students;

    StudentArrayV2 cs2114( number_of_students );
    std::cout << "contents of cs2114:\n";
    cs2114.write( );
        // version 3
    StudentArrayV3 cs2124;
    std::cout << "Enter Student data for version 3 (y/n)? ";
    char option;
    std::cin >> option;
    while ( option == 'y' || option == 'Y' ) {
        cs2124.add( );
        std::cout << "Enter more student data (y/n)? ";
        std::cin >> option;
    }
    std::cout << "contents of cs2124:\n";
    cs2124.write( );
        // version 4
    StudentArrayV4 cs3000;
    std::cout << "Enter Student data for version 4 (y/n)? ";
    char option4;
    std::cin >> option4;
    while ( option4 == 'y' || option4 == 'Y' ) {
        cs3000.add( );
        std::cout << "Enter more student data (y/n)? ";
        std::cin >> option4;
    }
    std::cout << "contents of cs3000:\n";
    cs3000.write( );

    return 0;
}