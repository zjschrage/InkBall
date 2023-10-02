#include "wall.h"
#include "constants.h"
#include "iMobile.h"

namespace InkBall::Entities {

    Wall::Wall(sf::Vector2<int> position, Color color) : Entity(position, Constants::General::HITBOX_DIM) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, colorToSheetMapping(color));
        _sprite.setTexture(_texture);
    }

    void Wall::interact(Entity& entity) {
        IMobile* mobile = dynamic_cast<IMobile*>(&entity);
        if (mobile) {
            if (_hitbox.intersects(entity.getHitbox())) {
                auto velocity = mobile->getVelocity();
                HitType hitType = isLateralHit(_position, entity.getPosition());
                if (hitType == HitType::Lateral)
                    mobile->setVelocity(-velocity.x, velocity.y);
                else if (hitType == HitType::TopBottom)
                    mobile->setVelocity(velocity.x, -velocity.y);
                else
                    mobile->setVelocity(-velocity.x, -velocity.y);
            }
            while (_hitbox.intersects(entity.getHitbox())) {
                mobile->move();
            }
        }
    }

    sf::IntRect Wall::colorToSheetMapping(Color color) {
        switch (color) {
            case Color::WHITE:
                return Constants::SprtSheet::WHITE_TILE;
        }
    }

}