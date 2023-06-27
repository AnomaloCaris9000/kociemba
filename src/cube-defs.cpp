#include "cube-defs.hpp"

using namespace rc;


Facelet::Facelet(Face f, byte_t i, byte_t j)
{
    // TODO
    (void)f;
    (void)i;
    (void)j;
}

byte_t Facelet::row() const
{
    // TODO
    return 0; 
}

byte_t Facelet::col() const
{
    // TODO
    return 0; 
}

Face Facelet::face() const
{
    // TODO
    return F; 
} 

Cubie::Cubie(PieceType type, byte_t p, byte_t o)
{
    // TODO
}

Cubie::Cubie(Facelet f)
{
    // TODO
    (void)f; 
}

PieceType Cubie::type() const 
{
    // TODO
    return EDGE; 
}

byte_t Cubie::placement() const 
{
    // TODO 
    return 0; 
}

byte_t Cubie::orientation() const 
{
    // TODO:
    return 0; 
}

Cubie::operator Facelet() const 
{
    // TODO
    return Facelet(F, 0, 0); 
}