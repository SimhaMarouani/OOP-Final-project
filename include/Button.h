#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Macros.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
public:
	Button(sf::Texture &texture, sf::Vector2f size); //Noga: we need to use the tecture here after we replace the rectangle with sprite
	Button() {};
	virtual ~Button() = default;
	void draw(sf::RenderWindow& window);

	//get
	bool isContain(sf::Event event) const;

	//set sprite
	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture* texture);
	void setColor(sf::Color color);
	void setSize(sf::Vector2f size);
	void setOutline(sf::Color color, float thickness);


private:
	sf::Sprite m_button; //Noga: rectangle or Sprite?		simha: sprite will be better
};
