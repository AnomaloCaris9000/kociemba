#include "cube-defs.hpp"

//#define DEBUG

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

        Converter() { // merci wikipedia
            loadEntry(Cubie(CENTER, U, 0), Facelet(U, 1, 1));
            loadEntry(Cubie(CENTER, D, 0), Facelet(D, 1, 1));
            loadEntry(Cubie(CENTER, F, 0), Facelet(F, 1, 1));
            loadEntry(Cubie(CENTER, B, 0), Facelet(B, 1, 1));
            loadEntry(Cubie(CENTER, L, 0), Facelet(L, 1, 1));
            loadEntry(Cubie(CENTER, R, 0), Facelet(R, 1, 1));

            loadEntry(Cubie(EDGE, UB, GOOD), Facelet(U, 1, 0));
            loadEntry(Cubie(EDGE, UB, BAD), Facelet(B, 1, 0));

            loadEntry(Cubie(EDGE, UR, GOOD), Facelet(U, 2, 1));
            loadEntry(Cubie(EDGE, UR, BAD), Facelet(R, 1, 0));

            loadEntry(Cubie(EDGE, UF, GOOD), Facelet(U, 1, 2));
            loadEntry(Cubie(EDGE, UF, BAD), Facelet(F, 1, 0));

            loadEntry(Cubie(EDGE, UL, GOOD), Facelet(U, 0, 1));
            loadEntry(Cubie(EDGE, UL, BAD), Facelet(L, 1, 0));

            loadEntry(Cubie(EDGE, DF, GOOD), Facelet(D, 1, 0));
            loadEntry(Cubie(EDGE, DF, BAD), Facelet(F, 1, 2));

            loadEntry(Cubie(EDGE, DR, GOOD), Facelet(D, 2, 1));
            loadEntry(Cubie(EDGE, DR, BAD), Facelet(R, 1, 2));

            loadEntry(Cubie(EDGE, DB, GOOD), Facelet(D, 1, 2));
            loadEntry(Cubie(EDGE, DB, BAD), Facelet(B, 1, 2));

            loadEntry(Cubie(EDGE, DL, GOOD), Facelet(D, 0, 1));
            loadEntry(Cubie(EDGE, DL, BAD), Facelet(L, 1, 2));

            loadEntry(Cubie(EDGE, FR, GOOD), Facelet(F, 2, 1));
            loadEntry(Cubie(EDGE, FR, BAD), Facelet(R, 0, 1));

            loadEntry(Cubie(EDGE, FL, GOOD), Facelet(F, 0, 1));
            loadEntry(Cubie(EDGE, FL, BAD), Facelet(L, 2, 1));

            loadEntry(Cubie(EDGE, BR, GOOD), Facelet(B, 0, 1));
            loadEntry(Cubie(EDGE, BR, BAD), Facelet(R, 2, 1));

            loadEntry(Cubie(EDGE, BL, GOOD), Facelet(B, 2, 1));
            loadEntry(Cubie(EDGE, BL, BAD), Facelet(L, 0, 1));

            loadEntry(Cubie(CORNER, UFR, PLUS), Facelet(U, 2, 2));
            loadEntry(Cubie(CORNER, UFR, OK), Facelet(R, 0, 0));
            loadEntry(Cubie(CORNER, UFR, MINUS), Facelet(F, 2, 0));

            loadEntry(Cubie(CORNER, UFL, PLUS), Facelet(U, 0, 2));
            loadEntry(Cubie(CORNER, UFL, OK), Facelet(F, 0, 0)); 
            loadEntry(Cubie(CORNER, UFL, MINUS), Facelet(L, 2, 0));

            loadEntry(Cubie(CORNER, UBL, PLUS), Facelet(U, 0, 0));
            loadEntry(Cubie(CORNER, UBL, OK), Facelet(L, 0, 0));
            loadEntry(Cubie(CORNER, UBL, MINUS), Facelet(B, 2, 0));

            loadEntry(Cubie(CORNER, UBR, PLUS), Facelet(U, 2, 0));
            loadEntry(Cubie(CORNER, UBR, OK), Facelet(B, 0, 0));
            loadEntry(Cubie(CORNER, UBR, MINUS), Facelet(R, 2, 0));

            loadEntry(Cubie(CORNER, DFR, PLUS), Facelet(D, 2, 0));
            loadEntry(Cubie(CORNER, DFR, OK), Facelet(F, 2, 2));
            loadEntry(Cubie(CORNER, DFR, MINUS), Facelet(R, 0, 2));

            loadEntry(Cubie(CORNER, DFL, PLUS), Facelet(D, 0, 0)); 
            loadEntry(Cubie(CORNER, DFL, OK), Facelet(L, 2, 2));
            loadEntry(Cubie(CORNER, DFL, MINUS), Facelet(F, 0, 2));

            loadEntry(Cubie(CORNER, DBL, PLUS), Facelet(D, 0, 2)); 
            loadEntry(Cubie(CORNER, DBL, OK), Facelet(B, 2, 2));
            loadEntry(Cubie(CORNER, DBL, MINUS), Facelet(L, 0, 2));

            loadEntry(Cubie(CORNER, DBR, OK), Facelet(R, 2, 2)); 
            loadEntry(Cubie(CORNER, DBR, PLUS), Facelet(D, 2, 2));
            loadEntry(Cubie(CORNER, DBR, MINUS), Facelet(B, 0, 2)); 
        }

        /// @brief Hash code for cubie
        int cubieCode(Cubie const& c) 
        {
            switch (c.type())
            {
            case CENTER:
                return c.placement();
            case EDGE:
                return 6 + 2*c.placement()+c.orientation();
            case CORNER:
                return 30 + 3*c.placement()+c.orientation(); 
            }
        }

        /// @brief Hash code for facelet
        int faceletCode(Facelet const& f)
        {
            return 9*f.face()+3*f.row()+f.col();
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

#ifdef DEBUG
        static void testFunction()
        {
            int count; 
            count = 0;
            for(int i = 0; i < 6; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    for(int k = 0; k < 3; k++)
                    {
                        Facelet f = Facelet((Face)i, j, k);
                        int code = val().faceletCode(f); 
                        assert(code == count);
                        count++;
                    }
                }
            }
            printf("[+] test facelet code OK");
            count = 0; 
            for(int i = 0; i < 3; i++)
            {
                int nb_place;
                int nb_ori;
                if(i == (int)CENTER) {nb_place = 6; nb_ori = 1;}
                if(i == (int)EDGE) {nb_place = 12; nb_ori = 2;}
                if(i == (int)CORNER) {nb_place = 8; nb_ori = 3;}
                for(int j = 0; j < nb_place; j++) {
                    for(int k =0; k < nb_ori; k++) {
                        Cubie c = Cubie((PieceType)i, j, k);
                        int code = val().cubieCode(c); 
                        assert(code == count);
                        count++;
                    }
                }
            }
            printf("[+] test cubie code OK");
        }
#endif
} conv; 

// Singleton instance initialization
Converter Converter::s_instance;


Cubie::Cubie(Facelet const &f)
{
    (*this) = conv::toCubie(f); 
}

Cubie::operator Facelet() const 
{
    return conv::toFacelet(*this); 
}

std::ostream& operator << (std::ostream &flux, rc::Face const &f)
{
    switch(f) {
        case rc::U: flux << "U"; break;
        case rc::D: flux << "D"; break;
        case rc::F: flux << "F"; break;
        case rc::B: flux << "B"; break;
        case rc::L: flux << "L"; break;
        case rc::R: flux << "R"; break;
        default: break;
    }
    return flux;
}

std::ostream& operator << (std::ostream &flux, rc::PieceType const &t)
{
    switch(t) {
        case rc::CENTER: flux << "CENTER"; break;
        case rc::EDGE  : flux << "EDGE"; break;
        case rc::CORNER: flux << "CORNER"; break;
        default: break;
    }
    return flux; 
}

std::ostream& operator << (std::ostream &flux, rc::EdgeP const &ep)
{
    switch(ep) {
        case rc::UF: flux << "UF"; break;
        case rc::UB: flux << "UB"; break;
        case rc::UL: flux << "UL"; break;
        case rc::UR: flux << "UR"; break;
        case rc::FL: flux << "FL"; break;
        case rc::FR: flux << "FR"; break;
        case rc::BL: flux << "BL"; break;
        case rc::BR: flux << "BR"; break;
        case rc::DF: flux << "DF"; break;
        case rc::DB: flux << "DB"; break;
        case rc::DL: flux << "DL"; break;
        case rc::DR: flux << "DR"; break;
        default: break;
    }
    return flux; 
}

std::ostream& operator << (std::ostream &flux, rc::CornerP const &cp)
{
    switch(cp) {
        case rc::UFL: flux << "UFL"; break;
        case rc::UFR: flux << "UFR"; break;
        case rc::UBL: flux << "UBL"; break;
        case rc::UBR: flux << "UBR"; break;
        case rc::DFL: flux << "DFL"; break;
        case rc::DFR: flux << "DFR"; break;
        case rc::DBL: flux << "DBL"; break;
        case rc::DBR: flux << "DBR"; break;
        default: break;
    }
    return flux; 
}

std::ostream& operator << (std::ostream &flux, rc::EdgeO const &eo)
{
    switch(eo) {
        case rc::GOOD: flux << "GOOD"; break;
        case rc::BAD  : flux << "BAD"; break;
        default: break;
    }
    return flux; 
}

std::ostream& operator << (std::ostream &flux, rc::CornerO const &co)
{
    switch(co) {
        case rc::OK: flux << "OK"; break;
        case rc::PLUS: flux << "PLUS"; break;
        case rc::MINUS: flux << "MINUS"; break;
        default: break;
    }
    return flux;
}

std::ostream& operator << (std::ostream &flux, rc::Facelet const &f)
{
    flux << f.face() << " " << (int)f.row() << " " << (int)f.col();
    return flux;
}

std::ostream& operator << (std::ostream &flux, rc::Cubie const &c)
{
    flux << c.type() << " ";
    switch(c.type()) {
        case rc::CENTER: flux << (rc::Face)c.placement(); break;
        case rc::EDGE: 
            flux << (rc::EdgeP)c.placement() << " " << (rc::EdgeO)c.orientation(); 
            break;
        case rc::CORNER:
            flux << (rc::CornerP)c.placement() << " " << (rc::CornerO)c.orientation(); 
            break;
        default: break;
    }
    return flux;
}
