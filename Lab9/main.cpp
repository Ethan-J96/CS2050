#include "CityStateZip.h"
#include "CSZNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <limits>
#include <istream>
#include <fstream>

    using namespace std;

CityStateZip read_CityStateZip( std::istream& fin ) {
    std::string  city, state;
    unsigned int zip = 0;
    getline( fin, city, ',' );
    getline( fin, state, ',' );
    fin >> zip;
    fin.ignore( std::numeric_limits<std::streamsize>::max( ), '\n' );
    return CityStateZip{city, state, zip}; // creates a temporary CityStateZip object and returns it
}

int main(){
    std::ifstream fin{"city_list.txt"};
    if ( !fin ) {
    cout << "Error opening city_list.txt!\n";
    exit( 1 );
    }

    CSZNode n1{read_CityStateZip( fin )};
    CSZNode n2{read_CityStateZip( fin )};

    cout << "test CSZNodes:\n";
    cout << n1 << endl;
    cout << n2 << endl;
    cout << endl;

    cout << "Press <enter> to continue...\n";
    cin.get();
    BinarySearchTree city_tree;

    fin.clear();   // restore stream state so I/O may proceed
    fin.seekg(0);  // seek "get" to file start (byte #0)

    while (fin.good())
    city_tree.add_iteratively(read_CityStateZip(fin));

    cout << "Recursive Tree Listing of Iterative Additions\n";
    city_tree.write_recursively(cout);
}