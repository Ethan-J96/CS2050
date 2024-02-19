#include "StudentArrayV3.h"
StudentArrayV3::StudentArrayV3( ){
    for(int i = 0; i<max_array_size; i++){
        members[i] = nullptr;
    }
    number_of_students = 0;
}
StudentArrayV3::~StudentArrayV3( ){
    for(int i = 0; i<max_array_size; i++){
        delete members[i];
        members[i] = nullptr;
    }
}
void StudentArrayV3::add( ){
    if(number_of_students != max_array_size){
        members[number_of_students] = new Student;
        number_of_students++;
    }
}
void StudentArrayV3::write( ){
    for(int i = 0; i < number_of_students; i++){
        members[i]->write(std::cout);
    }
}

