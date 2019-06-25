#pragma once
#include "Brush.h"
class Pen : public Brush
{
public:
	void startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
	void dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
	void endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
};

