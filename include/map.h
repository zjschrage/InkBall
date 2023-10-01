#pragma once

#include <vector>
#include "tile.h"

namespace InkBall::World {

    typedef std::vector<std::vector<Tile*>> TileMap;

    class Map {
    public:
        Map() {
            _map = TileMap(17, std::vector<Tile*>(17, nullptr));
        }
        void setTile(int i, int j, Tile* tile) { _map[i][j] = tile; }
        void setMap(TileMap map) { _map = map; }
        const TileMap& getMap() { return _map; }

    private:
        TileMap _map;
    };

}