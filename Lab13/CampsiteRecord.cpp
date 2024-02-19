#include "CampsiteRecord.h"
#include <cstring>
#include <cctype>
#include <iomanip>
#include <iostream>
using namespace std;

CampsiteRecord::CampsiteRecord() {
    memset(this, 0, sizeof(CampsiteRecord));
}

CampsiteRecord::CampsiteRecord(int number, const char description[], bool has_electric, double rate) {
    memset(this, 0, sizeof(CampsiteRecord));
    this->number = number;
    this->has_electric = has_electric;
    this->rate = rate;
    strcpy(this->description, description);
}

istream& from_ascii_file( istream& strm, CampsiteRecord& site ) {
    char delim;
    char buffer[6]; 
    strm >> site.number >> delim;
    strm.getline( site.description, site.desc_size, '|' );
    strm.getline( buffer, 6, '|' );
    site.has_electric = tolower( buffer[0] ) == 't'; 
    strm >> site.rate;
    return strm;
}

ostream& operator<<( ostream& strm, const CampsiteRecord& site ) {
    strm << site.number      << ' ' << ( site.has_electric ? "[E]" : "[ ]" ) 
         << ' ' << site.description << ' '
         << fixed << setprecision( 2 ) << "\t($" << site.rate << ")"
         << resetiosflags( ios::fixed | ios::showpoint );
    return strm;
}