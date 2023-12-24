#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    int WINDOW_WIDTH = 800;
    int WINDOW_HEIGHT = 600;

    int height = 0;
    int lower = 0;
    int higher = 0;

    int r = 0;
    int g = 0;
    int b = 0;

    std::cin >> height >> lower >> higher >> r >> g >> b;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "AAAA");
    
    sf::ConvexShape convex;

    convex.setPointCount(4);
    convex.setPoint(0, sf::Vector2f(50 + (lower - higher) / 2, 50));
    convex.setPoint(1, sf::Vector2f(50 + (lower - higher) / 2 + higher, 50));
    convex.setPoint(2, sf::Vector2f(50 + lower, 50 + height));
    convex.setPoint(3, sf::Vector2f(50, 50 + height));

    convex.setFillColor(sf::Color(r, g, b));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(convex);
        window.display();
    }
    return 0;
}
