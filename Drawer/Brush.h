#pragma once

#include "Canvas.h"

class Brush
{
public:
	~Brush() = default;

	virtual void startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) = 0;
	virtual void dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition) = 0;
	virtual void endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) = 0;
};



