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

	Canvas canvas{ 500, 500, sf::Color::White };

	UserMouse mouse{};

	Button buttonPen{ "Images//PenImage.png", 0, 500 };
	Button buttonThickPen{ "Images//ThickPenImage.png", 50, 500 };
	Button buttonRubber{ "Images//RubberImage.png", 100, 500 };
	Button buttonLine{ "Images//LineImage.png", 150, 500 };
	Button buttonParabola{ "Images//ParabolaImage.png", 200, 500 };
	Button buttonSave{ "Images//SaveImage.png", 250, 500 };
	Button buttonLoad{ "Images//LoadImage.png", 300, 500 };
	Button buttonRedDye{ "Images//RedDyeImage.png", 350, 500 };
	Button buttonBlueDye{ "Images//BlueDyeImage.png", 400, 500 };
	Button buttonBlackDye{ "Images//BlackDyeImage.png", 450, 500 };

	bool canPress{};

	bool isPressed(Button & button);

public:
	Application(std::string title, int height, int width);

	void run();
};

