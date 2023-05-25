#include "coord.hpp"
#include <stdlib.h>

namespace rc {


Coord::Coord()
{
    // TODO:
}

Cubie Coord::operator () (Cubie const c) const
{
    (void)c;
    return {(PieceP)0, (PieceO)0};
}

Coord& Coord::operator *= (Coord const other)
{
    (void)other;
    return *this;
}

Coord operator * (Coord const c0, Coord const c1)
{
    (void)c0;
    (void)c1;
    return (Coord)(*(Coord*)NULL); 
}

} // namespace rc