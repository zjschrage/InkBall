#include "wall.h"
#include "constants.h"

namespace InkBall::Entities {

    Wall::Wall(sf::Vector2<int> position) : Entity(position) {
        _texture.loadFromFile(Constants::SprtSheet::SPRITESHEET_PATH, Constants::SprtSheet::WHITE_TILE);
        _sprite.setTexture(_texture);
    }

}