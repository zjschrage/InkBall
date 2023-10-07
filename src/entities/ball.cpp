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
        if (this == &entity)
            return;
        IMobile* mobile = dynamic_cast<IMobile*>(&entity);
        if (mobile) {
            if (_hitbox.intersects(entity.getHitbox())) {
                auto otherVelocity = mobile->getVelocity();
                auto myVelocity = this->getVelocity();
                // HitType hitType = isLateralHit(_position, entity.getPosition());
                // if (hitType == HitType::Lateral) {
                //     mobile->setVelocity(-otherVelocity.x, otherVelocity.y);
                //     this->setVelocity(-myVelocity.x, myVelocity.y);
                // }
                // else if (hitType == HitType::TopBottom) {
                //     mobile->setVelocity(otherVelocity.x, -otherVelocity.y);
                //     this->setVelocity(myVelocity.x, -myVelocity.y);
                // }
                // else {
                //     mobile->setVelocity(-otherVelocity.x, -otherVelocity.y);
                //     this->setVelocity(-myVelocity.x, -myVelocity.y);
                // }
                auto epicenter = (this->getPosition() + entity.getPosition())/2;
                auto c1 = epicenter - myVelocity;
                auto c2 = epicenter - otherVelocity;
                auto precenter = (c1 + c2)/2;
                auto tangentOfCollision = 2 * (epicenter - precenter);
                auto d1 = c1 + tangentOfCollision;
                auto d2 = c2 + tangentOfCollision;
                // std::cout << "old vec 1: " << myVelocity.x << " " << myVelocity.y << std::endl;
                // std::cout << "old vec 2: " << otherVelocity.x << " " << otherVelocity.y << std::endl;
                // std::cout << "epicenter: " << epicenter.x << " " << epicenter.y << std::endl;
                // std::cout << "c1: " << c1.x << " " << c1.y << std::endl;
                // std::cout << "c2: " << c2.x << " " << c2.y << std::endl;
                // std::cout << "precenter: " << precenter.x << " " << precenter.y << std::endl;
                // std::cout << "tangentOfCollision: " << tangentOfCollision.x << " " << tangentOfCollision.y << std::endl;
                // std::cout << "d1: " << d1.x << " " << d1.y << std::endl;
                // std::cout << "d2: " << d2.x << " " << d2.y << std::endl;
                // std::cout << "new vec 1: " << (d1 - epicenter).x << " " << (d1 - epicenter).y << std::endl;
                // std::cout << "new vec 2: " << (d2 - epicenter).x << " " << (d2 - epicenter).y << std::endl;
                this->setVelocity(d1 - epicenter);
                mobile->setVelocity(d2 - epicenter);
            }
            while (_hitbox.intersects(entity.getHitbox())) {
                this->move();
                mobile->move();
            }
        }
    }

}