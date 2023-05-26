#ifndef CUBE_DEF_HPP
#define CUBE_DEF_HPP

#define NB_EDGES 12
#define NB_CORNERS 8
#define NB_FACE 6

typedef unsigned char byte_t;

namespace rc { 

enum Face: byte_t
{
    U, D, F, B, L, R // the order is not chosen randomly
};

enum Color: const char
{
    WHITE = 'w',
    GREEN = 'g',
    BLUE = 'b',
    YELLOW = 'y',
    ORANGE = 'o',
    RED = 'r'
};

/// @brief Piece Placement
enum EdgeP: byte_t
{
    UF, UB, UL, UR, // U layer
    FL, FR, BL, BR, // E layer
    DF, DB, DL, DR, // D layer
};


enum CornerP: byte_t
{
    UFL, UFR, UBL, UBR, // U layer
    DFL, DFR, DBL, DBR  // D layer
};

/// @brief Piece Orientation
enum EdgeO: byte_t
{
    GOOD, BAD
};

enum CornerO: byte_t
{
    OK, PLUS, MINUS
};

enum PieceType: byte_t
{
    CORNER, EDGE, CENTER
};

} // namespace rc

#endif