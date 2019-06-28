#include "Parabola.h"

void Parabola::nextStage()
{
	stage = (stage == 1)?0:(stage + 1);
}

void Parabola::setColor(sf::Color color)
{
	drawingColor = color;
}

void Parabola::startDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	if (stage == 0)
	{
		beginPixel = pixelPosition;
		lastPixel = pixelPosition;
	}
	else
	{
		canvas.drawLine(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, sf::Color::White);
		parabolaPixel = pixelPosition;
	}
}

void Parabola::dragDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	if (stage == 0)
	{
		canvas.drawLine(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, sf::Color::White);
		canvas.drawLine(beginPixel.x, beginPixel.y, pixelPosition.x, pixelPosition.y, sf::Color::Color(80, 80, 80, 255));
		lastPixel = pixelPosition;
	}
	else
	{
		canvas.drawParabola(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, parabolaPixel.x, parabolaPixel.y, sf::Color::White);
		canvas.drawParabola(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, pixelPosition.x, pixelPosition.y, sf::Color::Color(80, 80, 80, 255));
		parabolaPixel = pixelPosition;
	}
}

void Parabola::endDrawing(Canvas & canvas, sf::Vector2i pixelPosition)
{
	if (stage == 0)
	{
		canvas.drawLine(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, sf::Color::White);
		canvas.drawLine(beginPixel.x, beginPixel.y, pixelPosition.x, pixelPosition.y, drawingColor);
	}
	else
	{
		canvas.drawParabola(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, parabolaPixel.x, parabolaPixel.y, sf::Color::White);
		canvas.drawParabola(beginPixel.x, beginPixel.y, lastPixel.x, lastPixel.y, pixelPosition.x, pixelPosition.y, drawingColor);

	}

	nextStage();
}
