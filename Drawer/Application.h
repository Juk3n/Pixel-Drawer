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

	Canvas canvas{ 500, 500 };

	UserMouse mouse{};

	Button buttonPen{ "Images//PenImage.png", 0, 500 };
	Button buttonRubber{ "Images//RubberImage.png", 50, 500 };
	Button buttonLine{ "Images//LineImage.png", 100, 500 };
	bool canPress{};

	bool isPressed(Button & button);

public:
	Application(std::string title, int height, int width);

	void run();
};

