#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Canvas.h"

class Application
{
	sf::RenderWindow window{};

	std::string window_Title{};
	int window_height{};
	int window_width{};

public:
	Application(std::string title, int height, int width);

	void run();
};

