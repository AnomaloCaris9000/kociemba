#include "cube.hpp"


namespace rc {

Cube::Cube()
{
    // TODO
}

Cube& Cube::turn(Face f)
{
    (void)f;
    // TODO 
    return *this;
}

bool Cube::isSolved() const 
{
    // TODO 
    return false; 
}

} // namespace rc

std::ostream& operator << (std::ostream &flux, rc::Cube const& cube)
{
    (void)flux; (void)cube;
    // TODO
    return flux; 
}