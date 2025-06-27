#pragma once
#include "stdafx.h"
#include "Defines.h"
class Utils
{
public:
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins origin);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins origin);
};

