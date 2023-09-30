#pragma once

#include <vector>
#include <optional>

#include "entity.h"

namespace InkBall::World {

    struct Coordinate {
        int x;
        int y;

        Coordinate(int x, int y) : x(x), y(x) {}
        std::vector<Coordinate> getNeighborhood() {
            std::vector<Coordinate> coordinates;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    coordinates.push_back(Coordinate(x + i, y + j));
                }
            }
            return coordinates;
        }
    };

    class Tile {
    public:
        Tile();
    private:
        std::optional<Entities::Entity> _entity;
        Coordinate _coordinate;
    };

}