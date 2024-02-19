#include "StudentArrayV4.h"
StudentArrayV4::StudentArrayV4( ){
    physicalArraySize = 3; //initial physical size
    number_of_students = 0;
    members = new Student*[physicalArraySize];
    // for(int i = 0; i < physicalArraySize; i++){
    //     members[i] = nullptr;
    // }
}
StudentArrayV4::~StudentArrayV4( ){
    for(int i = 0; i < physicalArraySize; i++){
        delete members[i];
    }
    delete[] members;
}
void StudentArrayV4::add( ){
    if(number_of_students == physicalArraySize){
        physicalArraySize += 3;
        Student** _members = new Student*[physicalArraySize];
        for(int i = 0; i < number_of_students-1; i++){
            _members[i] = members[i];
        }
        delete[] members;
        members = _members;
    }

    members[number_of_students] = new Student;
    number_of_students++;
}
void StudentArrayV4::write( ){
    std::cout << "yes";
    for(int i = 0; i < number_of_students; i++){
        members[i]->write();
    }
}