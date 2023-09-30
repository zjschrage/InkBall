#pragma once

#include "iState.h"
#include "ball.h"

namespace InkBall::State {
    class GameState : public IState {
    public:
        GameState() { init(); }
        void init() override;
        void tick() override;
        void render(sf::RenderWindow& window) override;
        void handleEvents(sf::RenderWindow& window) override;

    private:
        Entities::Ball* _ball;
    };
}