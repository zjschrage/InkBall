#include "ball.h"
#include "constants.h"
#include "iMobile.h"

namespace InkBall::Entities {

    Ball::Ball(sf::Vector2<int> position) : Entity(position, Constants::General::BALL_HITBOX_DIM) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, Constants::SprtSheet::WHITE_BALL);
        _sprite.setTexture(_texture);
    }

    void Ball::move() {
        _position.x += getVelocity().x;
        _position.y += getVelocity().y;
        recalculateHitbox();
    }

    void Ball::recalculateHitbox() {
        int d = Constants::General::BALL_HITBOX_DIM;
        _hitbox = sf::IntRect(_position.x - d/2, _position.y - d/2, d, d);
        _sprite.setPosition(_position.x - d/2, _position.y - d/2);
    }

    void Ball::interact(Entity& entity) {
        IMobile* mobile = dynamic_cast<IMobile*>(&entity);
        if (mobile) {
            if (_hitbox.intersects(entity.getHitbox())) {
                auto velocity = mobile->getVelocity();
                HitType hitType = isLateralHit(_position, entity.getPosition());
                if (hitType == HitType::Lateral) {
                    mobile->setVelocity(-velocity.x, velocity.y);
                    this->setVelocity(-velocity.x, velocity.y);
                }
                else if (hitType == HitType::TopBottom) {
                    mobile->setVelocity(velocity.x, -velocity.y);
                    this->setVelocity(velocity.x, -velocity.y);
                }
                else {
                    mobile->setVelocity(-velocity.x, -velocity.y);
                    this->setVelocity(-velocity.x, -velocity.y);
                }
            }
            while (_hitbox.intersects(entity.getHitbox())) {
                mobile->move();
            }
        }
    }

}