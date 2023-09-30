#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Entities {

    class IMobile {
    public:
        
        virtual void move() = 0;
        virtual void recalculateHitbox() = 0;
        
        void setVelocity(sf::Vector2<int> velocity) {
            _velocity = velocity;
        }

        const sf::Vector2<int>& getVelocity() {
            return _velocity;
        }

    private:
        sf::Vector2<int> _velocity;
    };

}