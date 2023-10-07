#include <SFML/Graphics.hpp>
#include "coordinate.h"
#include "constants.h"

namespace InkBall::World {

    std::vector<Coordinate> Coordinate::getNeighborhood() {
        std::vector<Coordinate> coordinates;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                Coordinate c = Coordinate(x + i, y + j);
                if (c.isInBounds())
                    coordinates.push_back(c);
            }
        }
        return coordinates;
    }

    bool Coordinate::isInBounds() {
        return (x >= 0 && y >= 0 && x < Constants::Map::MAP_SIZE && y < Constants::Map::MAP_SIZE);
    }

    sf::Vector2<int> coordinateToPosition(Coordinate c) {
        int scale = Constants::General::HITBOX_DIM;
        int x = c.x * scale + scale/2;
        int y = c.y * scale + scale/2;
        return sf::Vector2<int>(x, y);
    }

    Coordinate positionToCoordinate(sf::Vector2<int> c) {
        int scale = Constants::General::HITBOX_DIM;
        return Coordinate(c.x / scale, c.y / scale);
    }
    
}