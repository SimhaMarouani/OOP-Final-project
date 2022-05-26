#pragma once
#include "Button.h"
#include "Resources.h"
#include <string>


class TitledButton : public Button
{
public:
	//TitledButton(); //Noga: remember to add texture here
	//TitledButton(sf::Vector2f ButtonSize); //Noga: remember to add texture here
	TitledButton(sf::Vector2f ButtonSize, std::string str, float textSize, sf::Vector2f textPos, sf::Font& font); //Noga: remember to add texture here

	void setTextString(std::string text); //the content
	void setTextColor(sf::Color c);
	void setTextSize(float s);
	void setTextPosition(sf::Vector2f p);
	void setTextFont(sf::Font &f);

	void draw(sf::RenderWindow& window);
private:
	void setTextAttributes(std::string str, float textSize, sf::Vector2f textPos, sf::Font &font);
	sf::Text m_buttonText;
};

