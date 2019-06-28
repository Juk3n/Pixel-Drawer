#include "ThickPen.h"

void ThickPen::setColor(sf::Color color)
{
	drawingColor = color;
}

void ThickPen::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, drawingColor);
	canvas.drawPixel(pixelPosition.x - 1, pixelPosition.y, drawingColor);
	canvas.drawPixel(pixelPosition.x + 1, pixelPosition.y, drawingColor);
	canvas.drawPixel(pixelPosition.x, pixelPosition.y - 1, drawingColor);
	canvas.drawPixel(pixelPosition.x, pixelPosition.y + 1, drawingColor);
	canvas.drawPixel(pixelPosition.x - 1, pixelPosition.y - 1, drawingColor);
	canvas.drawPixel(pixelPosition.x - 1, pixelPosition.y + 1, drawingColor);
	canvas.drawPixel(pixelPosition.x + 1, pixelPosition.y - 1, drawingColor);
	canvas.drawPixel(pixelPosition.x + 1, pixelPosition.y + 1, drawingColor);
}

void ThickPen::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	canvas.drawPixel(pixelPosition.x, pixelPosition.y, drawingColor);
	canvas.drawPixel(pixelPosition.x - 1, pixelPosition.y, drawingColor);
	canvas.drawPixel(pixelPosition.x + 1, pixelPosition.y, drawingColor);
	canvas.drawPixel(pixelPosition.x, pixelPosition.y - 1, drawingColor);
	canvas.drawPixel(pixelPosition.x, pixelPosition.y + 1, drawingColor);
	canvas.drawPixel(pixelPosition.x - 1, pixelPosition.y - 1, drawingColor);
	canvas.drawPixel(pixelPosition.x - 1, pixelPosition.y + 1, drawingColor);
	canvas.drawPixel(pixelPosition.x + 1, pixelPosition.y - 1, drawingColor);
	canvas.drawPixel(pixelPosition.x + 1, pixelPosition.y + 1, drawingColor);
}

void ThickPen::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
}
