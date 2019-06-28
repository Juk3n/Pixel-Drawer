#pragma once
#include "Brush.h"
class Parabola : public Brush
{
	sf::Vector2i beginPixel;
	sf::Vector2i lastPixel;
	sf::Vector2i parabolaPixel;

	int stage{};
	void nextStage();

public:
	void setColor(sf::Color color) override;
	void startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
	void dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
	void endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) override;
};

