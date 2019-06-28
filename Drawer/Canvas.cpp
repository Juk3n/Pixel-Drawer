#include "Canvas.h"

bool Canvas::isMouseOnCanvas(sf::Vector2i mousePosition)
{
	return (mousePosition.x < canvasWidth && mousePosition.y < canvasHeight && mousePosition.x >= 0 && mousePosition.y >= 0);
}

Canvas::Canvas(int width, int height, sf::Color startColor) : canvasWidth(width), canvasHeight(height)
{
	image.create(500, 500, sf::Color::White);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}

void Canvas::drawPixel(int x, int y, sf::Color color)
{
	image.setPixel(x, y, color);

	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
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

sf::Image Canvas::getSaveImage()
{
	return image;
}

sf::Sprite Canvas::getSprite()
{
	return sprite;
}


