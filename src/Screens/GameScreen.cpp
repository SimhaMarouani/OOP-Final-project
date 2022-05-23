#include "Screens/GameScreen.h"


GameScreen::GameScreen()
    : m_activePlayer(Player::Heavy)
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
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P)
        {
            m_activePlayer = Player((int(m_activePlayer) + 1) % 3);
            std::cout <<"active: " <<  int(m_activePlayer) << std::endl;
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

}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}
