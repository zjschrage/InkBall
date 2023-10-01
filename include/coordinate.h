#pragma once

#include <vector>

namespace InkBall::World {

    struct Coordinate {
        int x;
        int y;

        Coordinate() : x(0), y(0) {}
        Coordinate(int x, int y) : x(x), y(y) {}
        std::vector<Coordinate> getNeighborhood();
    };

    sf::Vector2<int> coordinateToPosition(Coordinate c);
    Coordinate positionToCoordinate(sf::Vector2<int> c);

}