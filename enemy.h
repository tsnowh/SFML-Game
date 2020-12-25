#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SFML/Graphics.hpp>

enum State {Alive, Dead};

class Weapon;
class Projectile;

class Enemy {
  private:
    State state;
    int health;
    sf::Vector2f position;
    float speed;
    int attackRange;
  public:
    Enemy(int h, sf::Vector2f pos, float speed, int attackRange, State = State::Alive);
    virtual void getAttacked (Weapon *) = 0;
    virtual void attack (Enemy *) = 0;
    virtual void notify (Projectile *) = 0;
    virtual void reEvaluateState ();

    // getters / setters
    int getX();
    void setX(int);
    int getY();
    void setY(int);

    int getAttackRange();
    void setAttackRange(int);

    int getHealth();
    void setHealth(int);
    State getState();
    void setState(State);

    sf::Vector2f getPos();
    void setPos(sf::Vector2f);
    float getSpeed();
    void setSpeed(float);
};


#endif
