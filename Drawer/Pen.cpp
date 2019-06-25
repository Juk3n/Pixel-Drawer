#include "Pen.h"

void Pen::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) 
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, sf::Color::Black);
}

void Pen::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, sf::Color::Black);
}

void Pen::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) 
{
}
