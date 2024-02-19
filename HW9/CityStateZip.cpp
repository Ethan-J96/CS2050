#include "CityStateZip.h"
void CityStateZip::writeCSZ(std::ostream& fout) const {
    fout << city << ", " << state << ", " << zip << std::endl;
}