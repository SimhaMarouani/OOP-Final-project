#pragma once
#include "Button.h"
#include "Resources.h"
#include <string>


class TitledButton : public Button
{
public:
	TitledButton(const sf::Texture &texture, const sf::Vector2f &ButtonSize, 
				const std::string str, unsigned int textSize, const sf::Vector2f &textPos, const sf::Font& font);

	void setTextString(const std::string &text); //the content
	void setTextColor(const sf::Color &c);
	void setTextSize(unsigned int s);
	void setTextPosition(const sf::Vector2f& p);
	void setTextFont(const sf::Font &f);

	void draw(sf::RenderWindow& window);
private:
	void setTextAttributes(const std::string& str, unsigned int textSize, const sf::Vector2f& textPos, const sf::Font &font);
	sf::Text m_buttonText;
};

