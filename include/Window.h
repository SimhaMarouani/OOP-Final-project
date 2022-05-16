#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Board.h"

class Controller;
 

class Window
{
public:
    Window();

private:
    sf::RenderWindow m_window;
};