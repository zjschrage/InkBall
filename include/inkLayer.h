#pragma once

#include <SFML/Graphics.hpp>

namespace InkBall::InkLayer {
    
    class InkLayer {
    public:
        std::vector<sf::VertexArray*> getInkLines();
        void addInkLine(sf::VertexArray* inkLine);
        void removeInkLine(sf::VertexArray* inkLine);
    private:
        std::vector<sf::VertexArray*> _inkLines;
    };

}