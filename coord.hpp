#ifndef CORD_HPP
#define CORD_HPP

#include "cube-defs.hpp"

namespace rc {


/**
 * @brief Representation of an element in the extended Rubik's Cube group.
 * @note Optimized for compositions. 
 */
struct Coord
{
    // unprotected data members
    // TODO: optimize
    byte_t m_edgeP[NB_EDGES];
    byte_t m_cornerP[NB_CORNERS];
    byte_t m_edgeO[NB_CORNERS];
    byte_t m_cornerO[NB_CORNERS];

    /**
     * @brief Construct a new Coord object which is Identity by default.
     */
    Coord();

    /**
     * @brief Look a the Cubie living in a given place
     * @param c A Cubie place in the cube
     * @return Actual Cubie living in this place
     */
    Cubie operator () (Cubie const c) const;

    /**
     * @brief Compose the current Coord with another one
     * @param other The other Coord
     * @return The current instence. 
     */
    Coord& operator *= (Coord const other);
};

/**
 * @brief Compose two Coords.
 * @param c0 
 * @param c1 
 * @return The composition of c0 and c1. 
 */
Coord operator * (Coord const c0, Coord const c1);

} // namespace rc

#endif