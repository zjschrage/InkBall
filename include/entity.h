#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace InkBall::Entities {

    class Entity : public sf::Drawable {
    public:
        Entity(sf::Vector2<int> position);
        const sf::Vector2<int>& getPosition() { return _position; }
        const sf::IntRect& getHitbox() { return _hitbox; }

    protected:
        sf::Vector2<int> _position;
        sf::IntRect _hitbox;
        sf::Texture _texture;
        sf::Sprite _sprite;

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    };

}