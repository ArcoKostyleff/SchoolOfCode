using namespace std;
#include <iostream>;
#include <SFML/Graphics.hpp>

int main()
{
    float w1, w2, h;
    cin >> w1 >> w2 >> h;
    sf::RenderWindow window(sf::VideoMode(800, 800), "1");
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, sf::Vector2f{0,h});
    convex.setPoint(1, sf::Vector2f{(w2-w1)/2 ,0});
    convex.setPoint(2, sf::Vector2f{((w2 - w1) / 2) + w1,0});
    convex.setPoint(3, sf::Vector2f{w2,h});
    
    window.draw(convex);
    window.display();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
