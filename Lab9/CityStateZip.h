#ifndef CITYSTATEZIP_H_
#define CITYSTATEZIP_H_
#include <string>
#include <iostream>

class CityStateZip{
    public:
        CityStateZip(std::string _city, std::string _state, unsigned int _zip)
         : city{_city}, state{_state}, zip{_zip} {} 
        std::string getCity() const{ return city; }
        void writeCSZ(std::ostream& fout) const;
    private:
        std::string city;
        std::string state;
        unsigned int zip;
};

#endif