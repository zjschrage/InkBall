#include "entity.h"
#include "constants.h"
#include "statics.h"

namespace InkBall::Entities {

    Entity::Entity(sf::Vector2<int> position) {
        int d = Constants::General::HITBOX_DIM;
        _position = position;
        _hitbox = sf::IntRect(position.x - d/2, position.y - d/2, d, d);
        _sprite.setPosition(position.x - d/2, position.y - d/2);
        _sprite.setScale(Constants::SprtSheet::SCALE, Constants::SprtSheet::SCALE);
    }

    void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(_sprite, states);
        if (Statics::SHOW_HITBOX) {
            auto hitboxOutline = sf::RectangleShape(sf::Vector2f(_hitbox.width, _hitbox.height));
            hitboxOutline.setPosition(_position.x - _hitbox.width/2, _position.y - _hitbox.width/2);
            hitboxOutline.setOutlineColor(sf::Color::Cyan);
            hitboxOutline.setOutlineThickness(2);
            hitboxOutline.setFillColor(sf::Color::Transparent);
            target.draw(hitboxOutline, states);
        }
        if (Statics::SHOW_CENTER) {
            int radius = 4;
            auto positionMarker = sf::CircleShape(radius, 8);
            positionMarker.setPosition(_position.x - radius, _position.y - radius);
            positionMarker.setOutlineColor(sf::Color::Magenta);
            positionMarker.setOutlineThickness(2);
            positionMarker.setFillColor(sf::Color::Transparent);
            target.draw(positionMarker, states);
        }
    }

}