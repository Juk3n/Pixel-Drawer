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

void Canvas::drawParabola(int x1, int y1, int x2, int y2, int parx, int pary, sf::Color color)
{
	sf::Vector2i A{ x1, y1 };
	sf::Vector2i B{ parx, pary };
	sf::Vector2i C{ x2, y2 };

	for (float t = 0; t <= 1; t += 0.02f)
	{
		sf::Vector2i Q{ (int)((1 - t)*A.x + t * B.x), (int)((1 - t)*A.y + t * B.y) };
		sf::Vector2i R{ (int)((1 - t)*B.x + t * C.x), (int)((1 - t)*B.y + t * C.y) };
		sf::Vector2i P{ (int)((1 - t)*Q.x + t * R.x), (int)((1 - t)*Q.y + t * R.y) };

		drawPixel(P.x, P.y, color);
	}
}

void Canvas::setImage(sf::Image image)
{
	this->image = image;
}

sf::Image Canvas::getSaveImage()
{
	return image;
}

sf::Sprite Canvas::getSprite()
{
	return sprite;
}


