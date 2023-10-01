#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::Constants {

    namespace SprtSheet {
        constexpr const char* SPRITESHEET_PATH = "res/spritesheets/inkball_sprites.png";
        const int SCALE = 2;
        const int BALL_TILE_SIZE = 24;
        const int TILE_SIZE = 32;
        const sf::IntRect WHITE_BALL = sf::IntRect(1, 375, BALL_TILE_SIZE, BALL_TILE_SIZE);
        const sf::IntRect WHITE_TILE = sf::IntRect(99, 1, TILE_SIZE, TILE_SIZE);
        const sf::IntRect EMPTY_TILE = sf::IntRect(1, 1, TILE_SIZE, TILE_SIZE);
        const sf::IntRect DISPENSER_TILE = sf::IntRect(1, 33, TILE_SIZE, TILE_SIZE);
    }

    namespace Map {
        constexpr const char* WORLDMAP_PATH = "res/worldmaps/";
        const int MAP_SIZE = 17;
    }

    namespace General {
        constexpr const char* WINDOW_TITLE = "Inkball";
        const int WINDOW_SIZE = Map::MAP_SIZE * SprtSheet::TILE_SIZE * SprtSheet::SCALE;
        const int FPS = 30;
        const int BALL_HITBOX_DIM = SprtSheet::SCALE * SprtSheet::BALL_TILE_SIZE;
        const int HITBOX_DIM = SprtSheet::SCALE * SprtSheet::TILE_SIZE;
    }

}