#include "controller.h"

Controller::Controller() {}

void Controller::Gameloop() {
    sf::Event event;

    // while there are pending events...

    while (display.getWindow()->isOpen()) {
        while (display.getWindow()->pollEvent(event)) {

            sf::CircleShape shape(100.f);
            shape.setFillColor(sf::Color::Green);

            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    display.getWindow()->close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    break;

                // we don't process other types of events
                default:
                    break;
            }
            display.getWindow()->clear();
            display.getWindow()->draw(shape);
            display.getWindow()->display();
        }
    }
}
