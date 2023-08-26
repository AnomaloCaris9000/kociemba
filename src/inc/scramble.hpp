#ifndef SCRAMBLE_HPP
#define SCRAMBLE_HPP

#include "cube-defs.hpp"

namespace rc 
{

/**
 * @brief Scramble for a rubiks cube.
 */
class Scramble 
{
    public:
        enum Move {
            U, U2, Up,
            D, D2, Dp,
            F, F2, Fp,
            B, B2, Bp,
            L, L2, Lp,
            R, R2, Rp
        };

    private:
        struct Node;
    
    public:

        /**
         * @brief Construct an empty scramble.
         */
        Scramble();

        /**
         * @brief Construct a new Scramble object
         * 
         * @param s The Scrambl's notation.
         */
        Scramble(std::string s);

        ~Scramble();

        /**
         * @brief Push m at the front of the collection.
         * @param m 
         * @return The modified scramble.
         */
        Scramble& pushFront(Move m);

        /**
         * @brief Push m at the back of the collection.
         * @param m 
         * @return The modified scramble.
         */
        Scramble& pushBack(Move m);

        /**
         * @brief Remove front.
         * @note Scramble must be not empty.
         * @return The modified scramble.
         */
        Scramble& popFront();

        /**
         * @brief Remove front.
         * @note Scramble must be not empty.
         * @return The modified scramble.
         */
        Scramble& popBack();

        /**
         * @brief Make the scramble empty.
         * @return The modified scramble.
         */
        Scramble& erase();

        /**
         * @brief Concatenation operator for two scramble.
         * 
         * @param other Another scramble.
         * @note other will be erased?
         * @return The concatenation itself.
         */
        Scramble& cat(Scramble const& other);

        /**
         * @brief Inverse the scramble.
         * @note If you concatenate a scramble with his inverse, it'll give you
         * the empty scramble.
         * 
         * @return The modified scramble.
         */
        Scramble& insverse();

        /**
         * @brief Make the scramble shorter without changing its 'value'.
         * @return The modified scramble.
         */
        Scramble& simplify();

        /**
         * @brief Simplify the sramble and put commutativ move (such as R L)
         * in an arbitrary but concistant order. 
         * @return The modified scramble.
         */
        Scramble& normalize();

        /**
         * @brief Is the scramble simplified?
         * @return true if it is, false if it isn't.
         */
        bool isSimplified();

        /**
         * @brief Is the scramble normalized?
         * @note s.isSimplified() => yes
         * @return true if it is, false if it isn't.
         */
        bool isNormalized();

        /**
         * @brief Is the scramble empty?
         * @return true if it is, false if it isn't.
         */
        bool isEmpty() const;

        /**
         * @brief Front getter
         * @return The front move.
         */
        Move front() const;

        /**
         * @brief Front getter
         * @return The back move.
         */
        Move back() const;

};

} // namespace rc 

// for cout
std::ostream& operator << (std::ostream&, rc::Scramble const&);


#endif