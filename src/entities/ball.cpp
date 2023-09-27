#include "ball.h"
#include "constants.h"

namespace InkBall::Entities {

    Ball::Ball(sf::Vector2<int> position) : Entity(position) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, Constants::SprtSheet::WHITE_BALL);
        _sprite.setTexture(_texture);
    }

}