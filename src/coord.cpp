#include "coord.hpp"
#include <stdlib.h>
#include <assert.h>

namespace rc {


Coord::Coord()
{
    for(byte_t i = 0; i < NB_EDGES; ++i)
    {
        if(i < NB_CORNERS) {
            cornerP[i] = i;
            cornerO[i] = 0;  
        }
        edgeP[i] = i;
        edgeO[i] = 0;
    }
}

EdgeO Coord::eo(EdgeP ep) const {
    return (EdgeO)edgeO[ep]; 
}

CornerO Coord::co(CornerP cp) const {
    return (CornerO)edgeO[cp]; 
}

EdgeP Coord::ep(EdgeP ep) const {
    return (EdgeP)edgeP[ep]; 
}

CornerP Coord::cp(CornerP ep) const {
    return (CornerP)edgeO[ep]; 
}

Cubie Coord::at(Cubie const& c) const 
{
    if(c.type() == EDGE) {
        return Cubie(c.type(), edgeP[c.placement()], c.orientation()+edgeO[c.placement()]);
    }
    else if(c.type() == CORNER) {
        return Cubie(c.type(), cornerP[c.placement()], c.orientation()+cornerO[c.placement()]);
    } else { // En cas de centre, vous êtes invité à ne rien faire
        return c;
    }
}

Coord& Coord::operator *= (Coord const other)
{
    for(int i = 0; i < NB_EDGES; ++i)
    {
        if(i < NB_CORNERS) {
            cornerP[i] = other.cornerP[cornerP[i]];
            cornerO[i] += other.cornerO[cornerP[i]];
        }
        edgeP[i] = other.edgeP[edgeP[i]];
        edgeO[i] += other.edgeO[edgeP[i]];
    }
    return *this;
}

Coord operator * (Coord const c0, Coord const c1)
{
    Coord result = c0;
    result *= c1;
    return result; 
}

} // namespace rc