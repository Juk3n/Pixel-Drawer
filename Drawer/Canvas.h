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
	bool isMouseOnDrawingPanel(sf::Vector2i mousePosition);
public:
	Canvas(int width, int height);

	void drawPixel(int x, int y);
	void drawLine(int x1, int y1, int x2, int y2);

	std::vector<sf::RectangleShape> getPixels();
};

