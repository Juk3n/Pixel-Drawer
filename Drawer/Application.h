#pragma once

#include <SFML/Graphics.hpp>

#include "Mouse.h"
#include "Button.h"
#include "Canvas.h"
#include "Brush.h"
#include "BrushFactory.h"

class Application
{
	sf::RenderWindow window{};

	std::string window_Title{};
	int window_height{};
	int window_width{};

	const BrushFactory & factory{};
	std::unique_ptr<Brush> actualBrush{std::make_unique<Pen>(Pen())};

public:
	Application(std::string title, int height, int width);

	void run();
};

