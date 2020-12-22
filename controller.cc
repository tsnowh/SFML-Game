#include "controller.h"
#include <iostream>

Controller::Controller() {}

void Controller::Gameloop() {
    sf::Event event;

    std::unique_ptr<Zombie> z;
    z = std::make_unique<Zombie>(rand() % 500, rand() % 500);

    model.addZombie(z.get());

    while (model.getDisplay()->getWindow().isOpen()) {
        while (model.getDisplay()->getWindow().pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    model.getDisplay()->getWindow().close();
                    break;

                case sf::Event::KeyPressed:
                    KeyPressedHandler(event);
                    break;

                default:
                    break;
            }
        }
        model.getDisplay()->getWindow().clear();
        model.drawZombies();
        model.getDisplay()->getWindow().draw(model.getPlayer()->draw());
        model.getDisplay()->getWindow().display();
    }
}

void Controller::KeyPressedHandler(sf::Event &e) {
    if (e.key.code == sf::Keyboard::W) {
        model.getPlayer()->setY(model.getPlayer()->getY() - 20);
        std::cout << model.getPlayer()->getY() << std::endl;
    }
    if (e.key.code == sf::Keyboard::S) {
        model.getPlayer()->setY(model.getPlayer()->getY() + 20);
        std::cout << model.getPlayer()->getY() << std::endl;
    }
    if (e.key.code == sf::Keyboard::D) {
        model.getPlayer()->setX(model.getPlayer()->getX() + 20);
        std::cout << model.getPlayer()->getX() << std::endl;
    }
    if (e.key.code == sf::Keyboard::A) {
        model.getPlayer()->setX(model.getPlayer()->getX() - 20);
        std::cout << model.getPlayer()->getX() << std::endl;
    }
}
