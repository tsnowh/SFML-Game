#include "controller.h"
#include <iostream>

Controller::Controller(int width, int height): width{width}, height{height}, model{Model{width, height}} {}

void Controller::Gameloop() {
    sf::Event event;

    //sf::Clock shoot_clock;
    sf::Clock zombie_clock;
    //sf::Time dt = clock.restart();

    /*
    sf::Sprite zombieSprite;
    sf::Texture texture;
    //texture.setSmooth(true);
    texture.loadFromFile("corona_cell.png");
    zombieSprite.setTexture(texture);
    */
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && model.getPlayer()->getAttackTime() >= model.getPlayer()->getAttackDelay()) { //shoot
            model.getPlayer()->shoot((sf::Vector2f)sf::Mouse::getPosition(model.getDisplay()->getWindow()));
            //shoot_clock.restart();
        }

        if (zombie_clock.getElapsedTime().asSeconds() > 3) {
            model.addZombie(std::make_unique<Zombie>(&model, sf::Vector2f(rand() % width, rand() % height), 0.5, 10, 1.0));
            zombie_clock.restart();
        }

        // make a render method (maybe in the display class)
        model.moveZombies();
        model.getDisplay()->getWindow().draw(model.getPlayer()->draw());
        model.drawZombies();
        model.getDisplay()->renderHealthBar();
        model.getDisplay()->displayKillCount();
        model.getPlayer()->moveProjectiles();
        model.drawProjectiles();
        model.getDisplay()->getWindow().display();
        //std::cout << model.getPlayer()->getHealth() << std::endl;
        if (model.getPlayer()->getState() == State::Dead) break;
    }
}

void Controller::KeyPressedHandler() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Move Up
        if ((model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1))).y <= 0.0) {
            model.getPlayer()->setPos(sf::Vector2f(model.getPlayer()->getPos().x, height)); // + sf::Vector2f(0, -1 * model.getPlayer()->getPos().y));
        } else {
            //model.getPlayer()->setY(model.getPlayer()->getY() - 1);
            model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1)));
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //Move Down
        if ((model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1))).y >= float(height)) {
            model.getPlayer()->setPos(sf::Vector2f(model.getPlayer()->getPos().x, 0.0));
        } else {
            //model.getPlayer()->setY(model.getPlayer()->getY() + 1);
            model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, 1)));
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //Move Right
        if ((model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1))).x >= float(width)) {
            model.getPlayer()->setPos(sf::Vector2f(0.0, model.getPlayer()->getPos().y));
        } else {
            //model.getPlayer()->setX(model.getPlayer()->getX() + 1);
            model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(1, 0)));
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Move Left
        if ((model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(0, -1))).x <= 0) {
            model.getPlayer()->setPos(sf::Vector2f(width, model.getPlayer()->getPos().y));
        } else {
            //model.getPlayer()->setX(model.getPlayer()->getX() - 1);
            model.getPlayer()->setPos(model.getPlayer()->getPos() + (model.getPlayer()->getSpeed() * sf::Vector2f(-1, 0)));
        }
    }
    //std::cout << model.getPlayer()->getX() << ", " << model.getPlayer()->getY() << std::endl;
}
