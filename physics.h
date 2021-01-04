#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include <SFML/Graphics.hpp>

class Enemy;

extern float pi;

float distance(const sf::Vector2f&);

sf::Vector2f normalize(const sf::Vector2f&);

float getAngle(sf::Vector2f v1, sf::Vector2f v2);

bool collision(Enemy *, Enemy *);

#endif

