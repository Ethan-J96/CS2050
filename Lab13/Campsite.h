#ifndef CAMPSITE_H
#define CAMPSITE_H
#include "CampsiteRecord.h"
#include <iostream>
#include <string>
using namespace std;

class Campsite {
public:
    Campsite( ) = default;
    Campsite( int number, string description, bool has_electric, double rate );
    Campsite( const CampsiteRecord& r );

    CampsiteRecord get_record() const;
    int            get_number( ) const;
    string    get_description( ) const;
    bool           has_electric( ) const;
    bool           get_rate( ) const;

    void set_number( int number );
    void set_description( string description );
    void set_has_electric( bool flag );
    void set_rate( double rate );

    ostream& write(ostream& strm) const;
    istream& from_ascii_file(istream& strm);
    
private:
    CampsiteRecord _rec;
};

ostream& operator<< (ostream& strm, const Campsite& site);

#endif