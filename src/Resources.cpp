#include "Resources.h"
#include "macros.h"


Resources::Resources()
{
	loadFont();
	loadBackgroundTextures();
	loadPlayers();
	loadObjects();
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

sf::Texture* Resources::getArrowTexture()
{
	if (!m_arrow.loadFromFile("arrow.png")) //Todo: move to load function
	{
		std::cerr << "error loading arrow from file";
	}

	return &m_arrow;
}

sf::Texture* Resources::getObjectTexture(Objects obj)
{
	return &m_objects[(int)obj];
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
	for (int i = 0; i < NUM_OF_TEXTURES; ++i)
	{
		if (!m_backgroundTextures[i].loadFromFile(m_fileBackground[i]))
			exit(EXIT_FAILURE);
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

void Resources::loadObjects()
{
	m_objects.resize(NUM_OF_OBJS);

	if (!m_objects[(int)Objects::Hay].loadFromFile("hay.png"))
	{
		std::cerr << "error loading player textures from file";
	}
}
