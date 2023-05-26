#ifndef FACELET_HPP
#define FACELET_HPP

#include "cube-defs.hpp"
#include "cubie.hpp"

namespace rc {

struct Facelet {
    Face face;
    byte_t i, j;

    Facelet(Face f, byte_t p_i, byte_t p_j):
        face(f), i(p_i), j(p_j)
    {}

    Facelet(Cubie const);
    Cubie toCubie() const
    ;
};


/// @brief Rubik's Cube describe as an array of facelet. 
class FaceletLevel
{
    private:
        CubieLevel &m_cubies; 
    public:
        FaceletLevel(CubieLevel &);

        /// @brief Return the actual facelet at this place. 
        Facelet at(Facelet) const; 
};

} // namespace rc 


#endif 