#include <SFML/Graphics.hpp>
#include "constants.h"
#include "statics.h"
#include "ball.h"
#include "singleton.h"
#include "iState.h"
#include "stategame.h"

using namespace InkBall;

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "InkBall");
    window.setFramerateLimit(Constants::General::FPS);

    auto state = std::make_unique<State::GameState>();
    Singleton<State::IState>::set(std::move(state));

    while (window.isOpen()) {
        Singleton<State::IState>::get().handleEvents(window);
        Singleton<State::IState>::get().tick();
        Singleton<State::IState>::get().render(window);
    }

    return 0;
}