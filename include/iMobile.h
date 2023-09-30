#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Entities {

    class IMobile {
    public:
        
        virtual void move() = 0;
        
        void setVelocity(const sf::Vector2<int>& velocity) {
            _velocity = velocity;
        }

        void setVelocity(int x, int y) {
            _velocity.x = x;
            _velocity.y = y;
        }

        const sf::Vector2<int>& getVelocity() {
            return _velocity;
        }

    private:
        sf::Vector2<int> _velocity;
    };

}