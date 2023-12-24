#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	int w, h;
	w = 400;
	h = 400;
	RenderWindow window(VideoMode(w, h), "Win");

	ConvexShape convex;
	convex.setPointCount(4);
	convex.setFillColor(sf::Color(100, 250, 50));

	convex.setPoint(0, Vector2f{ 5, 0});
	convex.setPoint(1, Vector2f{ 15, 0});
	convex.setPoint(2, Vector2f{ 0, 10});
	convex.setPoint(3, Vector2f{ 20, 10});














	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		window.display();
	}
	return 0;
}
