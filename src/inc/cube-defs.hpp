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

    private:
        Face m_face;
        byte_t m_row;
        byte_t m_col;

    public:

        /**
         * @brief Construct a new Facelet object
         * @param f The face.
         * @param i The row.
         * @param j The column.
         */
        Facelet(Face f, byte_t i, byte_t j):
            m_face(f), m_row(i%3), m_col(j%3)
        {}

        Facelet() // default constructor
        : m_face(U), m_row(0), m_col(0) 
        {}

       /**
        * @brief Row getter 
        * @return 0, 1 or 2 
        */
       inline byte_t row() const {return m_row;}

       /**
        * @brief Column getter 
        * @return 0, 1 or 2
        */
       inline byte_t col() const {return m_col;}

       /**
        * @brief Face getter
        * @return F, R, U, B, L or D 
        */
       inline Face face() const {return m_face;}
};


class Cubie {

    private:
        PieceType m_type;
        byte_t m_placement;
        byte_t m_orientation;

    public:
        /**
         * @brief Construct a new Cubie object
         * 
         * @param type Edge, corner or center 
         * @param p Placement
         * @param o Orientation.
         */
        Cubie(PieceType type, byte_t p, byte_t o):
            m_type(type), 
            m_placement(p%(type==EDGE?NB_EDGES:NB_CORNERS)), 
            m_orientation(o%(type==EDGE?2:3))
        {}

        Cubie(): // default constructor
            m_type(CENTER), m_placement(0), m_orientation(0)
        {}

        /**
         * @brief Make a facelet into a cubie. 
         * @param f A facelet. 
         */
        Cubie(Facelet const &f);

        /**
         * @note Works only if the facelet is not a center. 
         * @return Facelet 
         */
        operator Facelet() const; 

        /**
         * @brief Piece's type getter
         * @return Edge, Corner or center
         */
        inline PieceType type() const {return m_type;}

        /**
         * @brief Orientation getter.
         * @return 0, 1 or 2
         * @note type = Edge => orientation in 0, 1 
         * @note type = Corner => orientation in 0, 1, 2
         * @note type = Edge => orientation in 0, 1 
         */
        inline byte_t orientation() const {return m_orientation;}

        /**
         * @brief Placement getter.
         * @return Number in 0..23
         * @note If type = center, then placement is the correspounding facelement.face. 
         */
        inline byte_t placement() const {return m_placement;}
};

} // namespace rc

#endif