#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Macros.h"


class Resources
{
public:
	~Resources();
	static Resources& instance();

	//Access Functions
	sf::Font* getFont();
	//sf::Texture* getBtnTexture(Btns button);
	//sf::Texture* getCatSpriteSheet();
	//sf::Texture* getWinPageTexture();
	//sf::Texture* getLosePageTexture();
	//sf::Image* getGameIcon();
	//sf::SoundBuffer* getAudioClick();
	sf::Texture* getPlayerTexture(Player player);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	//Load Functions
	void loadFont();
	//void loadBtnTextures();
	//void loadCatSpriteSheet();
	//void loadWinPageTexture();
	//void loadLosePageTexture();
	//void loadAudioClick();
	//void loadGameIcon();
	void loadPlayers();


	//======Members==========

	//Fonts
	sf::Font m_font;

	////Textures
	//sf::Texture m_catSpriteSheet;
	//sf::Texture m_winPageTexture;
	//sf::Texture m_losePageTexture;
	//sf::Image m_gameIcon;
	std::vector<sf::Texture> m_players;

	//std::vector<sf::Texture> m_btnTextures;

	////Audio
	//sf::SoundBuffer m_audioClick;
};