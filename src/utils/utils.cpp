#include "utils.h"

namespace InkBall::Utils {

    double distance(sf::Vector2<int> v1, sf::Vector2<int> v2) {
        return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
    }

}