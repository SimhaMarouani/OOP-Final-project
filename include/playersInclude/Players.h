#pragma once
#include "GameObjects.h"


class Players : public GameObjects
{
public:
	Players();
	Players(Player type);

	void setPostition(sf::Vector2f pos);
	void setDirection(Direction dir);

	void draw(sf::RenderWindow& window);
	void move(float deltaTime);

	//---- simha: Move to game object -----
	void createBody(b2World* world /*, b2BodyType bodyType*/);
	sf::Vector2f getPosition();
	float getHeight();
	//-------------------------------------


protected: //Tali: why protected? need change all protected members in other classes as well
	sf::Sprite m_icon; //Tali: Move to GameObjects? then will have to make access functions
	
	//---- simha: Move to game object -----
	b2Body* m_body = nullptr;	
	float getWidth();
	//-------------------------------------
	 
	
	//sf::Vector2f m_direction;

	float m_speedPerSecond = BASE_SPEED;

	Direction m_direction;
	b2Vec2 getDirection(Direction dir);

};