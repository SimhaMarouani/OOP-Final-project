#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"

class Button
{
public:
	Button();
	Button(sf::Vector2f buttonPos, sf::Vector2f textPos, sf::Vector2f buttonSize, std::string buttonName, int textSize);

	void draw(sf::RenderWindow& window);

private:
	void setButtonSize(sf::Vector2f buttonSize);

	sf::Vector2f m_buttonSize;
	sf::Font* m_font;
	sf::RectangleShape m_button;
	sf::Text m_buttonText;
};


