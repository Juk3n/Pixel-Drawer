#pragma once
#include "Brush.h"
class Line : public Brush
{
	sf::Vector2i beginPixel;
public:
	void startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
	void dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
	void endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
};

