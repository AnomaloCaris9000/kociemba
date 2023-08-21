#include "coord.hpp"
#include <stdlib.h>
#include <assert.h>

namespace rc {


Coord::Coord()
{
    for(byte_t i = 0; i < NB_EDGES; i++)
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
    return (EdgeO)(edgeO[ep]%2); 
}

CornerO Coord::co(CornerP cp) const {
    return (CornerO)(cornerO[cp]%3); 
}

EdgeP Coord::ep(EdgeP ep) const {
    return (EdgeP)edgeP[ep]; 
}

CornerP Coord::cp(CornerP cp) const {
    return (CornerP)cornerP[cp]; 
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
    for(int i = 0; i < NB_EDGES; i++)
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

void cycle4EC(Coord &coord, std::array<EdgeP, 4> ep, std::array<CornerP, 4> cp, std::array<int, 4> co, bool switchEdges)
{
    int next;

    for(int i = 0; i < 4; i++) {
        if(i < 3)
        {
            std::swap(coord.edgeP[ep[i]], coord.edgeP[ep[i+1]]); 
            std::swap(coord.cornerP[cp[i]], coord.cornerP[cp[i+1]]); 
        }
        if(switchEdges) coord.edgeO[ep[i]] = 1;
        coord.cornerO[cp[i]] = co[i];
    }
} 

template <>
Coord Coord::make<F>()
{
    Coord c = Coord(); 
    cycle4EC(c, {FL, DF, FR, UF}, {DFL, DFR, UFR, UFL}, {2, 1, 2, 1}, true);
    return c; 
}

template <>
Coord Coord::make<R>()
{
    Coord c = Coord(); 
    cycle4EC(c, {DR, BR, UR, FR}, {DBR, UBR, UFR, DFR}, {1, 2, 1, 2}, false);
    return c;
}

template <>
Coord Coord::make<U>()
{
    Coord c = Coord(); 
    cycle4EC(c, {UB, UL, UF, UR}, {UBL, UFL, UFR, UBR}, {0, 0, 0, 0}, false);
    return c;
}
template <>
Coord Coord::make<D>()
{
    Coord c = Coord(); ;
    cycle4EC(c, {DB, DR, DF, DL}, {DFL, DBL, DBR, DFR}, {0, 0, 0, 0}, false);
    return c;
}
template <>
Coord Coord::make<B>()
{
    Coord c = Coord(); ;
    cycle4EC(c, {UB, BR, DB, BL}, {UBL, UBR, DBR, DBL}, {2, 1, 2, 1}, true);
    return c;
}
template <>
Coord Coord::make<L>()
{
    Coord c;
    cycle4EC(c, {UL, BL, DL, FL}, {UFL, UBL, DBL, DFL}, {2, 1, 2, 1}, false);
    return c;
}


} // namespace rc