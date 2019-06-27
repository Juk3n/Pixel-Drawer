#include "Pen.h"

void Pen::setColor(sf::Color color)
{
	drawingColor = color;
}

void Pen::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, drawingColor);
}

void Pen::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, drawingColor);
}

void Pen::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition) 
{
}
