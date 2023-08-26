#include "app.hpp"

#define RECT_SIZE 32

sf::Color colorRcToSf(rc::Color color)
{
    switch(color)
    {
        case rc::GREEN:
            return sf::Color::Green;
            break;
        case rc::BLUE:
            return sf::Color::Blue;
            break;
        case rc::WHITE:
            return sf::Color::White;
            break;
        case rc::YELLOW:
            return sf::Color::Yellow;
            break;
        case rc::ORANGE:
            return sf::Color(255,127,80);
            break;
        case rc::RED:
            return sf::Color::Red;
            break;
    }
}

App::App():
    m_window(sf::RenderWindow(sf::VideoMode(RECT_SIZE*12, RECT_SIZE*9), "SFML works!")),
    m_cube()
{
}

App::~App()
{
    // TODO
}

void App::handleEvent(sf::Event const& event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        m_window.close();
        break;
    
    case sf::Event::KeyPressed:
        #define ifKeyPressedTurn(k, m) \
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::k)) m_cube.turn(rc::Scramble::m)
        ifKeyPressedTurn(A, F); // NOTE: make sens for azety keyboard only.
        else ifKeyPressedTurn(Z, R);
        else ifKeyPressedTurn(E, U);
        else ifKeyPressedTurn(R, B);
        else ifKeyPressedTurn(T, L);
        else ifKeyPressedTurn(Y, D);

        else ifKeyPressedTurn(Q, Fp);
        else ifKeyPressedTurn(S, Rp);
        else ifKeyPressedTurn(D, Up);
        else ifKeyPressedTurn(F, Bp);
        else ifKeyPressedTurn(G, Lp);
        else ifKeyPressedTurn(H, Dp);

        else ifKeyPressedTurn(W, F2);
        else ifKeyPressedTurn(X, R2);
        else ifKeyPressedTurn(C, U2);
        else ifKeyPressedTurn(V, B2);
        else ifKeyPressedTurn(B, L2);
        else ifKeyPressedTurn(N, D2);

        #undef ifKeyPressedTurn
        break;
    
    default:
        break;
    }
}

void App::paint()
{
    static sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(RECT_SIZE, RECT_SIZE));
    sf::Vector2i facePos;
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    for(int f = 0; f < 6; f++)
    {
        switch((rc::Face)f)
        {
            case rc::U:
                facePos.x = 6; facePos.y = 0; 
                break;
            case rc::B:
                facePos.x = 0; facePos.y = 3; 
                break;
            case rc::L:
                facePos.x = 3; facePos.y = 3; 
                break;
            case rc::F:
                facePos.x = 6; facePos.y = 3; 
                break;
            case rc::R:
                facePos.x = 9; facePos.y = 3; 
                break;
            case rc::D:
                facePos.x = 6; facePos.y = 6; 
                break;
        }
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                rect.setPosition((facePos.x+row)*RECT_SIZE, (facePos.y+col)*RECT_SIZE);
                rect.setFillColor(colorRcToSf(m_cube.at((rc::Face)f, row, col)));
                m_window.draw(rect); 
            }
        }
    }
}

void App::launchLoop()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            handleEvent(event); 
        }
        
        m_window.clear();
        paint();
        m_window.display();
    }
}