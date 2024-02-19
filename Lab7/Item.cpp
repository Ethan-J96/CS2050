#include "Item.h"

std::ostream& Item::write(std::ostream& fout) const {
    fout << std::setiosflags(std::ios::left) << std::setw(30) << name << magic << std::resetiosflags(std::ios::left);
    return fout;
}

std::ostream& operator<<(std::ostream& fout, const Item& item) {
    return item.write(fout);
} 
