#ifndef STUDENTARRAYV2_H_
#define STUDENTARRAYV2_H_
#include "Student.h"
class StudentArrayV2 {  // version 2: dynamic array of objects
public:
    StudentArrayV2( int size );
    ~StudentArrayV2( );
    void write( );

private:
    Student* members            = nullptr;
    int      number_of_students = 0;
};
#endif