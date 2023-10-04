#pragma once

#include <vector>
#include "entity.h"
#include "coordinate.h"

namespace InkBall::World {

    class Tile {
    public:
        Tile(Coordinate c) : _coordinate(c), _permanentEntity(nullptr) {}
        Tile(Coordinate c, Entities::Entity* e) : _coordinate(c), _permanentEntity(e) {}
        Entities::Entity* getPermanentEntity();
        std::vector<Entities::Entity*>& getMovingEntities();
        void addMovingEntity(Entities::Entity* entity);
        void removeMovingEntity(Entities::Entity* entity);
        
    private:
        Entities::Entity* _permanentEntity;
        std::vector<Entities::Entity*> _movingEntities;
        Coordinate _coordinate;

    };

}