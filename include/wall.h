#pragma once

#include "entity.h"

namespace InkBall::Entities {

    class Wall : public Entity {
    public:
        Wall(sf::Vector2<int> position);
    };

}