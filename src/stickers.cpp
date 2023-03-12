#include "inc/stickers.hpp"


using namespace rc;


Stickers::Stickers(ColorArray color):
    m_color(color)
{};
Stickers::Stickers():
    m_color({GREEN, BLUE, RED, ORANGE, WHITE, YELLOW}) // order F, B, R, L, U, D 
{};
inline Color Stickers::operator () (EdgeP ep, EdgeO eo) const
{
    return m_color[edge_face(ep, eo)];
}

inline Color Stickers::operator () (CornerP cp, CornerO co) const
{
    return m_color[corner_face(cp, co)];
}





