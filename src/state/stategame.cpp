#include "stategame.h"
#include "statics.h"
#include "levelLoader.h"
#include "iInteractable.h"
#include "utils.h"

#include <queue>

namespace InkBall::State {

    void GameState::init() {
        auto ball0 = new Entities::Ball(sf::Vector2(500, 500), Entities::Color::WHITE);
        ball0->setVelocity(sf::Vector2(-3, 3));

        auto ball1 = new Entities::Ball(sf::Vector2(400, 300), Entities::Color::ORANGE);
        ball1->setVelocity(sf::Vector2(4, -3));

        auto ball2 = new Entities::Ball(sf::Vector2(450, 200), Entities::Color::BLUE);
        ball2->setVelocity(sf::Vector2(-2, -5));

        auto ball3 = new Entities::Ball(sf::Vector2(200, 200), Entities::Color::GREEN);
        ball3->setVelocity(sf::Vector2(2, 3));

        auto ball4 = new Entities::Ball(sf::Vector2(250, 200), Entities::Color::YELLOW);
        ball4->setVelocity(sf::Vector2(-2, 3));

        _balls.push_back(ball0);
        _balls.push_back(ball1);
        _balls.push_back(ball2);
        _balls.push_back(ball3);
        _balls.push_back(ball4);

        _map = World::LevelLoader::loadLevel(1);
        _inkPen = InkLayer::InkPen();

    }

    void GameState::handleEvents(sf::RenderWindow& window) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case Constants::Keys::SHOW_HITBOX:
                        Statics::SHOW_HITBOX = !Statics::SHOW_HITBOX;
                        break;
                    case Constants::Keys::SHOW_CENTER:
                        Statics::SHOW_CENTER = !Statics::SHOW_CENTER;
                        break;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                switch (event.key.code) {
                    case sf::Mouse::Left:
                        _inkPen.penDown();
                        break;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                switch (event.key.code) {
                    case sf::Mouse::Left:
                        _inkPen.penUp();
                        break;
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                if (_inkPen.isPenDown()) {
                    auto v = sf::Vertex(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                    _inkPen.addPoint(v);
                    //std::cout << event.mouseMove.x << " " << event.mouseMove.y << std::endl;
                }
            }
        }
    }

    void GameState::tick() {
        for (auto ball : _balls) {
            auto coordinate = tickBalls(*ball);
            tickNeighborInteractions(*ball, coordinate);
        }
    }

    World::Coordinate GameState::tickBalls(Entities::Ball& ball) {
        auto oldCoordinate = World::positionToCoordinate(ball.getPosition());
        ball.move();
        auto newCoordinate = World::positionToCoordinate(ball.getPosition());
        if (oldCoordinate != newCoordinate) {
            _map.getMap()[oldCoordinate.x][oldCoordinate.y]->removeMovingEntity(&ball);
            _map.getMap()[newCoordinate.x][newCoordinate.y]->addMovingEntity(&ball);
        }
        return newCoordinate;
    }

    void GameState::tickNeighborInteractions(Entities::Ball& ball, World::Coordinate& coordinate) {
        auto cmp = [&ball](World::Coordinate a, World::Coordinate b){
            double d1 = Utils::distance(World::coordinateToPosition(a), ball.getPosition());
            double d2 = Utils::distance(World::coordinateToPosition(b), ball.getPosition());
            return d1 > d2;
        };
        std::priority_queue<World::Coordinate, std::vector<World::Coordinate>, decltype(cmp)> neighborhood(cmp);
        for (auto cord : coordinate.getNeighborhood()) {
            neighborhood.push(cord);
        }

        while (!neighborhood.empty()) {
            auto cord = neighborhood.top();
            neighborhood.pop();
            auto* permanentEntity = _map.getMap()[cord.x][cord.y]->getPermanentEntity();
            if (permanentEntity) {
                auto* interactable = dynamic_cast<Entities::IInteractable*>(permanentEntity);
                if (interactable) {
                    interactable->interact(ball);
                }
            }
            for (auto movingEntity : _map.getMap()[cord.x][cord.y]->getMovingEntities()) {
                auto* interactable = dynamic_cast<Entities::IInteractable*>(movingEntity);
                if (interactable) {
                    interactable->interact(ball);
                }
            }
        }
    }

    void GameState::render(sf::RenderWindow& window) {
        window.clear();
        for (auto tileRow : _map.getMap()) {
            for (auto tile : tileRow) {
                if (tile->getPermanentEntity() != nullptr) {
                    window.draw(*tile->getPermanentEntity());
                }
            }
        }
        for (auto ball : _balls) {
            window.draw(*ball);
        }
        window.display();
    }
}