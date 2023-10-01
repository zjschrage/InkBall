#include "wall.h"
#include "constants.h"
#include "iMobile.h"

namespace InkBall::Entities {

    static bool isLateralHit(const sf::Vector2<int>& pA, const sf::Vector2<int>& pB);

    Wall::Wall(sf::Vector2<int> position, Color color) : Entity(position, Constants::General::HITBOX_DIM) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, colorToSheetMapping(color));
        _sprite.setTexture(_texture);
    }

    void Wall::interact(Entity& entity) {
        IMobile* mobile = dynamic_cast<IMobile*>(&entity);
        if (mobile) {
            if (_hitbox.intersects(entity.getHitbox())) {
                auto velocity = mobile->getVelocity();
                if (isLateralHit(_position, entity.getPosition()))
                    mobile->setVelocity(-velocity.x, velocity.y);
                else
                    mobile->setVelocity(velocity.x, -velocity.y);
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

    static bool isLateralHit(const sf::Vector2<int>& pA, const sf::Vector2<int>& pB) {
        return abs(pA.x - pB.x) > abs(pA.y - pB.y);
    }

}