#ifndef COORD_HPP
#define COORD_HPP


#include "cube-defs.hpp"


namespace rc 
{

class Coord 
{

    public:
        using EpType = std::array<EdgeP, NB_EDGES>;
        using EoType = std::array<int, NB_EDGES>;
        using CpType = std::array<CornerP, NB_CORNER>;
        using CoType = std::array<int, NB_CORNER>;

    private:
        EpType m_ep;
        CpType m_cp; 
        EoType m_eo;
        CoType m_co;
        Coord(EpType ep, EoType eo, CpType cp, CoType co);

    public:
        Coord(EpType ep, EoType eo, CpType cp, CoType co);

        CornerP  getCP(CornerP const corner) const;
        EdgeP    getEP(EdgeP   const edge)   const;
        CornerO  getCO(CornerP const corner) const;
        EdgeO    getEO(EdgeP   const edge)   const;
        Coord&  operator *= (Coord const& other);

};

}

#endif 