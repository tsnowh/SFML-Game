#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include "weapon.h"

class Model;

class Zombie: public Enemy {
  private:
    Weapon weapon;
    Model *model;
    int radius;
  public:
    Zombie(Model *, sf::Vector2f pos, float speed, int damage, float attackDelay);
    void getAttacked (Weapon *, bool = true) override;
    void attack (Enemy *, bool = true) override;
    void reEvaluateState () override;
    void notify (Projectile *) override;
    float getRadius() override;

    //sf::Sprite draw() override;
    //sf::Sprite getSprite() override;
};


#endif
