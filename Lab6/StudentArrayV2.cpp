#include "StudentArrayV2.h"
#include <iostream>
StudentArrayV2::StudentArrayV2( int size ){
    if(size > 0){
        number_of_students = size;
        Student* _members = new Student[number_of_students];
        members = _members;
    }
}
StudentArrayV2::~StudentArrayV2( ){
    delete[] members;
    members = nullptr;
    number_of_students = 0;
}
void StudentArrayV2::write( ){
    for(int i = 0; i < number_of_students; i++){
        members[i].write(std::cout);
    }
}