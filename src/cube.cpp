#include "inc/cube-impl.hpp"


using namespace rc;


 Cube::Cube()
 {
    for(int i = 0; i < m_data.size(); i++)
    {
        m_data[i] = i; 
    }
 }


 Color Cube::colorAt(Face f, const char i, const char j) const
 {
    return to_color((Face)(m_data[f*9+3*i+j]/9));
 }

 Cube& Cube::turn(Face)
 {
    return *this; 
 }


bool Cube::isSolved() const 
{
    return false;
}


std::ostream& operator << (std::ostream &flux, const Cube &cube)
{
   size_t index = 0; 
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if((6<=j && j < 9) || (3 <= i && i<6))
            {
                std::cout << cube.colorAt((Face)(index/9), (index/3)%3, index%3) << " ";
                index++; 
            } else std::cout << "  ";
        }
        flux << std::endl; 
    }
    return flux; 
}