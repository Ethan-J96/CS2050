#ifndef STUDENTARRAYV4_H_
#define STUDENTARRAYV4_H_
#include "Student.h"
class StudentArrayV4 {  // version 4: dynamic array of object pointers
public:
    StudentArrayV4( );
    ~StudentArrayV4( );
    void add( );
    void write( );

private:
    Student** members            = nullptr;
    int       number_of_students = 0;
    int       physicalArraySize  = 0;
};
#endif