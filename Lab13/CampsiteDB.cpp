#include "Campsite.h"
#include "CampsiteDB.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

CampsiteDB::CampsiteDB( string filename ){
    _filename = filename;
    if (!_open_file()){
        _create_file();
        if (!_open_file()){
            throw runtime_error("Unable to create the database.");
        }
    }
}

bool CampsiteDB::_open_file( ){
    _file.open(_filename, ios::in | ios::out | ios::binary);
    _file.seekp(0, ios::end);
    return _file.is_open();
}

void CampsiteDB::_create_file( ){
    _file.open(_filename, ios::out | ios::binary);
    _file.close();
}

int CampsiteDB::get_record_count( ){
    _file.seekg(0, ios::end);
    return _file.tellg() / sizeof(CampsiteRecord);
}

int CampsiteDB::get_current_index( bool write ){
    int index;
    if (write){
        index = _file.tellp() / sizeof(CampsiteRecord);
    }else{
        index = _file.tellg() / sizeof(CampsiteRecord);
    }
    return index;
}

Campsite CampsiteDB::get_next_sequential( ){
    CampsiteRecord record;
    _file.read(reinterpret_cast<char*>(&record), sizeof(record));
    return Campsite(record);
}

Campsite CampsiteDB::get_at_index( int index ){
    _file.clear();
    _file.seekg(index * sizeof(CampsiteRecord), ios::beg);
    return get_next_sequential();
}

void CampsiteDB::write_next_sequential( const Campsite& site ){
    CampsiteRecord record = site.get_record();
    _file.write(reinterpret_cast<char*>(&record), sizeof(record));
}

void CampsiteDB::write_at_index( int index, const Campsite& site ){
    _file.clear();
    _file.seekp(index * sizeof(CampsiteRecord), ios::beg);
    write_next_sequential(site);
}

void CampsiteDB::list_records( ostream& strm ){
    _file.clear();
    _file.seekg(0, ios::beg);
    while (_file.good()){
        Campsite site = get_next_sequential();
        if (_file.good()){
            strm << site << endl;
        }
        strm << endl;
    }
    _file.clear();
    _file.seekg(0, ios::beg);
}