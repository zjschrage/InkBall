#include <SFML/Graphics.hpp>
#include "coordinate.h"
#include "constants.h"

namespace InkBall::World {

    std::vector<Coordinate> Coordinate::getNeighborhood() {
        std::vector<Coordinate> coordinates;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                coordinates.push_back(Coordinate(x + i, y + j));
            }
        }
        return coordinates;
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