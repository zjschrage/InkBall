#pragma once

#include <vector>
#include "tile.h"

namespace InkBall::World {

    class Map {
    public:

    private:
        std::vector<std::vector<Tile>> _map;
    };

}