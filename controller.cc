#include "controller.h"

Controller::Controller() {}

void Controller::Gameloop() {
    sf::Event event;

    // while there are pending events...

    while (model.getDisplay()->getWindow().isOpen()) {
        while (model.getDisplay()->getWindow().pollEvent(event)) {

            sf::CircleShape shape(100.f);
            shape.setFillColor(sf::Color::Green);

            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    model.getDisplay()->getWindow().close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    break;

                // we don't process other types of events
                default:
                    break;
            }

            model.getDisplay()->getWindow().clear();
            model.getDisplay()->getWindow().draw(shape);
            model.getDisplay()->getWindow().display();
        }
    }
}
