#include "Application.h"

bool Application::isPressed(Button & button)
{
	return (button.isPressed(mouse.isLeftButtonClicked(), mouse.getPosition()) && canPress);
}

Application::Application(std::string title, int height, int width) : window_Title(title), window_height(height), window_width(width)
{ 
}

void Application::run()
{
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), window_Title);
	
	while (window.isOpen())
	{
		mouse.refreshMouse(window);

		if (mouse.isLeftButtonClicked() && canPress && canvas.isMouseOnCanvas(mouse.getPosition()))
		{
			actualBrush->startDrawing(canvas, mouse.getPosition());
			canPress = false;
		}

		if (mouse.isLeftButtonClicked() && mouse.isDragging() && canvas.isMouseOnCanvas(mouse.getPosition()))
		{
			actualBrush->dragDrawing(canvas, mouse.getPosition());
		}

		if (isPressed(buttonPen))
		{
			actualBrush = factory.create(BrushFactory::BrushStrategy::Pen);
			canPress = false;
		}

		if (isPressed(buttonThickPen))
		{
			actualBrush = factory.create(BrushFactory::BrushStrategy::ThickPen);
			canPress = false;
		}

		if (isPressed(buttonRubber))
		{
			actualBrush = factory.create(BrushFactory::BrushStrategy::Rubber);
			canPress = false;
		}

		if (isPressed(buttonLine))
		{
			actualBrush = factory.create(BrushFactory::BrushStrategy::Line);
			canPress = false;
		}

		if (isPressed(buttonSave))
		{
			canvas.getSaveImage().saveToFile("image.png");
			canPress = false;
		}

		if (isPressed(buttonRedDye))
		{
			actualBrush->setColor(sf::Color::Red);
			canPress = false;
		}

		if (isPressed(buttonBlueDye))
		{
			actualBrush->setColor(sf::Color::Blue);
			canPress = false;
		}

		if (isPressed(buttonBlackDye))
		{
			actualBrush->setColor(sf::Color::Black);
			canPress = false;
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (canvas.isMouseOnCanvas(mouse.getPosition()))
				{
					actualBrush->endDrawing(canvas, mouse.getPosition());
				}
				
				canPress = true;
			}
		}

		window.clear();
		
		window.draw(canvas.getSprite());		
		window.draw(buttonPen.getSprite());
		window.draw(buttonThickPen.getSprite());
		window.draw(buttonRubber.getSprite());
		window.draw(buttonLine.getSprite());
		window.draw(buttonParabla.getSprite());
		window.draw(buttonSave.getSprite());
		window.draw(buttonLoad.getSprite());
		window.draw(buttonRedDye.getSprite());
		window.draw(buttonBlueDye.getSprite());
		window.draw(buttonBlackDye.getSprite());
		
		window.display();
	}
}


