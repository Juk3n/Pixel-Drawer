#pragma once

#include <SFML/Graphics.hpp>

class Button
{
	sf::RectangleShape shape{};
	float buttonSize{ 50 };
	bool isClicked{ false };
public:
	Button(int x, int y) 
	{
		shape.setPosition(float(x), float(y));
		shape.setFillColor(sf::Color::Blue);
		shape.setSize(sf::Vector2f(buttonSize, buttonSize));
	}

	bool isCLicked()
	{
		return isClicked;
	}

	sf::RectangleShape getShape()
	{
		return shape;
	}

	~Button() {}
};



