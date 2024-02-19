#include "Campsite.h"
#include <cstring>
using namespace std;

Campsite::Campsite( int number, string description, 
                    bool has_electric, double rate )
    : _rec{number, description.c_str( ), has_electric, rate} {}

Campsite::Campsite( const CampsiteRecord& r ) 
    : _rec{r} {}
    
CampsiteRecord Campsite::get_record() const {
    return _rec;
}
int Campsite::get_number( ) const {
    return _rec.number;
}
string Campsite::get_description( ) const {
    return string{_rec.description};
}
bool Campsite::has_electric( ) const {
    return _rec.has_electric;
}
bool Campsite::get_rate( ) const {
    return _rec.rate;
}

void Campsite::set_number( int number ) {
    _rec.number = number;
}
void Campsite::set_description( string description ) {
    _rec.description[CampsiteRecord::desc_size - 1] = '\0';
    strncpy( _rec.description, 
             description.c_str( ),
             CampsiteRecord::desc_size - 1 );
}
void Campsite::set_has_electric( bool flag ) {
    _rec.has_electric = flag;
}
void Campsite::set_rate( double rate ) {
    _rec.rate = rate;
}

istream& Campsite::from_ascii_file(istream& strm){
    return ::from_ascii_file(strm, _rec);   
}

ostream& Campsite::write(ostream& strm) const{
    return strm << _rec;
}

ostream& operator<< (ostream& strm, const Campsite& site){
    return site.write(strm);
}

