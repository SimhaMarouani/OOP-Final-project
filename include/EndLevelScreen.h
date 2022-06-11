#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Resources.h"
#include "Macros.h"
//#include "Controller.h"


class EndLevelScreen{
public:
    EndLevelScreen(bool status);
    virtual ~EndLevelScreen() = default;

    void draw(sf::RenderWindow& window);

    //void handleClick(sf::Event event);
    void createText();
    void setWinText();
    void setLoseText();

    bool isContainRetry(sf::Event e) const;
    bool isContainMenu(sf::Event e) const;
    bool isContainNext(sf::Event e) const;

private:
    void createBtns();

    sf::RectangleShape m_background;

    Button m_retryBtn;
    Button m_nextLevelBtn;
    Button m_menuBtn;

    sf::Text m_text;
    sf::Text m_timeText;
};
