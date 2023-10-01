#include "wall.h"
#include "constants.h"
#include "iMobile.h"

namespace InkBall::Entities {

    Wall::Wall(sf::Vector2<int> position) : Entity(position, Constants::General::HITBOX_DIM) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, Constants::SprtSheet::WHITE_TILE);
        _sprite.setTexture(_texture);
    }

    void Wall::interact(Entity& entity) {
        IMobile* mobile = dynamic_cast<IMobile*>(&entity);
        if (mobile) {
            if (_hitbox.intersects(entity.getHitbox())) {
                auto velocity = mobile->getVelocity();
                mobile->setVelocity(-velocity.x, -velocity.y);
            }
            while (_hitbox.intersects(entity.getHitbox())) {
                mobile->move();
            }
        }
    }

}