#pragma once

#include "SFML/Graphics.hpp"

#include <vector>

class Canvas
{
	int canvasWidth{};
	int canvasHeight{};

	sf::Image image{};
	sf::Texture texture{};
	sf::Sprite sprite{};
	
public:
	Canvas(int width, int height, sf::Color startColor);

	bool isMouseOnCanvas(sf::Vector2i mousePosition);

	void drawPixel(int x, int y, sf::Color color);
	void drawLine(int x1, int y1, int x2, int y2, sf::Color color);

	sf::Image getSaveImage();
	sf::Sprite getSprite();
};

