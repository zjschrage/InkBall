#include "stategame.h"
#include "statics.h"
#include "levelLoader.h"
#include "iInteractable.h"

namespace InkBall::State {

    void GameState::init() {
        auto ball0 = new Entities::Ball(sf::Vector2(500, 500));
        ball0->setVelocity(sf::Vector2(-3, 3));

        auto ball1 = new Entities::Ball(sf::Vector2(400, 300));
        ball1->setVelocity(sf::Vector2(4, -3));

        auto ball3 = new Entities::Ball(sf::Vector2(450, 200));
        ball3->setVelocity(sf::Vector2(-2, -5));

        _balls.push_back(ball0);
        _balls.push_back(ball1);
        _balls.push_back(ball3);

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
        for (auto* ball : _balls) {
            World::Coordinate oldPosition = World::positionToCoordinate(ball->getPosition());
            ball->move();
            World::Coordinate newPosition = World::positionToCoordinate(ball->getPosition());
            if (oldPosition != newPosition) {
                _map.getMap()[oldPosition.x][oldPosition.y]->removeMovingEntity(ball);
                _map.getMap()[newPosition.x][newPosition.y]->addMovingEntity(ball);
            }
            for (auto cord : newPosition.getNeighborhood()) {
                if (_map.getMap()[cord.x][cord.y]->getPermanentEntity()) {
                    Entities::IInteractable* interactable = dynamic_cast<Entities::IInteractable*>(_map.getMap()[cord.x][cord.y]->getPermanentEntity());
                    if (interactable) {
                        interactable->interact(*ball);
                    }
                }
                for (auto movingEntity : _map.getMap()[cord.x][cord.y]->getMovingEntities()) {
                    Entities::IInteractable* interactable = dynamic_cast<Entities::IInteractable*>(movingEntity);
                    if (interactable) {
                        interactable->interact(*ball);
                    }
                }
            }
        }
    }

    void GameState::render(sf::RenderWindow& window) {
        window.clear();
        for (auto ball : _balls) {
            window.draw(*ball);
        }
        for (auto tileRow : _map.getMap()) {
            for (auto tile : tileRow) {
                if (tile->getPermanentEntity() != nullptr) {
                    window.draw(*tile->getPermanentEntity());
                }
            }
        }
        window.display();
    }
}