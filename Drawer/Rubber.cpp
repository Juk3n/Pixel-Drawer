#include "Rubber.h"

void Rubber::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, sf::Color::White);
}

void Rubber::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, sf::Color::White);
}

void Rubber::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
}
