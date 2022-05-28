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
	sf::Texture* getArrowTexture();
	sf::Texture* getObjectTexture(Objects obj);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadFont();
	void loadBackgroundTextures();
	void loadPlayers();
	void loadObjects();


	//======Members==========

	//Fonts
	sf::Font m_font;

	////Textures
	sf::Texture m_arrow;;
	std::vector<sf::Texture> m_players;
	std::vector<sf::Texture> m_objects;

	sf::Texture m_backgroundTextures[NUM_OF_TEXTURES];
	std::string m_fileBackground[NUM_OF_TEXTURES]{ "Menu-background.jpg"/*, "GameBackground.png", "win.png", "Lose.png", "Help.png"*/ };
	
	

	////Audio
	//sf::SoundBuffer m_audioClick;
};