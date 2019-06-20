#pragma once

#include "Brush.h"

class Parabola : public Brush
{
public:
	void draw(sf::RectangleShape & pixel) const override;
};

