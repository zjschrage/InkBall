#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Entities {

    class IInteractable {
    public:
        virtual void interact(Entity& entity) = 0;

    private:
    };
    
}