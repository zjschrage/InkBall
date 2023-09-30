#include "stategame.h"
#include "statics.h"
#include "ball.h"

namespace InkBall::State {

    void GameState::init() {
        _ball = new Entities::Ball(sf::Vector2(500, 500));
        _ball->setVelocity(sf::Vector2(-2, 2));

        auto wall = new Entities::Wall(sf::Vector2(300, 700));
        _wall = wall;
        std::cout << "Init()" << " " << _wall << std::endl;
        //_walls.push_back(wall);
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
         std::cout << "Handled Events" << std::endl;
    }

    void GameState::tick() {
        _ball->move();
        std::cout << _wall << std::endl;
        _wall->interact(*_ball);
    }

    void GameState::render(sf::RenderWindow& window) {
        window.clear();
        window.draw(*_ball);
        window.draw(*_wall);
        window.display();
    }
}