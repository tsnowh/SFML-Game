#include "physics.h"
#include "cmath"

#include "enemy.h"

float pi = 3.14159274101257324219;

float distance(const sf::Vector2f& source) {
    return sqrt((source.x * source.x) + (source.y * source.y));
}

sf::Vector2f normalize(const sf::Vector2f& source) {
    float length = distance(source);
    if (length != 0) {
        return sf::Vector2f(source.x / length, source.y / length);
    } else {
        return source;
    }
}

float getAngle(sf::Vector2f v1, sf::Vector2f v2) {
    return (acos((v1.x * v2.x + v1.y * v2.y)/((sqrt(v1.x*v1.x + v1.y*v1.y) * sqrt(v2.x*v2.x + v2.y*v2.y))))/pi*180);
}

bool collision(Enemy *e1, Enemy *e2) {
    if (e1 == nullptr || e2 == nullptr) throw;
    if (distance(e1->getPos() - e2->getPos()) <= e1->getRadius() + e2->getRadius()) {
        return true;
    } else {
        return false;
    }
}
