#pragma once
#include <SFML/Graphics.hpp>
//#include "Menu.h"
#include "Board.h"

class Controller;

class Window
{
public:
    Window();

    void processEvents(Controller& controller);//, Board& board);
    void update();
    void render();
    bool isOpen();

private:
    sf::RenderWindow m_window;
    //sf::RectangleShape m_gameBackground;
    //sf::RectangleShape m_winBackground;
    //sf::RectangleShape m_loseBackground;
};