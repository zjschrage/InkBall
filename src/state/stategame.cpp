#include "stategame.h"
#include "statics.h"
#include "levelLoader.h"
#include "iInteractable.h"
#include "utils.h"

#include <queue>

namespace InkBall::State {

    int cont = 0;

    void GameState::init() {
        auto ball0 = new Entities::Ball(sf::Vector2(500, 500));
        ball0->setVelocity(sf::Vector2(-3, 3));

        auto ball1 = new Entities::Ball(sf::Vector2(400, 300));
        ball1->setVelocity(sf::Vector2(4, -3));

        auto ball2 = new Entities::Ball(sf::Vector2(450, 200));
        ball2->setVelocity(sf::Vector2(-2, -5));

        auto ball3 = new Entities::Ball(sf::Vector2(200, 200));
        ball3->setVelocity(sf::Vector2(2, 3));

        auto ball4 = new Entities::Ball(sf::Vector2(250, 200));
        ball4->setVelocity(sf::Vector2(-2, 3));

        _balls.push_back(ball0);
        _balls.push_back(ball1);
        _balls.push_back(ball2);
        _balls.push_back(ball3);
        _balls.push_back(ball4);

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
                    case sf::Keyboard::Space:
                        cont += 1;
                        break;
                    case sf::Keyboard::X:
                        cont += 5;
                        break;
                    case sf::Keyboard::Z:
                        cont += 50;
                        break;
                }
            }
        }
    }

    void GameState::tick() {
        if (!cont)
            return;
        cont--;
        for (auto* ball : _balls) {
            World::Coordinate oldCoordinate = World::positionToCoordinate(ball->getPosition());
            ball->move();
            World::Coordinate newCoordinate = World::positionToCoordinate(ball->getPosition());
            if (oldCoordinate != newCoordinate) {
                _map.getMap()[oldCoordinate.x][oldCoordinate.y]->removeMovingEntity(ball);
                _map.getMap()[newCoordinate.x][newCoordinate.y]->addMovingEntity(ball);
            }
            auto cmp = [&ball](World::Coordinate a, World::Coordinate b){
                double d1 = Utils::distance(World::coordinateToPosition(a), ball->getPosition());
                double d2 = Utils::distance(World::coordinateToPosition(b), ball->getPosition());
                return d1 > d2;
            };
            std::priority_queue<World::Coordinate, std::vector<World::Coordinate>, decltype(cmp)> neighborhood(cmp);
            for (auto cord : newCoordinate.getNeighborhood()) {
                neighborhood.push(cord);
            }

            while (!neighborhood.empty()) {
                World::Coordinate cord = neighborhood.top();
                neighborhood.pop();
                Entities::Entity* permanentEntity = _map.getMap()[cord.x][cord.y]->getPermanentEntity();
                if (permanentEntity) {
                    Entities::IInteractable* interactable = dynamic_cast<Entities::IInteractable*>(permanentEntity);
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