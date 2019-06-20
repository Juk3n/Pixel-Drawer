#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

class Button
{
private:
	sf::RectangleShape shape{};
	float buttonSize{ 50 };
public:
	Button(int x, int y) 
	{
		shape.setPosition(float(x), float(y));
		shape.setSize(sf::Vector2f(buttonSize, buttonSize));


		sf::Texture texture{};
		texture.create(50, 50);
		if (!texture.loadFromFile("iconTest.png"))
		{
			std::cout << "texture problem" << std::endl;
		}
		shape.setTextureRect(sf::IntRect(0, 0, 50, 50));
		shape.setTexture(&texture);
		
		
	}

	void onClick(){}

	bool isMouseOnButton(sf::Vector2i mousePosition)
	{
		if (mousePosition.x >= shape.getPosition().x && mousePosition.x <= (shape.getPosition().x + buttonSize))
		{
			if (mousePosition.y >= shape.getPosition().y && mousePosition.y <= (shape.getPosition().y + buttonSize))
			{
				return true;
			}
		}
		return false;
	}

	sf::RectangleShape getShape()
	{
		return shape;
	}

	~Button() {}
};



