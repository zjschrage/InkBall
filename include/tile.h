#pragma once

#include <vector>
#include <optional>
#include "entity.h"
#include "coordinate.h"

namespace InkBall::World {

    class Tile {
    public:
        Tile(Coordinate c) : _coordinate(c), _entity(std::nullopt) {}
        Tile(Coordinate c, Entities::Entity* e) : _coordinate(c), _entity(e) {}
        bool hasEntity();
        Entities::Entity* getEntity();
        
    private:
        std::optional<Entities::Entity*> _entity;
        Coordinate _coordinate;

    };

}