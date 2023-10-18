#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Utils {

    template <typename T, typename std::enable_if_t<std::is_arithmetic_v<T>>>
    double distance(const sf::Vector2<T>& v1, const sf::Vector2<T>& v2);

    double distance(const sf::Vector2<int>& v1, const sf::Vector2<int>& v2);

    double distance(const sf::Vector2f& v1, const sf::Vector2f& v2);
    
}