#include "Screens/GameScreen.h"
#include "Controller.h"


GameScreen::GameScreen()
    : m_activePlayer(Player::Heavy), m_win(false),
      m_background(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT)),
      m_btnsClick(Resources::instance().getAudioClick())
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

    if(m_win)
    {
        m_endLevelView->draw(window);
    }

    if (m_pageStatus == LevelActions::Pause)
    {
        m_settingsView->draw(window, Screen::Game);
    }    
}

void GameScreen::processEvents(sf::Event event, Controller &controller)
{
    switch (event.type)
    {
    case sf::Event::KeyReleased:
    {
        if (event.key.code == sf::Keyboard::P && m_pageStatus != LevelActions::Pause)
        {
            m_activePlayer = Player((int(m_activePlayer) + 1) % 3);
            m_dataDisplay.setCurrPlayer(int(m_activePlayer));
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            m_pageStatus = LevelActions::None;
            controller.updatePage(Screen::HomePage);
        }
        break;
    }
    case sf::Event::MouseButtonReleased:
        if (m_win)
        {
            m_win = false;
            if (m_endLevelView->isContainRetry(event))
            {
                std::cout << "retry pressed"<<std::endl;
                retryLevel();
            }
            else if (m_endLevelView->isContainNext(event))   //need to update the level num and reload a level
                ;
            else if (m_endLevelView->isContainMenu(event))
                controller.updatePage(Screen::HomePage);
        }
        if(m_pageStatus != LevelActions::Pause)
            m_dataDisplay.handleClick(event, *this);
        else
        {
            m_settingsView->handleClick(event, Screen::Game);

            if (!m_settingsView->isContain(event)) //Noga: temp
            {
                updateStatus(LevelActions::None);
                m_dataDisplay.startTimer();
            }

            if (m_settingsView->isContainExit(event))
            {
                m_btnsClick.playMusic();
                updateStatus(LevelActions::None);
                m_dataDisplay.startTimer();
            }

            if (m_settingsView->isContainHome(event))
            {
                m_btnsClick.playMusic();
                updateStatus(LevelActions::None);
                controller.updatePage(Screen::HomePage);
            }
        }
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

    if (m_world.allPlayersReachedEnd()) {
        m_win = true;
        std::cout << "Level Won";
    }
}

void GameScreen::resetTimer()
{
    m_dataDisplay.resetTimer();
}

void GameScreen::pauseTimer()
{
    m_dataDisplay.switchTimer();
}

void GameScreen::loadLevel(int level)
{
    //TODO: load level from file or something
}

void GameScreen::setDirection(Direction dir)
{
    //m_world.setActiveDirection(dir, m_activePlayer);
}

void GameScreen::updateStatus(LevelActions la)
{
    m_pageStatus = la;
}

void GameScreen::initSettings(std::shared_ptr<Settings> s)
{
    m_settingsView = move(s);
}

void GameScreen::initEndLevelScreen(std::shared_ptr<WinScreen> s)
{
    m_endLevelView = move(s);
}

//Noga
void GameScreen::retryLevel()
{
    m_world.loadLevel(1); //simha: need to chek the level num
    m_dataDisplay.resetTimer();
    m_activePlayer = Player::Heavy;
    m_dataDisplay.setCurrPlayer((int)m_activePlayer);
    std::cout << "retry\n";
}

LevelActions GameScreen::getPageStatus() const
{
    return m_pageStatus;
}

