#pragma once

#include <optional>
#include <SFML/Graphics.hpp>

namespace InkBall::InkLayer {

    class InkPen {
    public:
        InkPen();
        void penDown();
        void penUp();
        bool isPenDown();
        void addPoint(sf::Vertex point);

    private:
        bool _penDown = false;
        sf::VertexArray* _penPoints = nullptr;
    };

}