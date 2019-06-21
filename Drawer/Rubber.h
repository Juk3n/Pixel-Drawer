#pragma once

#include "Brush.h"

class Rubber : public Brush
{
public:
	void draw(sf::RectangleShape & pixel) const override;
};

