#ifndef KOCIEMBA_HPP
#define KOCIEMBA_HPP

#include "coord.hpp"

namespace rc 
{

/**
 * @brief Solve a scramble from <U, D, F, B R, L> to <U, D, F2, B2, R2, L2> gen sub-group.
 * @return The solution.
 */
Scramble solveG0(Coord const& coord);

/**
 * @brief Solve a <U, D, F2, B2, R2, L2> gen sramble.
 * @param coord
 * @return The solution.
 */
Scramble solveG1(Coord const& coord);

/**
 * @brief Solve a cube.
 * @param coord
 * @return The solution.
 */
Scramble solve(Coord const& coord);

/**
 * @brief Search the optimal solution for a cube. 
 * @param coord
 * @return The solution.
 */
Scramble solveOpt(Coord const& coord);

} // namespace rc

#endif 