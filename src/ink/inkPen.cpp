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

    void InkPen::addPoint(sf::Vertex point) {
        size_t num = _penPoints->getVertexCount();
        if (num != 0) {
            auto last = (*_penPoints)[num-1];
            double dist = Utils::distance(last.position, point.position);
            if (dist < Constants::HyperParameters::MIN_INK_SEGMENT_DISTANCE)
                return;
        }
        _penPoints->append(point);
        std::cout << point.position.x << " " << point.position.y << std::endl;
    }

}