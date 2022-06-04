#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Macros.h"
#include "Utilities.h"
#include "box2d/box2d.h"



class GameObjects
{
public:
    GameObjects();
    //GameObjects(b2World* world, b2BodyType bodyType);
    virtual ~GameObjects() = default;

    void draw(sf::RenderWindow& window);

    sf::Vector2f  convertB2VecToVec2f(b2Vec2 vec2f) const;
    sf::Vector2f getPosition()const;
    virtual void setPosition(sf::Vector2f pos);
    float getWidth()const;
    float getHeight()const;
    void createBody(b2World* world, b2BodyType bodyType);

protected:
    b2Body* m_body = nullptr;
    b2Fixture* footSensor = nullptr;
    sf::Sprite m_icon;
};