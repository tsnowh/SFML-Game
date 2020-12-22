#include "controller.h"

Controller::Controller() {}

void Controller::Gameloop() {
    sf::Event event;

    int x = 250;
    int y = 250;

    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
    shape.setOrigin (250, 250);


    while (model.getDisplay()->getWindow().isOpen()) {
        while (model.getDisplay()->getWindow().pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    model.getDisplay()->getWindow().close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::W) {
                        y -= 20;
                    }
                    if (event.key.code == sf::Keyboard::S) {
                        y += 20;
                    }
                    if (event.key.code == sf::Keyboard::D) {
                        x += 20;
                    }
                    if (event.key.code == sf::Keyboard::A) {
                        x -= 20;
                    }
                    break;

                default:
                    break;
            }

            shape.setPosition(x, y);

            model.getDisplay()->getWindow().clear();
            model.getDisplay()->getWindow().draw(shape);
            model.getDisplay()->getWindow().display();
        }
    }
}
