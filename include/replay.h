#pragma once

#include <SFML/Graphics.hpp>

#ifdef REPLAY_ON

namespace ReplayKeys {
    const int FAST_FORWARD = sf::Keyboard::Q;
    const int FORWARD_50 = sf::Keyboard::Z;
    const int FORWARD_5 = sf::Keyboard::X;
    const int FORWARD = sf::Keyboard::Space;
    const int STOP = sf::Keyboard::Slash;
}

namespace InkBall::Replay {
    
    class ReplayControls {
    public:
        void handleEvents(sf::RenderWindow& window);
        bool replay();
    private:
        int forwarder = 1;
        bool fastForwarding = false;
    };
}
#endif //REPLAY_ON