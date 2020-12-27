#ifndef __PHYSICS_H__
#define __PHYSICS_H__

#include <SFML/Graphics.hpp>

class Enemy;

float distance(const sf::Vector2f&);

sf::Vector2f normalize(const sf::Vector2f&);

bool collision(Enemy *, Enemy *);

#endif

