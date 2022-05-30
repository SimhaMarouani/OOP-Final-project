#include "Resources.h"

Resources::Resources()
{
	loadFont();
	loadBackgroundTextures();
	loadPlayers();
	loadPlayersFace();
	loadPlayerArrow();
	loadObjects();
	loadLevelMenuIcons();
	loadHomePageBtnsTexture();
}


//-----------------------------------------------------------------

Resources::~Resources()
{
}

//-----------------------------------------------------------------

Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}


//===============================================================//
//							 GET DATA
//===============================================================//

sf::Font* Resources::getFont()
{
	return &m_font;
}

//-----------------------------------------------------------------
	
sf::Texture* Resources::getBackground(Backgrounds index)
{
	return &m_backgroundTextures[int(index)];
}

//
//sf::SoundBuffer* Resources::getAudioClick()
//{
//	return &m_audioClick;
//}
//

sf::Texture* Resources::getPlayerTexture(Player player)
{
	return &m_players[(int)player];
}

sf::Texture* Resources::getPlayerFaceTexture(Player player)
{
	return &m_playersFace[(int)player];
}

sf::Texture* Resources::getPlayerArrowTexture()
{
	return &m_playerArrow;
}

sf::Texture* Resources::getObjectTexture(Objects obj)
{
	return &m_objects[(int)obj];
}

sf::Texture* Resources::getLevelMenuTexture(LevelState l)
{
	return &m_levelMenuTexture[(int)l];
}

sf::Texture* Resources::getHomePageBtnsTexture(HomeButtonType b)
{
	return &m_homePageBtnsTexture[(int)b];
}

//===============================================================//
//							 LOAD DATA
//===============================================================//

void Resources::loadFont()
{
	if (!m_font.loadFromFile("Font.ttf"))
	{
		std::cerr << "error loading font from file";
	}
}

//-----------------------------------------------------------------

void Resources::loadBackgroundTextures()
{
	for (int i = 0; i < NUM_OF_BG_TEXTURES; ++i)
	{
		if (!m_backgroundTextures[i].loadFromFile(m_fileBackground[i]))
			exit(EXIT_FAILURE);
	}
}

void Resources::loadLevelMenuIcons()
{
	m_levelMenuTexture.resize(2);
	if (!m_levelMenuTexture[(int)LevelState::Lock].loadFromFile("lock_level.png")
		|| !m_levelMenuTexture[(int)LevelState::Unlock].loadFromFile("unlock_level.png"))
	{
		std::cerr << "error loading player textures from file";
	}
}

void Resources::loadHomePageBtnsTexture()
{
	m_homePageBtnsTexture.resize(4);
	if (!m_homePageBtnsTexture[(int)HomeButtonType::Start].loadFromFile("start.png")
		|| !m_homePageBtnsTexture[(int)HomeButtonType::Help].loadFromFile("help.png")
		|| !m_homePageBtnsTexture[(int)HomeButtonType::Settings].loadFromFile("settings.png")
		|| !m_homePageBtnsTexture[(int)HomeButtonType::Exit].loadFromFile("exit.png"))
	{
		std::cerr << "error loading btns textures from file";
	}
}

void Resources::loadPlayers()
{
	m_players.resize(NUM_OF_PLAYERS);
	if (!m_players[(int)Player::Heavy].loadFromFile("polar-bear.png")
				|| !m_players[(int)Player::Light].loadFromFile("penguin.png")
				|| !m_players[(int)Player::Simple].loadFromFile("deer.png"))
			{
				std::cerr << "error loading player textures from file";
			}
}

void Resources::loadPlayersFace()
{
	m_playersFace.resize(NUM_OF_PLAYERS);
	if (!m_playersFace[(int)Player::Heavy].loadFromFile("heavy_player_face.png")
		|| !m_playersFace[(int)Player::Simple].loadFromFile("simple_player_face.png")
		|| !m_playersFace[(int)Player::Light].loadFromFile("light_player_face.png")
		)
	{
		std::cerr << "error loading player textures from file";
	}
}

void Resources::loadObjects()
{
	m_objects.resize(NUM_OF_OBJS);

	if (!m_objects[(int)Objects::Hay].loadFromFile("hay.png"))
	{
		std::cerr << "error loading player textures from file";
	}
}

void Resources::loadPlayerArrow()
{
	if (!m_playerArrow.loadFromFile("arrow.png")) //Todo: move to load function
	{
		std::cerr << "error loading arrow from file";
	}
}
