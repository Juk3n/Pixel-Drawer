#pragma once

#include "SFML/Graphics.hpp"

class UserMouse
{
	bool dragging{};
	sf::Mouse mouse{};
	sf::Vector2i position{};
public:
	UserMouse() {}

	void refreshMouse(sf::RenderWindow & window)
	{
		position = mouse.getPosition(window);
		if (isLeftButtonClicked())
		{
			dragging = true;
		}
		else 
		{
			dragging = false;
		}
	}

	sf::Vector2i getPosition() { return position; }

	bool isDragging()
	{
		return dragging;
	}

	bool isLeftButtonClicked()
	{
		return mouse.isButtonPressed(sf::Mouse::Button::Left);
	}


	~UserMouse() {}
};
