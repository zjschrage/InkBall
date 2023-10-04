#include "tile.h"

namespace InkBall::World {
    
    Entities::Entity* Tile::getPermanentEntity() {
        return _permanentEntity;
    }

    std::vector<Entities::Entity*>& Tile::getMovingEntities() {
        return _movingEntities;
    }

    void Tile::addMovingEntity(Entities::Entity* entity) {
        _movingEntities.push_back(entity);
    }

    void Tile::removeMovingEntity(Entities::Entity* entity) {
        auto it = std::find(_movingEntities.begin(), _movingEntities.end(), entity);
        if (it != _movingEntities.end()) {
            _movingEntities.erase(it);
        }
    }

}