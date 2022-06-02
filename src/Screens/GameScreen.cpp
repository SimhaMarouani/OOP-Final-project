#include "Screens/GameScreen.h"
#include "Controller.h"


GameScreen::GameScreen()
    : m_activePlayer(Player::Heavy),
      m_background(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT))
{
    m_background.setTexture(Resources::instance().getBackground(Screen::Game));
}

//-----------------------------------------------------------------

void GameScreen::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
	m_world.draw(window);
	m_dataDisplay.draw(window);

    DebugDraw d(&window);
    uint32 flags = b2Draw::e_shapeBit;
    d.SetFlags(flags);
    m_world.getWorld()->SetDebugDraw(&d);
    m_world.getWorld()->DebugDraw(); 
}

void GameScreen::processEvents(sf::Event event, Controller &controller)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P)
        {
            m_activePlayer = Player((int(m_activePlayer) + 1) % 3);
            m_dataDisplay.setCurrPlayer(int(m_activePlayer));
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            controller.updatePage(Screen::HomePage);
        }
        break;
    }
    case sf::Event::MouseButtonReleased:
        m_dataDisplay.handleClick(event);
        break;
    default:
        break;
    }
}

//-----------------------------------------------------------------

void GameScreen::update(float deltaTime)
{
    m_world.moveActive(deltaTime, m_activePlayer);
    m_world.moveArrow(m_activePlayer);
}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}

void GameScreen::loadLevel(int level)
{
    //TODO: load level from file or something
}

void GameScreen::setDirection(Direction dir)
{
    m_world.setActiveDirection(dir, m_activePlayer);
}

