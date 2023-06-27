#include "cube-defs.hpp"

using namespace rc;


/// @brief Singleton class to convert between Facelet and Cubie.
typedef class Converter 
{
    private:
        static Converter s_instance;

        Cubie m_cubieTable[56];
        Facelet m_faceletTable[56];

        void loadEntry(Cubie c, Facelet f)
        {
            m_cubieTable[faceletCode(f)] = c;
            m_faceletTable[cubieCode(c)] = f;
        }

        Converter() {
            loadEntry(Cubie(EDGE, UB, GOOD), Facelet(U, 0, 1));
            loadEntry(Cubie(EDGE, UB, BAD), Facelet(B, 0, 1));
            loadEntry(Cubie(EDGE, UR, GOOD), Facelet(U, 1, 2));
            loadEntry(Cubie(EDGE, UR, BAD), Facelet(R, 0, 1));
            loadEntry(Cubie(EDGE, UF, GOOD), Facelet(U, 2, 1));
            loadEntry(Cubie(EDGE, UF, BAD), Facelet(F, 0, 1));
            loadEntry(Cubie(EDGE, UL, GOOD), Facelet(U, 1, 0));
            loadEntry(Cubie(EDGE, UL, BAD), Facelet(L, 0, 1));
            loadEntry(Cubie(EDGE, DF, GOOD), Facelet(D, 0, 1));
            loadEntry(Cubie(EDGE, DF, BAD), Facelet(F, 2, 1));
            loadEntry(Cubie(EDGE, DR, GOOD), Facelet(D, 1, 2));
            loadEntry(Cubie(EDGE, DR, BAD), Facelet(R, 2, 1));
            loadEntry(Cubie(EDGE, DB, GOOD), Facelet(D, 2, 1));
            loadEntry(Cubie(EDGE, DB, BAD), Facelet(B, 2, 1));
            loadEntry(Cubie(EDGE, DL, GOOD), Facelet(D, 1, 0));
            loadEntry(Cubie(EDGE, DL, BAD), Facelet(L, 2, 1));
            loadEntry(Cubie(EDGE, FR, GOOD), Facelet(F, 1, 2));
            loadEntry(Cubie(EDGE, FR, BAD), Facelet(R, 1, 0));
            loadEntry(Cubie(EDGE, FL, GOOD), Facelet(F, 1, 0));
            loadEntry(Cubie(EDGE, FL, BAD), Facelet(L, 1, 2));
            loadEntry(Cubie(EDGE, BR, GOOD), Facelet(B, 1, 2));
            loadEntry(Cubie(EDGE, BR, BAD), Facelet(R, 1, 2));
            loadEntry(Cubie(EDGE, BL, GOOD), Facelet(B, 1, 0));
            loadEntry(Cubie(EDGE, BL, BAD), Facelet(L, 1, 0));
            loadEntry(Cubie(CORNER, UFR, OK), Facelet(U, 2, 2));
            loadEntry(Cubie(CORNER, UFR, PLUS), Facelet(R, 0, 0));
            loadEntry(Cubie(CORNER, UFR, MINUS), Facelet(F, 0, 2));
            loadEntry(Cubie(CORNER, UFL, OK), Facelet(U, 2, 0));
            loadEntry(Cubie(CORNER, UFL, PLUS), Facelet(F, 0, 0));
            loadEntry(Cubie(CORNER, UFL, MINUS), Facelet(L, 0, 2));
            loadEntry(Cubie(CORNER, UBL, OK), Facelet(U, 0, 0));
            loadEntry(Cubie(CORNER, UBL, PLUS), Facelet(B, 0, 0));
            loadEntry(Cubie(CORNER, UBL, MINUS), Facelet(L, 0, 0));
            loadEntry(Cubie(CORNER, UBR, OK), Facelet(U, 0, 2));
            loadEntry(Cubie(CORNER, UBR, PLUS), Facelet(R, 0, 2));
            loadEntry(Cubie(CORNER, UBR, MINUS), Facelet(B, 0, 2));
            loadEntry(Cubie(CORNER, DFR, OK), Facelet(D, 2, 2));
            loadEntry(Cubie(CORNER, DFR, PLUS), Facelet(F, 2, 0));
            loadEntry(Cubie(CORNER, DFR, MINUS), Facelet(R, 2, 2));
            loadEntry(Cubie(CORNER, DFL, OK), Facelet(D, 2, 0));
            loadEntry(Cubie(CORNER, DFL, PLUS), Facelet(L, 2, 2));
            loadEntry(Cubie(CORNER, DFL, MINUS), Facelet(F, 2, 2));
            loadEntry(Cubie(CORNER, DBL, OK), Facelet(D, 0, 0));
            loadEntry(Cubie(CORNER, DBL, PLUS), Facelet(B, 2, 0));
            loadEntry(Cubie(CORNER, DBL, MINUS), Facelet(L, 2, 0));
            loadEntry(Cubie(CORNER, DBR, OK), Facelet(D, 0, 2));
            loadEntry(Cubie(CORNER, DBR, PLUS), Facelet(R, 2, 0));
            loadEntry(Cubie(CORNER, DBR, MINUS), Facelet(B, 2, 2));
            loadEntry(Cubie(CENTER, U, 0), Facelet(U, 1, 1));
            loadEntry(Cubie(CENTER, D, 0), Facelet(D, 1, 1));
            loadEntry(Cubie(CENTER, F, 0), Facelet(F, 1, 1));
            loadEntry(Cubie(CENTER, B, 0), Facelet(B, 1, 1));
            loadEntry(Cubie(CENTER, L, 0), Facelet(L, 1, 1));
            loadEntry(Cubie(CENTER, R, 0), Facelet(R, 1, 1));
        }

        /// @brief Cubie -> Number beween 0 and 47 if this not a center.
        int cubieCode(Cubie const& c) const
        {
            if(c.type() == CENTER) // Center cases 
            {
                return 48 + c.placement();
            }
            else if(c.type() == EDGE) // Edge cases 
            {
                return 24 + c.placement() * 2 + c.orientation();
            }
            else // Corner cases 
            {
                return c.placement() * 3 + c.orientation();
            }
        }

        /// @brief Facelet -> Number beween 0 and 47 if this not a center. 
        int faceletCode(Facelet const& f) const
        {
            if(f.col() == 1 && f.row() == 1) // Center cases 
            {
                return 48 + f.face();
            }
            else if(f.col() == 1 || f.row() == 1) // Edge cases 
            {
                return 24 + f.face() * 12 + f.col() * 3 + f.row();
            }
            else // Corner cases 
            {
                return f.face() * 8 + f.col() * 2 + f.row();
            }
        }
    public:

        /// @brief Singleton instance getter
        static Converter& val() { return s_instance; }

        static Cubie &toCubie(Facelet const& f)
        {
            return val().m_cubieTable[val().faceletCode(f)];
        }

        static Facelet &toFacelet(Cubie const& c)
        {
            return val().m_faceletTable[val().cubieCode(c)];
        }
} conv; 

// Singleton instance initialization
Converter Converter::s_instance;


Cubie::Cubie(Facelet const &f)
{
    *this = conv::toCubie(f);
}

Cubie::operator Facelet() const 
{
    return conv::toFacelet(*this); 
}