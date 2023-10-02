#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Entities {

    enum HitType {
        Lateral,
        TopBottom,
        Corner
    };

    class IInteractable {
    public:
        virtual void interact(Entity& entity) = 0;
        
        HitType isLateralHit(const sf::Vector2<int>& pA, const sf::Vector2<int>& pB) {
            int dx = abs(pA.x - pB.x);
            int dy = abs(pA.y - pB.y);
            if (dx == dy) return HitType::Corner;
            return (dx > dy) ? HitType::Lateral : HitType::TopBottom;
        }

    private:
    };
    
}