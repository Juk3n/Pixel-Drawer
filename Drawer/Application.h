#pragma once

#include <SFML/Graphics.hpp>

class Application
{
	sf::RenderWindow window{};

	std::string window_Title{};
	int window_height{};
	int window_width{};

	int drawing_panel_width{ 500 };
	int drawing_panel_height{ 500 };

	bool isMouseOnDrawingPanel(sf::Vector2i mousePosition);

public:
	Application(std::string title, int height, int width);

	void run();
};

