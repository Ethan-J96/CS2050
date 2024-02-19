#ifndef MOVIE_H_
#define MOVIE_H_
#include <string>
#include <iostream>

struct Movie {
    std::string title;              /// Movie title
    unsigned short year;            /// Movie release year
    std::string director;           /// Director's name
    std::string rating;             /// Movie audience rating

    Movie( std::istream& infile );  /// construct given an input stream
    void write( std::ostream& outfile ) const;
};
std::ostream& operator<<( std::ostream& outfile, const Movie& movie );

#endif