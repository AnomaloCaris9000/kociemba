#ifndef CUBE_DEF_HPP
#define CUBE_DEF_HPP

#define NB_EDGES 12
#define NB_CORNERS 8

typedef unsigned char byte_t;

namespace rc { 

enum Face: byte_t
{
    U, D, F, B, L, R // the order is not chosen randomly
};

/// @brief Piece Placement
enum PieceP: byte_t
{
    UF, UB, UL, UR, // U layer
    FL, FR, BL, BR, // E layer
    DF, DB, DL, DR, // D layer

    UFL, UFR, UBL, UBR, // U layer
    DFL, DFR, DBL, DBR  // D layer
};

/// @brief Piece Orientation
enum PieceO: byte_t
{
    GOOD, BAD, BAD0
};

struct Cubie
{
    PieceP p;
    PieceO o;
};

struct Facelet
{
    Face f;
    byte_t i;
    byte_t j;
};

} // namespace rc

#endif