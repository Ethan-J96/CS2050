#include "movie.h"

Movie( std::istream& infile ){  /// construct given an input stream
    std::string data;
    char delimiter;
    std::getline (infile, data, '|');
    title = data;
    infile >> year;
    infile >> delimiter;
    std::getline(infile, director, '|');
    std::getline(infile, rating);

}
void write( std::ostream& outfile ) const{
    outfile << title << 
    "(" << year << ") " << 
    rating << " - " << 
    director << std::endl;
}
std::ostream& operator<<( std::ostream& outfile, const Movie& movie ){
    movie.write(outfile);
    return outfile;
}