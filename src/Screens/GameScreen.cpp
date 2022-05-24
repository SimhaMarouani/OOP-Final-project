#include "Screens/GameScreen.h"


GameScreen::GameScreen()
    : m_activePlayer(Player::Heavy), m_escPressed(false)
{
}

//-----------------------------------------------------------------

void GameScreen::draw(sf::RenderWindow& window)
{
	m_board.draw(window);
	m_dataDisplay.draw(window);
}

void GameScreen::processEvents(sf::Event event)
{
    m_escPressed = false;

    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P)
        {
            m_activePlayer = Player((int(m_activePlayer) + 1) % 3);
            std::cout <<"active: " <<  int(m_activePlayer) << std::endl;
        }

        else if (event.key.code == sf::Keyboard::Escape)
        {
            m_escPressed = true;
            //simha: Need to pause the timer
        }

        break;
    }
    case sf::Event::MouseButtonReleased:
        //m_dataDisplay.handleClick();
        break;
    default:
        break;
    }
 
}

//-----------------------------------------------------------------

void GameScreen::update(float deltaTime)
{
    m_board.moveActive(deltaTime);
}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}

bool GameScreen::isEscPressed()
{
    return m_escPressed;
}

void GameScreen::setDirection(Direction dir)
{
    m_board.setActiveDirection(dir);
}

