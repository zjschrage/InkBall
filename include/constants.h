#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Constants {

    namespace SprtSheet {
        constexpr const char* SPRITESHEET_PATH = "res/inkball_sprites.png";
        const int SCALE = 3;
        const int SS_TILE_SIZE = 24;
        const sf::IntRect WHITE_BALL = sf::IntRect(1, 375, SS_TILE_SIZE, SS_TILE_SIZE);
        const sf::IntRect WHITE_TILE = sf::IntRect(99, 1, SS_TILE_SIZE, SS_TILE_SIZE);
    }

    namespace General {
        const int FPS = 30;
        const int HITBOX_DIM = SprtSheet::SCALE * SprtSheet::SS_TILE_SIZE;
    }

}