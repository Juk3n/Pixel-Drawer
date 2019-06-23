#include "Application.h"

Application::Application(std::string title, int height, int width) : window_Title(title), window_height(height), window_width(width)
{ 
}

void Application::run()
{
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), window_Title);
	
	Canvas canvas{ 500, 500 };

	Button buttonPen{ "Images//PenImage.png", 0, 500 };
	Button buttonRubber{ "Images//RubberImage.png", 50, 500 };
	Button buttonLine{ "Images//LineImage.png", 100, 500 };

	bool canPress{ true };
	sf::Mouse mouse{};

	while (window.isOpen())
	{
		sf::Vector2i mousePosition{ mouse.getPosition(window) };
		
		bool isMouseClicked{ mouse.isButtonPressed(sf::Mouse::Button::Left) };

		if (isMouseClicked)
		{
			//canvas.drawPixel(mousePosition.x / 10, mousePosition.y / 10);
		}

		if (buttonPen.isPressed(isMouseClicked, mousePosition) && canPress)
		{
			canPress = false;
			std::cout << "pen";
		}

		if (buttonRubber.isPressed(isMouseClicked, mousePosition) && canPress)
		{
			canPress = false;
			std::cout << "rubber";
		}

		if (buttonLine.isPressed(isMouseClicked, mousePosition) && canPress)
		{
			canPress = false;
			std::cout << "line";
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

		for (auto pixel : canvas.getPixels()) window.draw(pixel);
		window.draw(buttonPen.getSprite());
		window.draw(buttonRubber.getSprite());
		window.draw(buttonLine.getSprite());
		
		
		window.display();
	}
}


