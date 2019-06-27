#pragma once

#include "Canvas.h"

class Brush
{
protected:
	sf::Color drawingColor{sf::Color::Black};
public:
	~Brush() = default;

	virtual void setColor(sf::Color color) = 0;
	virtual void startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) = 0;
	virtual void dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition) = 0;
	virtual void endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) = 0;
};



