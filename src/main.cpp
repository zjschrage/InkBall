#include <SFML/Graphics.hpp>
#include "constants.h"
#include "ball.h"

using namespace InkBall;

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "InkBall");
    window.setFramerateLimit(Constants::General::FPS);

    Entities::Entity* ball = new Entities::Ball(sf::Vector2(500, 500));

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(*ball);
        window.display();
    }

    return 0;
}