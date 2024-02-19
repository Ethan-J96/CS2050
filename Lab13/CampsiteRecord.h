#ifndef CAMPSITERECORD_H
#define CAMPSITERECORD_H
#include <iostream>
using namespace std;

struct CampsiteRecord {
    CampsiteRecord();
    CampsiteRecord(int number, const char description[], bool has_electric, double rate);
    static const int desc_size = 128;         
    int              number;                  
    char             description[desc_size];  
    bool             has_electric;            
    double           rate;
};

istream& from_ascii_file( istream& strm, CampsiteRecord& site );
ostream& operator<<( ostream& strm, const CampsiteRecord& site );

#endif