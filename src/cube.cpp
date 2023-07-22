#include "cube.hpp"
#include <stdio.h>
#include <string.h>


namespace rc {

Cube::Cube()
{
    // scheme def
    m_scheme[F] = GREEN; 
    m_scheme[R] = RED; 
    m_scheme[U] = WHITE; 
    m_scheme[B] = BLUE; 
    m_scheme[L] = ORANGE; 
    m_scheme[D] = YELLOW;

    // move table def
}

Cube& Cube::turn(Face f)
{
    m_coord *= m_coordTable[f];
    return *this;
}

Color Cube::at(Face f, byte_t i, byte_t j) const
{
    // f, i, j -> Facelet
    // Facelet -> Cubie
    // Cubie*Coord -> Cubie'
    // Cubie' -> Facelet'
    // Facelet' -> face 
    // face -> color 
    return m_scheme[((Facelet)m_coord.at(Cubie(Facelet(f, i, j)))).face()]; 
}

bool Cube::isSolved() const 
{
    // TODO 
    return false; 
}

} // namespace rc

std::ostream& operator << (std::ostream &flux, rc::Cube const& cube)
{
    static char format[] = 
". . . . . . %c %c %c . . .\n\
. . . . . . %c %c %c . . .\n\
. . . . . . %c %c %c . . .\n\
%c %c %c %c %c %c %c %c %c %c %c %c\n\
%c %c %c %c %c %c %c %c %c %c %c %c\n\
%c %c %c %c %c %c %c %c %c %c %c %c\n\
. . . . . . %c %c %c . . .\n\
. . . . . . %c %c %c . . .\n\
. . . . . . %c %c %c . . .\n";
    snprintf(format, 271, format, 
        cube.at(rc::U, 0, 0), cube.at(rc::U, 0, 1), cube.at(rc::U, 0, 2), // U face
        cube.at(rc::U, 1, 0), cube.at(rc::U, 1, 1), cube.at(rc::U, 1, 2),
        cube.at(rc::U, 2, 0), cube.at(rc::U, 2, 1), cube.at(rc::U, 2, 2), 
        cube.at(rc::B, 0, 0), cube.at(rc::B, 0, 1), cube.at(rc::B, 0, 2), // BLFR 1
        cube.at(rc::L, 0, 0), cube.at(rc::L, 0, 1), cube.at(rc::L, 0, 2), 
        cube.at(rc::F, 0, 0), cube.at(rc::F, 0, 1), cube.at(rc::F, 0, 2),
        cube.at(rc::R, 0, 0), cube.at(rc::R, 0, 1), cube.at(rc::R, 0, 2),
        cube.at(rc::B, 1, 0), cube.at(rc::B, 1, 1), cube.at(rc::B, 1, 2), // BLFR 2
        cube.at(rc::L, 1, 0), cube.at(rc::L, 1, 1), cube.at(rc::L, 1, 2), 
        cube.at(rc::F, 1, 0), cube.at(rc::F, 1, 1), cube.at(rc::F, 1, 2),
        cube.at(rc::R, 1, 0), cube.at(rc::R, 1, 1), cube.at(rc::R, 1, 2),
        cube.at(rc::B, 2, 0), cube.at(rc::B, 2, 1), cube.at(rc::B, 2, 2), // BLFR 3
        cube.at(rc::L, 2, 0), cube.at(rc::L, 2, 1), cube.at(rc::L, 2, 2), 
        cube.at(rc::F, 2, 0), cube.at(rc::F, 2, 1), cube.at(rc::F, 2, 2),
        cube.at(rc::R, 2, 0), cube.at(rc::R, 2, 1), cube.at(rc::R, 2, 2),
        cube.at(rc::D, 0, 0), cube.at(rc::D, 0, 1), cube.at(rc::D, 0, 2), // D face
        cube.at(rc::D, 1, 0), cube.at(rc::D, 1, 1), cube.at(rc::D, 1, 2),
        cube.at(rc::D, 2, 0), cube.at(rc::D, 2, 1), cube.at(rc::D, 2, 2)
    );
    flux << format; 
    return flux; 
}