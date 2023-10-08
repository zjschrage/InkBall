#include <SFML/Graphics.hpp>
#include "constants.h"
#include "statics.h"
#include "ball.h"
#include "singleton.h"
#include "iState.h"
#include "stategame.h"
#include "replay.h"

using namespace InkBall;

int main() {

    sf::RenderWindow window(sf::VideoMode(Constants::General::WINDOW_SIZE, Constants::General::WINDOW_SIZE), Constants::General::WINDOW_TITLE);
    window.setFramerateLimit(Constants::General::FPS);

    auto state = std::make_unique<State::GameState>();
    Singleton<State::IState>::set(std::move(state));
    Singleton<State::IState>::get().init();

    #ifdef REPLAY_ON
    Replay::ReplayControls replayControls;
    #endif
    
    while (window.isOpen()) {
        #ifdef REPLAY_ON
        replayControls.handleEvents(window);
        if (!replayControls.replay()) continue;
        #endif
        Singleton<State::IState>::get().handleEvents(window);
        Singleton<State::IState>::get().tick();
        Singleton<State::IState>::get().render(window);
    }

    return 0;
}