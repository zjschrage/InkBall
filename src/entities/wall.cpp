#include "wall.h"
#include "constants.h"
#include "iMobile.h"

namespace InkBall::Entities {

    enum HitType {
        Lateral,
        TopBottom,
        Corner
    };

    static HitType isLateralHit(const sf::Vector2<int>& pA, const sf::Vector2<int>& pB);

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

    static HitType isLateralHit(const sf::Vector2<int>& pA, const sf::Vector2<int>& pB) {
        int dx = abs(pA.x - pB.x);
        int dy = abs(pA.y - pB.y);
        if (dx == dy) return HitType::Corner;
        return (dx > dy) ? HitType::Lateral : HitType::TopBottom;
    }

}