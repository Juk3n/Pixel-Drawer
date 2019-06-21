#include "Parabola.h"

void Parabola::draw(sf::RectangleShape & pixel) const
{
	//magic happens
	//pixel.setFillColor(sf::Color::Black);

	/*parabolaPoints.push_back(sf::Vector2i(mousePosition.x, mousePosition.y));

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

		parabolaPoints.clear();*/
}
