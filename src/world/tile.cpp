#include "tile.h"

namespace InkBall::World {
    
    bool Tile::hasEntity() {
        return _entity.has_value();
    }

    Entities::Entity* Tile::getEntity() {
        return _entity.value();
    }
    
}