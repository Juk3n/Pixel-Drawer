#include "Line.h"

#include <iostream>

void Line::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition) 
{
	beginPixel = pixelPosition;
	std::cout << "pixelPosition: x: " << pixelPosition.x << std::endl;
	std::cout << "beginPixel: x: " << beginPixel.x << std::endl;
}

void Line::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{

}

void Line::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawLine(beginPixel.x, beginPixel.y, pixelPosition.x, pixelPosition.y);
}
