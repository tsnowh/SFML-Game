#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Model;
class Weapon;
class Projectile;

class exception;

class Player: public Enemy {
  private:
    std::vector<std::unique_ptr<Projectile>> projectiles;
    Model *model;
    int killCount = 0;
    int radius;
    std::vector<sf::IntRect> frames_up;
    std::vector<sf::IntRect> frames_down;
    std::vector<sf::IntRect> frames_left;
    std::vector<sf::IntRect> frames_right;
    int framePos = 0;
    bool framePosUp = true;
    int maxFrame;
  public:
    Player(Model *, sf::Vector2f pos, float speed);
    void getAttacked (Weapon *, bool = true) override;
    void attack (Enemy *, bool = true) override;
    void reEvaluateState () override;
    void notify (Projectile *) override;
    float getRadius() override;

    void addProjectile(std::unique_ptr<Projectile>);
    void deleteProjectile(Projectile *);
    Projectile * getProjectile(int i);
    int getNumProjectiles();
    void shoot(sf::Vector2f mpos);
    void moveProjectiles();

    int getKillCount();
    void increaseKillCount();

    void nextFrame();

    //sf::Sprite draw() override;
    //sf::Sprite getSprite() override;
};


#endif
