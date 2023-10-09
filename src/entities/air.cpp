#include "air.h"
#include "constants.h"

namespace InkBall::Entities {

    Air::Air(sf::Vector2<int> position) : Entity(position, Constants::General::HITBOX_DIM) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, Constants::SprtSheet::EMPTY_TILE);
        _sprite.setTexture(_texture);
    }
}