#pragma once

#include "entity.h"
#include "iMobile.h"

namespace InkBall::Entities {

    class Ball : public Entity, public IMobile {
    public:
        Ball(sf::Vector2<int> position);
        void move() override;
    private:
        void recalculateHitbox();
    };

}