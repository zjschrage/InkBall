#pragma once

#include "entity.h"

namespace InkBall::Entities {

    class Ball : public Entity {
    public:
        Ball(sf::Vector2<int> position);
    };

}