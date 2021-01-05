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
    std::vector<sf::IntRect> frames_up;
    std::vector<sf::IntRect> frames_down;
    std::vector<sf::IntRect> frames_left;
    std::vector<sf::IntRect> frames_right;
    int framePos = 0;
    bool framePosUp = true;
    int maxFrame;
  public:
    Zombie(Model *, sf::Vector2f pos, float speed, int damage, float attackDelay);
    void getAttacked (Weapon *, bool = true) override;
    void attack (Enemy *, bool = true) override;
    void reEvaluateState () override;
    void notify (Projectile *) override;
    float getRadius() override;

    void nextFrame();

    //sf::Sprite draw() override;
    //sf::Sprite getSprite() override;
};


#endif
