#pragma once

#include "iState.h"
#include "ball.h"
#include "wall.h"

namespace InkBall::State {
    class GameState : public IState {
    public:
        void init() override;
        void tick() override;
        void render(sf::RenderWindow& window) override;
        void handleEvents(sf::RenderWindow& window) override;

    private:
        Entities::Ball* _ball;
        std::vector<Entities::Wall*> _walls;
    };
}