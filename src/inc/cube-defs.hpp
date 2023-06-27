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

/**
 * @brief Represent a facelet. A facelet is located by its face and its coordinate on it.
 * @note There is 6*3*3=56 facelet.  
 */
class Facelet {

    public:

        /**
         * @brief Construct a new Facelet object
         * @param f The face.
         * @param i The row.
         * @param j The column.
         */
        Facelet(Face f, byte_t i, byte_t j);

       /**
        * @brief Row getter 
        * @return 0, 1 or 2 
        */
       byte_t row() const; 

       /**
        * @brief Column getter 
        * @return 0, 1 or 2
        */
       byte_t col() const; 

       /**
        * @brief Face getter
        * @return F, R, U, B, L or D 
        */
       Face face() const;  
};


class Cubie {
    public:
        /**
         * @brief Construct a new Cubie object
         * 
         * @param type Edge, corner or center 
         * @param p Placement
         * @param o Orientation.
         */
        Cubie(PieceType type, byte_t p, byte_t o);

        /**
         * @brief Make a facelet into a cubie. 
         * @param f 
         */
        Cubie(Facelet f);

        /**
         * @note Works only if the facelet is not a center. 
         * @return Facelet 
         */
        operator Facelet() const; 

        /**
         * @brief Piece's type getter
         * @return Edge, Corner or center
         */
        PieceType type() const;

        /**
         * @brief Orientation getter.
         * @return 0, 1 or 2
         * @note type = Edge => orientation in 0, 1 
         * @note type = Corner => orientation in 0, 1, 2
         * @note type = Edge => orientation in 0, 1 
         */
        byte_t orientation() const;

        /**
         * @brief Placement getter.
         * @return Number in 0..23
         * @note If type = center, then placement is the correspounding facelement.face. 
         */
        byte_t placement() const;
};

} // namespace rc

#endif