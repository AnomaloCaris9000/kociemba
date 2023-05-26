#include "facelet.hpp"


namespace rc
{

Facelet::Facelet(Cubie const cubie)
{
    face = F; 
}

Cubie Facelet::toCubie() const 
{
    return Cubie(EDGE, 0, 0); 
}

FaceletLevel::FaceletLevel(CubieLevel &cubies):
    m_cubies(cubies)
{}

Facelet FaceletLevel::at(Facelet fcl) const
{
    return Facelet(m_cubies.at(fcl.toCubie()));  
}

} // namespace rc