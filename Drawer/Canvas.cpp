#include "Canvas.h"

void Canvas::fillLine(int y)
{
	for (int x = 0; x < canvasWidth; x += pixelSize)
	{
		sf::RectangleShape pixel{ sf::Vector2f(pixelSize, pixelSize) };
		pixel.setPosition(x, y);
		Pixels.push_back(pixel);
	}
}

bool Canvas::isMouseOnCanvas(sf::Vector2i mousePosition)
{
	return (mousePosition.x < canvasWidth && mousePosition.y < canvasHeight && mousePosition.x >= 0 && mousePosition.y >= 0);
}

Canvas::Canvas(int width, int height) : canvasWidth(width), canvasHeight(height)
{
	for (int y = 0; y < canvasHeight; y+= pixelSize)
	{
		fillLine(y);		
	}
}

void Canvas::drawPixel(int x, int y, sf::Color color)
{
	Pixels[y * canvasWidth / pixelSize + x].setFillColor(color);
}

void Canvas::drawLine(int x1, int y1, int x2, int y2, sf::Color color)
{
	int accuracy{ 100 };
	x1 *= accuracy;
	x2 *= accuracy;
	y1 *= accuracy;
	y2 *= accuracy;
	for (int t = 1; t <= accuracy; t++)
	{
		int x = (accuracy - t)*x1 + t*x2;
		int y = (accuracy - t)*y1 + t*y2;
		drawPixel(x / accuracy / accuracy, y / accuracy / accuracy, color);
	}
}

std::vector<sf::RectangleShape> Canvas::getPixels()
{
	return Pixels;
}
