#pragma once

#include "entity.h"
#include "iMobile.h"
#include "iInteractable.h"

namespace InkBall::Entities {

    class Ball : public Entity, public IMobile, public IInteractable {
    public:
        Ball(sf::Vector2<int> position);
        void move() override;
        void interact(Entity& entity) override;

    private:
        void recalculateHitbox();
    };

}