#include "replay.h"
#include "constants.h"
#include <iostream>

#ifdef REPLAY_ON

namespace InkBall::Replay {

    bool ReplayControls::replay() {
        if (forwarder > 0) {
            forwarder--;
            return true;
        }
        return false;
    }

    void ReplayControls::handleEvents(sf::RenderWindow& window) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case ReplayKeys::FORWARD:
                        forwarder += 1;
                        break;
                    case ReplayKeys::FORWARD_5:
                        forwarder += 5;
                        break;
                    case ReplayKeys::FORWARD_50:
                        forwarder += 50;
                        break;
                    case ReplayKeys::STOP:
                        forwarder = 0;
                        break;
                    case ReplayKeys::FAST_FORWARD:
                        fastForwarding = !fastForwarding;
                        if (fastForwarding) window.setFramerateLimit(0);
                        else window.setFramerateLimit(Constants::General::FPS);
                        break;
                }
            }
        }
    }
}
#endif //REPLAY_ON