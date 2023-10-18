#include "inkPen.h"
#include "utils.h"
#include "constants.h"
#include <iostream>

namespace InkBall::InkLayer {

    InkPen::InkPen() {
        _penPoints = new sf::VertexArray();
    }

    void InkPen::penDown() {
        _penDown = true;
    }

    void InkPen::penUp() {
        _penDown = false;
    }

    bool InkPen::isPenDown() {
        return _penDown;
    }

    void InkPen::addPoint(const sf::Vertex& point) {
        size_t num = _penPoints->getVertexCount();
        auto last = (*_penPoints)[num-1];
        double dist = Utils::distance(last.position, point.position);
        std::cout << "Before" << std::endl;
        if (dist < Constants::HyperParameters::MIN_INK_SEGMENT_DISTANCE)
            return;
        std::cout << "After" << std::endl;
        _penPoints->append(point);
        std::cout << point.position.x << " " << point.position.y << std::endl;
    }

}