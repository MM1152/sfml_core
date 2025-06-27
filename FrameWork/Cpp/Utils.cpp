#include "stdafx.h"
#include "Utils.h"

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins origin)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width , rect.height);

	newOrigin.x *= ((int)origin % 3) * 0.5f;
	newOrigin.y *= ((int)origin / 3) * 0.5f;

	obj.setOrigin(newOrigin);

	return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins origin)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= ((int)origin % 3) * 0.5f;
	newOrigin.y *= ((int)origin / 3) * 0.5f;

	obj.setOrigin(newOrigin);

	return newOrigin;
}
