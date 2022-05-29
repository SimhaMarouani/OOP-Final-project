#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Macros.h"
#include "Utilities.h"


class Resources
{
public:
	~Resources();
	static Resources& instance();

	//Access Functions
	sf::Font* getFont();
	sf::Texture* getBackground(Backgrounds index);
	sf::Texture* getPlayerTexture(Player player);
	sf::Texture* getPlayerFaceTexture(Player player);
	sf::Texture* getPlayerArrowTexture();
	sf::Texture* getObjectTexture(Objects obj);
	sf::Texture* getLevelMenuTexture(LevelState l);
	sf::Texture* getHomePageBtnsTexture(HomeButtonType b);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadFont();

	//Textures
	void loadPlayers();
	void loadPlayersFace();
	void loadObjects();
	void loadPlayerArrow();
	void loadBackgroundTextures();
	void loadLevelMenuIcons();
	void loadHomePageBtnsTexture();

	
	//Audio 
	

	//======Members==========

	//Fonts
	sf::Font m_font;

	////Textures
	sf::Texture m_playerArrow;;
	std::vector<sf::Texture> m_players;
	std::vector<sf::Texture> m_playersFace;
	std::vector<sf::Texture> m_objects;
	std::vector<sf::Texture> m_levelMenuTexture;
	std::vector<sf::Texture> m_homePageBtnsTexture;

	sf::Texture m_backgroundTextures[NUM_OF_BG_TEXTURES];
	std::string m_fileBackground[NUM_OF_BG_TEXTURES]{ "home_screen_bg.jpg", "game_background.png", /*"win.png", "Lose.png", "Help.png"*/ };
	
	

	////Audio
	//sf::SoundBuffer m_audioClick;
};