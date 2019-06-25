#pragma once

#include "SFML/Graphics.hpp"

#include <vector>

class Canvas
{
	int canvasWidth{};
	int canvasHeight{};

	std::vector<sf::RectangleShape> Pixels{};
	int pixelSize{10};

	void fillLine(int y);
	
public:
	Canvas(int width, int height);

	bool isMouseOnCanvas(sf::Vector2i mousePosition);

	void drawPixel(int x, int y, sf::Color color);
	void drawLine(int x1, int y1, int x2, int y2, sf::Color color);

	std::vector<sf::RectangleShape> getPixels();
};
