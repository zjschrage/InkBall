#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::State {

    class IState {
    public:
        virtual void init() = 0;
        virtual void tick() = 0;
        virtual void render(sf::RenderWindow& window) = 0;
        virtual void handleEvents(sf::RenderWindow& window) = 0;
    };
}