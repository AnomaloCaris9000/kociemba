/**
 * @file coord.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CORD_HPP
#define CORD_HPP

#include "scramble.hpp"

namespace rc {


/**
 * @brief Representation of an element in the extended Rubik's Cube group.
 * @note Optimized for compositions. 
 */
struct Coord
{
    // unprotected data members
    std::array<byte_t, NB_EDGES> edgeP;
    std::array<byte_t, NB_CORNERS> cornerP;
    std::array<byte_t, NB_EDGES> edgeO;
    std::array<byte_t, NB_CORNERS> cornerO;

    /**
     * @brief Construct a new Coord object which is Identity by default.
     */
    Coord();

    /// @brief Edge Orientation getter 
    EdgeO eo(EdgeP ep) const;
    /// @brief Corner Orientation getter 
    CornerO co(CornerP cp) const;
    /// @brief Edge Placement getter 
    EdgeP ep(EdgeP ep) const;
    /// @brief Edge Placement getter 
    CornerP cp(CornerP cp) const;

    Cubie at(Cubie const&) const; 

    /**
     * @brief Compose the current Coord with another one
     * @param other The other Coord
     * @return The current instence. 
     */
    Coord& operator *= (Coord const& other);

    template <Scramble::Move M> static Coord make(); 
};


/**
 * @brief Compose two Coords.
 * @param c0 
 * @param c1 
 * @return The composition of c0 and c1. 
 */
Coord operator * (Coord const& c0, Coord const& c1);

} // namespace rc

#endif