#include "physics.h"
#include "cmath"

#include "enemy.h"

float distance(const sf::Vector2f& source) {
    return sqrt((source.x * source.x) + (source.y * source.y));
}

sf::Vector2f normalize(const sf::Vector2f& source) {
    float length = distance(source);
    if (length != 0) {
        //std::cout << length << std::endl;
        return sf::Vector2f(source.x / length, source.y / length);
    } else {
        return source;
    }
}

bool collision(Enemy *e1, Enemy *e2) {
    if (e1 == nullptr || e2 == nullptr) throw;
    if (distance(e1->getPos() - e2->getPos()) <= e1->getRadius() + e2->getRadius()) {
        return true;
    } else {
        return false;
    }
}
