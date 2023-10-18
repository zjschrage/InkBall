#include "utils.h"

namespace InkBall::Utils {

    template <typename T, typename std::enable_if_t<std::is_arithmetic_v<T>>>
    double distance(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2) {
        return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
    }

    double distance(const sf::Vector2<int>& v1, const sf::Vector2<int>& v2) {
        return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
    }

    double distance(const sf::Vector2f& v1, const sf::Vector2f& v2) {
        return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
    }

}