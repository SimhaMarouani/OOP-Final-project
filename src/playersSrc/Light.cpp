#include "playersInclude/Light.h"

Light::Light()
	:Players(Player::Light)
{
}
//
//Light::Light(sf::Vector2f position/*, Board& board*/)
//	:Players(Player::Light)
//{
//}
Light::Light(b2World* world)
	: Players(Player::Light, world)
{
}
