#ifndef CAMPSITEDB_H
#define CAMPSITEDB_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CampsiteDB {
public:
    CampsiteDB( string filename );

    int get_record_count( );
    int get_current_index( bool write=false );

    Campsite get_next_sequential( );
    Campsite get_at_index( int index );

    void write_next_sequential( const Campsite& site );
    void write_at_index( int index, const Campsite& site );

    void print_record( int index, ostream& strm = cout );
    void list_records( ostream& strm = cout );

    // This object is non-copyable
    CampsiteDB(const CampsiteDB&)            = delete;  
    CampsiteDB& operator=(const CampsiteDB&) = delete;  

private:
    // private methods:
    void _create_file( );
    bool _open_file( );
    // attributes
    string  _filename;
    fstream _file;
};

#endif