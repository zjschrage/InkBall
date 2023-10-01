#pragma once

#include <fstream>
#include "map.h"

namespace InkBall::World {

    class LevelLoader {
    public:
        static Map loadLevel(int level);
    };
    
}