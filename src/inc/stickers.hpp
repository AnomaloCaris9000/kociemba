#ifndef SCHEME_HPP
#define SCHEME_HPP

#include "cube-defs.hpp"

#include <array>

namespace rc
{

class Stickers
{
    using ColorArray = std::array<Color, NB_FACES>;

    private:
        ColorArray m_color;
    public:
        Stickers(ColorArray color);
        Stickers() = default;

        Color operator () (EdgeP, EdgeO) const;
        Color operator () (CornerP, CornerO) const;
};

}


#endif 