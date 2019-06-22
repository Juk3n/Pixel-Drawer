#include "Application.h"

bool Application::isMouseOnDrawingPanel(sf::Vector2i mousePosition)
{
	if (mousePosition.x >= 0 && mousePosition.y >= 0)
	{
		if (mousePosition.x < drawing_panel_width && mousePosition.y < drawing_panel_height)
		{
			return true;
		}
	}
	return false;
}

Application::Application(std::string title, int height, int width) : window_Title(title), window_height(height), window_width(width)
{ 
}

void Application::run()
{
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), window_Title);
	
	bool canPress{ true };
	sf::Mouse mouse{};

	while (window.isOpen())
	{
		sf::Vector2i mousePosition{ mouse.getPosition(window) };

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

		window.display();
	}
}


