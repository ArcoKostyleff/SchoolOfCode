#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
int main()
{
        sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
    sf::SoundBuffer buffer;
    // load something into the sound buffer...

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    sf::RectangleShape box0(sf::Vector2f(1000, 100));
    box0.setPosition(sf::Vector2f(0, 0));
    box0.setFillColor(sf::Color::White);   
    sf::RectangleShape box1(sf::Vector2f(1000, 100));
    box1.setPosition(0, 100);
    box1.setFillColor(sf::Color::Blue);
    sf::RectangleShape box2(sf::Vector2f(1000, 100));
    box2.setPosition(0, 200);
    box2.setFillColor(sf::Color::Red);
    sf::RectangleShape box3(sf::Vector2f(300, 0));
    sf::Texture putInTexture;
    if (!putInTexture.loadFromFile("Широкий_Путин_идёт.jpg"/*, sf::IntRect(0, 400, 500, 500)*/))
    {
        std::cout << "putin ne vlez\n";
    }
    
    sf::Sprite putIn;
   
    putIn.setTexture(putInTexture);
    putIn.setScale(0.7, 0.7);
    //putIn.setTextureRect(sf::IntRect(0, 0, 1000, 500));
    putIn.setPosition(sf::Vector2f(0, 300));
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);


        window.draw(box0);
        window.draw(box1);
        window.draw(box2);
       window.draw(putIn);
        window.display();
    }

    return 0;
}
