#include "inkLayer.h"

namespace InkBall::InkLayer {
    
    std::vector<sf::VertexArray*> InkLayer::getInkLines() {
        return _inkLines;
    }

    void InkLayer::addInkLine(sf::VertexArray* inkLine) {
        _inkLines.push_back(inkLine);
    }

    void InkLayer::removeInkLine(sf::VertexArray* inkLine) {
        auto it = std::find(_inkLines.begin(), _inkLines.end(), inkLine);
        if (it != _inkLines.end())
            _inkLines.erase(it);
    }
}