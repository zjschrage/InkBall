#include <SFML/Graphics.hpp>
#include "constants.h"
#include "ball.h"

using namespace InkBall;

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "InkBall");
    window.setFramerateLimit(Constants::General::FPS);

    Entities::Entity* ball = new Entities::Ball(sf::Vector2(500, 500));
    ball->setVelocity(sf::Vector2(-2, 2));

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::F3:
                        //Statics::SHOW_HITBOX = !Statics::SHOW_HITBOX;
                        break;
                    case sf::Keyboard::F4:
                        //Statics::SHOW_CENTER = !Statics::SHOW_CENTER;
                        break;
                }
            }
        }

        ball->move();

        window.clear();
        window.draw(*ball);
        window.display();
    }

    return 0;
}