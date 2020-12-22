#include "controller.h"
#include <iostream>

Controller::Controller() {}

void Controller::Gameloop() {
    sf::Event event;

    while (model.getDisplay()->getWindow().isOpen()) {
        while (model.getDisplay()->getWindow().pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    model.getDisplay()->getWindow().close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::W) {
                        model.getPlayer()->setY(model.getPlayer()->getY() - 20);
                        std::cout << model.getPlayer()->getY() << std::endl;
                    }
                    if (event.key.code == sf::Keyboard::S) {
                        model.getPlayer()->setY(model.getPlayer()->getY() + 20);
                        std::cout << model.getPlayer()->getY() << std::endl;
                    }
                    if (event.key.code == sf::Keyboard::D) {
                        model.getPlayer()->setX(model.getPlayer()->getX() + 20);
                        std::cout << model.getPlayer()->getX() << std::endl;
                    }
                    if (event.key.code == sf::Keyboard::A) {
                        model.getPlayer()->setX(model.getPlayer()->getX() - 20);
                        std::cout << model.getPlayer()->getX() << std::endl;
                    }
                    break;

                default:
                    break;
            }

            model.getDisplay()->getWindow().clear();
            model.getDisplay()->getWindow().draw(model.getPlayer()->draw());
            model.getDisplay()->getWindow().display();
        }
    }
}
