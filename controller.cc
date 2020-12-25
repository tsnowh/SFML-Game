#include "controller.h"
#include <iostream>

Controller::Controller(int width, int height): width{width}, height{height}, model{Model{width, height}} {}

void Controller::Gameloop() {
    sf::Event event;

    std::unique_ptr<Zombie> z;
    //std::unique_ptr<Zombie> z2;
    z = std::make_unique<Zombie>(sf::Vector2f(rand() % width, rand() % height), 0.5, 10);
    //z2 = std::make_unique<Zombie>(rand() % 500, rand() % 500);
    model.addZombie(z.get());
    //model.addZombie(z2.get());

    sf::Clock clock;
    sf::Time dt = clock.restart();

    model.drawZombies();
    model.getDisplay()->getWindow().draw(model.getPlayer()->draw());

    while (model.getDisplay()->getWindow().isOpen()) {

        while (model.getDisplay()->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                model.getDisplay()->getWindow().close();
                break;
            }
        }

        model.getDisplay()->getWindow().clear();

        KeyPressedHandler();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asSeconds() > 0.1) { //shoot
            model.getPlayer()->shoot();
            clock.restart();
        }   

        //if (dt.asSeconds() > 10000000000) {
            model.moveZombies();
           // dt = clock.restart();
        //}
        model.getDisplay()->getWindow().draw(model.getPlayer()->draw());
        model.drawZombies();
        model.getPlayer()->moveProjectiles();
        model.drawProjectiles();
        model.getDisplay()->getWindow().display();
    }
}

void Controller::KeyPressedHandler() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Move Up
        if ((model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1))).y <= 0.0) {
            model.getPlayer()->setPos(sf::Vector2f(model.getPlayer()->getPos().x, 0.0f)); // + sf::Vector2f(0, -1 * model.getPlayer()->getPos().y));
        } else {
            //model.getPlayer()->setY(model.getPlayer()->getY() - 1);
            model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1)));
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //Move Down
        if ((model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1))).y >= float(height)) {
            model.getPlayer()->setPos(model.getPlayer()->getPos() + sf::Vector2f(0, -1 * model.getPlayer()->getPos().y));
        } else {
            //model.getPlayer()->setY(model.getPlayer()->getY() + 1);
            model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, 1)));
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //Move Right
        //model.getPlayer()->setX(model.getPlayer()->getX() + 1);
        model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(1, 0)));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Move Left
        //model.getPlayer()->setX(model.getPlayer()->getX() - 1);
        model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(-1, 0)));
    }
    //std::cout << model.getPlayer()->getX() << ", " << model.getPlayer()->getY() << std::endl;
}
