#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SFML/Graphics.hpp>

enum State {Alive, Dead};

class Weapon;

class Enemy {
  private:
    State state;
    int health;
    sf::Vector2f position;
    float speed;
  public:
    Enemy(int h, sf::Vector2f pos, float speed, State = State::Alive);
    virtual void getAttacked (Weapon *);

    // getters / setters
    int getX();
    void setX(int);
    int getY();
    void setY(int);

    sf::Vector2f getPos();
    void setPos(sf::Vector2f);
    float getSpeed();
    void setSpeed(float);
};


#endif
