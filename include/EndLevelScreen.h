#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Resources.h"
#include "Macros.h"
#include "HighScore.h"
#include "Utilities.h"
#include "Audio.h"

//#include "Controller.h"


class EndLevelScreen{
public:
    EndLevelScreen();
    virtual ~EndLevelScreen() = default;

    void draw(sf::RenderWindow& window, bool status, int levelNum, int time);

    //void handleClick(sf::Event event);
    void createText();

    bool isContainRetry(sf::Event e);
    bool isContainMenu(sf::Event e);
    bool isContainNext(sf::Event e);

private:
    void createBtns();
    std::string setTimeText(int time);
    void playSound(bool status);

    sf::RectangleShape m_background;

    Button m_retryBtn;
    Button m_nextLevelBtn;
    Button m_menuBtn;

    sf::Text m_winText;
    sf::Text m_loseText;
    sf::Text m_timeText;
    sf::Text m_newScoreText;

    Audio m_winSound;
    Audio m_loseSound;

    int m_soundCounter;
};
