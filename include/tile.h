#pragma once

#include <vector>
#include <optional>
#include "entity.h"
#include "coordinate.h"

namespace InkBall::World {

    class Tile {
    public:
        Tile();
        
    private:
        std::optional<Entities::Entity> _entity;
        Coordinate _coordinate;

    };

}