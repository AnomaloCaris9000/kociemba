#include "inc/coord.hpp"
#include <array>

namespace rc 
{


Coord::Coord(EpType ep, EoType eo, CpType cp, CoType co):
    m_ep(ep),
    m_eo(eo), 
    m_cp(cp),
    m_co(co) 
{}

inline CornerP  Coord::getCP(CornerP const corner) const
{
    return m_cp[corner];
}

inline EdgeP    Coord::getEP(EdgeP   const edge)   const
{
    return m_ep[edge];
}

inline CornerO  Coord::getCO(CornerP const corner) const
{
    return (CornerO)(m_co[corner]%NB_CO);
}

inline EdgeO    Coord::getEO(EdgeP   const edge)   const
{
    return (EdgeO)(m_eo[edge]%NB_EO);
}

Coord& Coord::operator *= (Coord const& other)
{
    for (size_t i = 0; i < NB_EDGES; i++)
    {
        if(i < NB_CORNER)
        {
            this->m_cp[other.m_cp[i]] = (CornerP)i;
            this->m_co[i] += other.m_co[i];
        }
        this->m_cp[other.m_cp[i]] = (CornerP)i;
        this->m_eo[i] += other.m_eo[i];
    }
    
}


}
