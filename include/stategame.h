#pragma once

#include "iState.h"
#include "ball.h"
#include "wall.h"
#include "map.h"
#include "inkLayer.h"
#include "inkPen.h"

namespace InkBall::State {
    class GameState : public IState {
    public:
        void init() override;
        void tick() override;
        void render(sf::RenderWindow& window) override;
        void handleEvents(sf::RenderWindow& window) override;

    private:
        World::Coordinate tickBalls(Entities::Ball& ball);
        void tickNeighborInteractions(Entities::Ball& ball, World::Coordinate& coordinate);

    private:
        World::Map _map;
        std::vector<Entities::Ball*> _balls;
        InkLayer::InkLayer _inkLayer;
        InkLayer::InkPen _inkPen;
    };
}