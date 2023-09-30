#pragma once

#include <vector>

namespace InkBall::World {

    struct Coordinate {
        int x;
        int y;

        Coordinate() : x(0), y(0) {}
        Coordinate(int x, int y) : x(x), y(x) {}
        std::vector<Coordinate> getNeighborhood();
    };

}