#include "physics.h"
#include "cmath"

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
