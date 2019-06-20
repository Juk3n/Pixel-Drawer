#pragma once

#include "Brush.h"

class NullBrush : public Brush
{
public:
	//null object does nothing
	void draw(sf::RectangleShape & pixel) const override;
};

