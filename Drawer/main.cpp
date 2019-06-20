#include <SFML/Graphics.hpp>

#include "Button.h"

#include <iostream>

static int window_height{ 550 };
static int window_width{ 500 };

static int drawing_panel_width{ 500 };
static int drawing_panel_height{ 500 };

static int graphicPixelSize{ 10 };

int main()
{
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Drawer");

	Button buttonTest{ 0, 500 };
	Button buttonTest1{ 50, 500 };

	std::vector<sf::RectangleShape> shapes;

	std::vector<sf::Vector2i> parabolaPoints;
	bool canPress{ true };
	sf::Mouse mouse{};

	for (int y = 0; y < drawing_panel_height; y += 10)
	{
		for (int x = 0; x < drawing_panel_width; x += 10)
		{
			sf::RectangleShape shape{ sf::Vector2f(float(graphicPixelSize), float(graphicPixelSize)) };
			shape.setPosition(sf::Vector2f((float)x, (float)y));

			shape.setFillColor(sf::Color::White);

			shapes.push_back(shape);
		}
	}


	while (window.isOpen())
	{
		sf::Vector2i mousePosition{ mouse.getPosition(window) };

		if (mouse.isButtonPressed(sf::Mouse::Left))
		{
			if (mousePosition.x >= 0 && mousePosition.y >= 0)
			{
				if (mousePosition.x < drawing_panel_width && mousePosition.y < drawing_panel_height)
				{
					mousePosition /= graphicPixelSize;

					shapes[(50 * mousePosition.y) + mousePosition.x].setFillColor(sf::Color::Red);
				}
			}		
		}

		if (mouse.isButtonPressed(sf::Mouse::Right) && canPress)
		{
			canPress = false;

			if (mousePosition.x >= 0 && mousePosition.y >= 0)
			{
				if (mousePosition.x < drawing_panel_width && mousePosition.y < drawing_panel_height)
				{
					mousePosition /= graphicPixelSize;

					shapes[(50 * mousePosition.y) + mousePosition.x].setFillColor(sf::Color::Black);
					parabolaPoints.push_back(sf::Vector2i(mousePosition.x, mousePosition.y));
					
					if (parabolaPoints.size() == 3)
					{
						sf::Vector2i A{ parabolaPoints[0] };
						sf::Vector2i B{ parabolaPoints[1] };
						sf::Vector2i C{ parabolaPoints[2] };

						for (float t = 0; t <= 1; t += 0.02f)
						{
							sf::Vector2i Q{ (int)((1 - t)*A.x + t * B.x), (int)((1 - t)*A.y + t * B.y) };
							sf::Vector2i R{ (int)((1 - t)*B.x + t * C.x), (int)((1 - t)*B.y + t * C.y) };
							sf::Vector2i P{ (int)((1 - t)*Q.x + t * R.x), (int)((1 - t)*Q.y + t * R.y) };

							shapes[(50 * P.y) + P.x].setFillColor(sf::Color::Black);
						}

						parabolaPoints.clear();
					}
				}
			}
		}

		if (buttonTest.isMouseOnButton(mousePosition) && mouse.isButtonPressed(sf::Mouse::Left) && canPress)
		{
			canPress = false;
			std::cout << "button clicked" << std::endl;
		}

		if (buttonTest1.isMouseOnButton(mousePosition) && mouse.isButtonPressed(sf::Mouse::Left) && canPress)
		{
			canPress = false;
			std::cout << "button1 clicked" << std::endl;
		}
		
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased)
			{
				canPress = true;
			}
		}


		window.clear();
		window.draw(buttonTest.getShape());
		window.draw(buttonTest1.getShape());
		for (sf::RectangleShape shape : shapes)
		{
			window.draw(shape);
		}
		window.display();
	}

	return 0;

}

