#ifndef SCRAMBL_HPP
#define SCRAMBL_HPP

#include "cube-defs.hpp"

namespace rc 
{

/**
 * @brief Scramble for a rubiks cube. Exemple : F R U R' U' F' D2 B L
 */
class Scramble 
{
    public:
        enum Move {
            U, U2, Up,
            D, D2, Dp,
            F, F2, Fd,
            B, B2, Bd,
            L, L2, Ld,
            R, R2, Rd
        };
    
    public:
        Scramble();
        Scramble(std::string);
        ~Scramble();

        Scramble& append(Scramble const&);

        Scramble& pushFront(Move m);
        Scramble& pushBack(Move m);

        Scramble& popFront(Move);
        Scramble& popBack(Move);

        Scramble& insverse();
        Scramble& simplify();
        Scramble& normalize();

        bool isSimplified();
        bool isNormalized();
        bool isEmpty() const;

        Move front() const;
        Move back() const;

};

} // namespace rc 

// for cout
std::ostream& operator << (std::ostream&, rc::Scramble const&);


#endif