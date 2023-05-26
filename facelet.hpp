#ifndef FACELET_HPP
#define FACELET_HPP

#include "cube-defs.hpp"

namespace rc {

struct Facelet {
    Face f;
    byte_t i, j; 
};

class FaceletLevel;

} // namespace rc 


#endif 