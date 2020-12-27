#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include "weapon.h"

class Model;

class Zombie: public Enemy {
  private:
    sf::CircleShape shape;
    Weapon weapon;
    Model *model;
  public:
    Zombie(Model *, sf::Vector2f pos, float speed, int damage);
    void getAttacked (Weapon *) override;
    void attack (Enemy *) override;
    void reEvaluateState () override;
    void notify (Projectile *) override;
    float getRadius() override;

    sf::CircleShape draw();
};


#endif
