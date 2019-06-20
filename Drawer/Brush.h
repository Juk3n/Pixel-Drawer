#pragma once

#include <SFML/Graphics.hpp>

class Brush
{
public:
	virtual void draw(sf::RectangleShape & pixel) const = 0;

	virtual ~Brush() = default;
};


