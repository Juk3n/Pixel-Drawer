#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

class Button
{
private:
	sf::Sprite sprite{};
	sf::Texture texture{};
	float buttonSize{ 50 };

public:
	Button(std::string fileName, int x, int y)
	{		
		texture.loadFromFile(fileName, sf::IntRect(0, 0, buttonSize, buttonSize));
		sprite.setTexture(texture);
		sprite.setPosition(float(x), float(y));
	}

	void onClick(){}

	bool isMouseOnButton(sf::Vector2i mousePosition)
	{
		if (mousePosition.x >= sprite.getPosition().x && mousePosition.x <= (sprite.getPosition().x + buttonSize))
		{
			if (mousePosition.y >= sprite.getPosition().y && mousePosition.y <= (sprite.getPosition().y + buttonSize))
			{
				return true;
			}
		}
		return false;
	}

	sf::Sprite getSprite()
	{
		return sprite;
	}

	~Button() {}
};



