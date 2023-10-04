#pragma once

#include <vector>
#include "tile.h"
#include "constants.h"

namespace InkBall::World {

    typedef std::vector<std::vector<Tile*>> TileMap;

    class Map {
    public:
        Map() {
            _map = TileMap(Constants::Map::MAP_SIZE, std::vector<Tile*>(Constants::Map::MAP_SIZE, nullptr));
        }
        void setTile(int i, int j, Tile* tile) { _map[i][j] = tile; }
        const TileMap& getMap() { return _map; }

    private:
        TileMap _map;
    };

}