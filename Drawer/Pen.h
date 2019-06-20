#pragma once

#include "Brush.h"

class Pen : public Brush
{
public:
	void draw(sf::RectangleShape & pixel) const override;
};

