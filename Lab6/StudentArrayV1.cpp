 #include "StudentArrayV1.h"
 #include <iostream>
    StudentArrayV1::StudentArrayV1( ) = default;
    void StudentArrayV1::write( ){
        for(int i = 0; i < number_of_students; i++){
            members[i].write(std::cout);
        }
    }