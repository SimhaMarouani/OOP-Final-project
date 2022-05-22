#include "Resources.h"
#include "macros.h"


Resources::Resources()
{
	loadFont();
	loadBackgroundTextures();
	/*loadBtnTextures();
	loadCatSpriteSheet();
	loadAudioClick();
	loadWinPageTexture();
	loadLosePageTexture();
	loadGameIcon();*/
	loadPlayers();
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

//-----------------------------------------------------------------
//
//sf::Texture* Resources::getBtnTexture(Btns button)
//{
//	return &m_btnTextures[(int)button];
//}
//
////-----------------------------------------------------------------
//
//sf::Texture* Resources::getCatSpriteSheet()
//{
//	return &m_catSpriteSheet;
//}
//
////-----------------------------------------------------------------
//
//sf::Texture* Resources::getWinPageTexture()
//{
//	return &m_winPageTexture;
//}
//
////-----------------------------------------------------------------
//
//sf::Texture* Resources::getLosePageTexture()
//{
//	return &m_losePageTexture;
//}
//
//sf::Image* Resources::getGameIcon()
//{
//	return &m_gameIcon;
//}
//
////-----------------------------------------------------------------
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

////-----------------------------------------------------------------
//
//void Resources::loadBtnTextures()
//{
//	m_btnTextures.resize(NUM_OF_BTNS);
//
//	if (!m_btnTextures[(int)Btns::NewGame].loadFromFile("new_game_btn.png")
//		|| !m_btnTextures[(int)Btns::Undo].loadFromFile("undo_btn.png")
//		|| !m_btnTextures[(int)Btns::Reset].loadFromFile("resart_btn.png"))
//	{
//		std::cerr << "error loading button textures from file";
//	}
//}
//
////-----------------------------------------------------------------
//
//void Resources::loadCatSpriteSheet()
//{
//	if (!m_catSpriteSheet.loadFromFile("cat.png"))
//	{
//		std::cerr << "error loading cat textures from file";
//	}
//}
//
////-----------------------------------------------------------------
//
//void Resources::loadWinPageTexture()
//{
//	if (!m_winPageTexture.loadFromFile("win_page.png"))
//	{
//		std::cerr << "error loading cat textures from file";
//	}
//}
//
////-----------------------------------------------------------------
//
//void Resources::loadLosePageTexture()
//{
//	if (!m_losePageTexture.loadFromFile("lose_page.png"))
//	{
//		std::cerr << "error loading cat textures from file";
//	}
//}
//
////-----------------------------------------------------------------
//
//void Resources::loadAudioClick()
//{
//	if (!m_audioClick.loadFromFile("click.wav"))
//	{
//		std::cerr << "error loading game music from file";
//	}
//}
//
//void Resources::loadGameIcon()
//{
//	if (!m_gameIcon.loadFromFile("GameIcon.png"))
//	{
//		std::cerr << "error loading game icon from file";
//	}
//}

void Resources::loadPlayers()
{
	m_players.resize(NUM_OF_PLAYERS);
	if (!m_players[(int)Player::PolarBear].loadFromFile("polar-bear.png")
				|| !m_players[(int)Player::Penguin].loadFromFile("penguin.png")
				|| !m_players[(int)Player::Deer].loadFromFile("deer.png"))
			{
				std::cerr << "error loading player textures from file";
			}
}