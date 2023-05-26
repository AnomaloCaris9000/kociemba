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
    byte_t edgeP[NB_EDGES];
    byte_t cornerP[NB_CORNERS];
    byte_t edgeO[NB_CORNERS];
    byte_t cornerO[NB_CORNERS];

    /**
     * @brief Construct a new Coord object which is Identity by default.
     */
    Coord();

    // TODO: maybe make inline
    /// @brief Edge Orientation getter 
    EdgeO eo(EdgeP ep) const;
    /// @brief Corner Orientation getter 
    CornerO co(CornerP cp) const;
    /// @brief Edge Placement getter 
    EdgeP ep(EdgeP ep) const;
    /// @brief Edge Placement getter 
    CornerP cp(CornerP cp) const;

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