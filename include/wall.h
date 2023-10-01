#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "iInteractable.h"

namespace InkBall::Entities {

    class Wall : public Entity, public IInteractable {
    public:
        Wall(sf::Vector2<int> position, Color color);
        void interact(Entity& entity) override;

    private:
        sf::IntRect colorToSheetMapping(Color color);
    };

}