#include "Line.h"

#include <iostream>

void Line::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) 
{
	beginPixel = pixelPosition;
	lastPixel = pixelPosition;
}

void Line::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawLine(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, sf::Color::White);
	canvas.drawLine(beginPixel.x, beginPixel.y, pixelPosition.x, pixelPosition.y, sf::Color::Color(80,80,80,255));
	lastPixel = pixelPosition;
}

void Line::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawLine(beginPixel.x, beginPixel.y, pixelPosition.x, pixelPosition.y, sf::Color::Black);
}
