#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include "cube.hpp"

class App
{
    private:
        sf::RenderWindow m_window;
        rc::Cube m_cube; 

        void handleEvent(sf::Event const&);
        void paint();

    public:
        explicit App();
        ~App();
        
        void launchLoop();
};


#endif