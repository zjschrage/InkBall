#pragma once

#include "entity.h"
#include "iInteractable.h"

namespace InkBall::Entities {

    class Wall : public Entity, public IInteractable {
    public:
        Wall(sf::Vector2<int> position);
        void interact(Entity& entity) override;
    };

}