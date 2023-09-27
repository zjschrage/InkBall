#include "entity.h"
#include "constants.h"

namespace InkBall::Entities {

    Entity::Entity(sf::Vector2<int> position) {
        _postion = position;
        int d = Constants::General::HITBOX_DIM;
        _hitbox = sf::IntRect(position.x - d/2, position.y - d/2, d, d);
        _velocity = sf::Vector2(0, 0);
    }

    void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(_sprite, states);
    }

}