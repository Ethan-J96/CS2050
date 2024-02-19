#include "CSZNode.h"
#include "CityStateZip.h"
#include <string>

void CSZNode::set_left( CSZNode* new_left ){
    if(left == nullptr){ // check if overwriting data
        left = new_left;
    }
}
void CSZNode::set_right( CSZNode* new_right ){
    if(right == nullptr){ // check if overwriting data
        right = new_right;
    }
}
CityStateZip CSZNode::get_data( ) const{
    return payload;
}
CSZNode* CSZNode::get_left( ) const{
    return left;
}
CSZNode* CSZNode::get_right( ) const{
    return right;
}
void CSZNode::writeNode( std::ostream& fout ) const{
    payload.writeCSZ(fout); //call the citystatezip class write method
}

bool CSZNode::operator<(const CSZNode& op2) const{
    bool result;
    if(payload.getCity().compare( op2.payload.getCity() ) <= 0){
        result = false;
    }
    else if(payload.getCity().compare( op2.payload.getCity() ) > 0){
        result = true;
    }
    return result;
}

std::ostream& operator<<( std::ostream& fout, const CSZNode& n ){
    n.writeNode(fout);
    return fout;
}