#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "DataDisplay.h"
#include "Utilities.h"

class Controller;
class Menu;

class Window
{
public:
    Window();
    void update();
    bool isOpen();
    bool pollEvent(sf::Event& event);
    void close();
    void clear(sf::Color color = sf::Color::Color::White);
    void display();
    void drawHomePage(Menu &homePage); //Noga: first page
    void drawLevelMenuPage(); //Noga: after click start the user choose level
    void drawGame(DataDisplay& dataDisplay); //Noga: the game game like the level you know

private:
    sf::RenderWindow m_window;
    sf::RectangleShape m_menuBackground;
    //sf::RectangleShape m_winBackground;
    //sf::RectangleShape m_loseBackground;
};