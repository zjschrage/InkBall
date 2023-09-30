#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Entities {

    class IInteractable {
    public:
        virtual void interact() = 0;

    private:
    };
    
}