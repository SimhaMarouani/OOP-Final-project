#pragma once
#include "GameObjects.h"
#include "Macros.h"
#include "Utilities.h"

class Players : public GameObjects
{
public:
	Players();
	Players(Player type);

	void setPostition(sf::Vector2f pos);
	void setDirection(Direction dir);

	void draw(sf::RenderWindow& window);
	void move(float deltaTime);

	//virtual void move(float deltaTime) = 0;
//	void move(Controller& controller) {};

	void createBody(b2World* world);
	
	

protected:
	sf::Sprite m_icon; //Tali: Move to GameObjects? then will have to make access functions
	
	//---- simha: Move to game object -----
	b2Body* m_body = nullptr;	
	float getWidth();
	float getHeight();
	sf::Vector2f getPosition();
	//-------------------------------------
	 
	
	//sf::Vector2f m_direction;

	float m_speedPerSecond = BASE_SPEED;

	Direction m_direction;
	b2Vec2 getDirection(Direction dir);

};