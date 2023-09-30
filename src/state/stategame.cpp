#include "stategame.h"
#include "statics.h"
#include "ball.h"

namespace InkBall::State {

    void GameState::init() {
        _ball = new Entities::Ball(sf::Vector2(500, 500));
        _ball->setVelocity(sf::Vector2(-2, 2));

        auto* wall1 = new Entities::Wall(sf::Vector2(300, 700));
        auto* wall2 = new Entities::Wall(sf::Vector2(700, 300));
        _walls.push_back(wall1);
        _walls.push_back(wall2);
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
        for (auto* wall : _walls) {
            wall->interact(*_ball);
        }
    }

    void GameState::render(sf::RenderWindow& window) {
        window.clear();
        window.draw(*_ball);
        for (auto& wall : _walls) {
            window.draw(*wall);
        }
        window.display();
    }
}