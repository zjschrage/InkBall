#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace InkBall::Entities {

    class Entity : public sf::Drawable {
    public:
        Entity(sf::Vector2<int> position);
        void move();
        void setVelocity(sf::Vector2<int> velocity);

    protected:
        sf::Vector2<int> _position;
        sf::Vector2<int> _velocity;
        sf::IntRect _hitbox;
        sf::Texture _texture;
        sf::Sprite _sprite;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void recalculateHitbox();

    };

}