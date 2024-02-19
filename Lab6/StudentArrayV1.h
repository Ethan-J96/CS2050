#ifndef STUDENTARRAYV1_H_
#define STUDENTARRAYV1_H_
#include "Student.h"
class StudentArrayV1 {  // version 1: automatic array of objects
public:
    StudentArrayV1( );
    void write( );

private:
    const static int n_members = 5;
    Student          members[n_members];
    int              number_of_students = n_members;
};
#endif