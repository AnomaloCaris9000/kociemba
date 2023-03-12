#ifndef CUBE_DEFS_HPP
#define CUBE_DEFS_HPP


#define NB_STICKERS 56 
#define NB_FACES 6
#define NB_CENTER 6
#define NB_EDGES 12
#define NB_CORNER 8
#define NB_EO 2 // edge are either good or bad
#define NB_CO 3 

namespace rc {


typedef enum e_Face 
{
    F, B, R, L, U, D 
} Face;


typedef enum e_Edge 
{
    UF, UB, UR, UL, // note: there is a natural order 
    BR, FR, BL, FL, 
    DF, DB, DR, DL
} EdgeP;
typedef enum e_EdgeOrientation 
{
    GOOD, BAD
} EdgeO;
const Face edge_face_table[NB_EDGES][NB_EO] =
{
    {U, F},
    {U, B},
    {U, R},
    {U, L},
    {B, R},
    {F, R},
    {B, L},
    {F, L},
    {D, F},
    {D, B},
    {D, R},
    {D, L}
};
#define edge_face(EP, EO) edge_face_table[EP][EO]


typedef enum e_CubeCorner
{
    UFR, ULF, URB, ULB,
    DFR, DFL, DBR, DBL 
} CornerP;
typedef enum e_CornerOrientation
{
    SOLVED, PLUS, MINUS
} CornerO;
const Face corner_face_table[NB_CORNER][NB_CO] =
{
    {U, F, R},
    {U, L, F},
    {U, R, B},
    {U, L, B},
    {D, F, R},
    {D, B, R},
    {D, B, L}
};
#define corner_face(EP, EO) edge_face_table[EP][EO]


typedef enum e_Color: char  
{
    GREEN  = 'g', 
    BLUE   = 'b', 
    RED    = 'r', 
    ORANGE = 'o', 
    WHITE  = 'w', 
    YELLOW = 'y'
} Color;



}

#endif