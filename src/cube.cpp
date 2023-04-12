#include "inc/cube.hpp"


using namespace rc;

 Cube::Cube()
 {

 }


 Color Cube::colorAt(Face, char, char) const
 {
    return RED;
 }

 Cube& Cube::turn(Face)
 {
    return *this; 
 }


bool Cube::isSolved() const 
{
    return false;
}



std::ostream& operator << (std::ostream &flux, const rc::Cube& cube)
{
    return flux;
}