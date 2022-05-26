#include "..\..\include\Screens\GameScreen.h"
#include "Screens/GameScreen.h"


GameScreen::GameScreen()
    : m_activePlayer(Player::Heavy), m_escPressed(false)
{
}

//-----------------------------------------------------------------

void GameScreen::draw(sf::RenderWindow& window)
{
	m_world.draw(window);
	m_dataDisplay.draw(window);

    DebugDraw d(&window);
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_world.getWorld()->SetDebugDraw(&d);
    m_world.getWorld()->DebugDraw();
    
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
            m_dataDisplay.setCurrPlayer(int(m_activePlayer));
            std::cout <<"active: " <<  int(m_activePlayer) << std::endl;
        }

        else if (event.key.code == sf::Keyboard::Escape)
        {
            m_escPressed = true;
        }

        break;
    }
    case sf::Event::MouseButtonReleased:
        m_dataDisplay.handleClick(event);
        m_activePlayer = Player(m_dataDisplay.getCurrPlayer());
        break;

    default:
        break;
    }
 
}

//-----------------------------------------------------------------

void GameScreen::update(float deltaTime)
{
    m_world.moveActive(deltaTime, m_activePlayer);
}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}

bool GameScreen::isEscPressed()
{
    return m_escPressed;
}

void GameScreen::loadLevel(int level)
{
    //TODO: load level from file or something
}

void GameScreen::setDirection(Direction dir)
{
    m_world.setActiveDirection(dir, m_activePlayer);
}

