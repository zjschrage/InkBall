#include "coordinate.h"

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
    
}