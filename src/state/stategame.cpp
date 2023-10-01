#include "stategame.h"
#include "statics.h"
#include "levelLoader.h"
#include "iInteractable.h"

namespace InkBall::State {

    void GameState::init() {
        _ball = new Entities::Ball(sf::Vector2(500, 500));
        _ball->setVelocity(sf::Vector2(-3, 3));

        _map = World::LevelLoader::loadLevel(0);

    }

    void GameState::handleEvents(sf::RenderWindow& window) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::F3:
                        Statics::SHOW_HITBOX = !Statics::SHOW_HITBOX;
                        break;
                    case sf::Keyboard::F4:
                        Statics::SHOW_CENTER = !Statics::SHOW_CENTER;
                        break;
                }
            }
        }
    }

    void GameState::tick() {
        _ball->move();
        for (auto tileRow : _map.getMap()) {
            for (auto tile : tileRow) {
                if (tile->hasEntity()) {
                    Entities::IInteractable* interactable = dynamic_cast<Entities::IInteractable*>(tile->getEntity());
                    if (interactable) {
                        interactable->interact(*_ball);
                    }
                }
            }
        }
    }

    void GameState::render(sf::RenderWindow& window) {
        window.clear();
        window.draw(*_ball);
        for (auto tileRow : _map.getMap()) {
            for (auto tile : tileRow) {
                if (tile->hasEntity()) {
                    window.draw(*tile->getEntity());
                }
            }
        }
        window.display();
    }
}