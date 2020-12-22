#include "display.h"

Display::Display() {
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(200, 200), "SFML works!");
}

sf::RenderWindow * Display::getWindow() {
    return window.get();
}

/*
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

*/
