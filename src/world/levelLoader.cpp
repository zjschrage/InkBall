#include "levelLoader.h"
#include "constants.h"
#include "wall.h"
#include "coordinate.h"

namespace InkBall::World {

    static std::string getLevelFile(int level);
    static void processLine(Map& map, const std::string& line, int row);
    static Tile* charToTile(Coordinate cord, char c);

    Map LevelLoader::loadLevel(int level) {
        int row = 0;
        Map map;
        std::string line;
        std::ifstream myfile (getLevelFile(level));
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                processLine(map, line, row++);
            }
            myfile.close();
        }
        return map;
    }

    static std::string getLevelFile(int level) {
        std::string path = Constants::Map::WORLDMAP_PATH;
        path += "level_";
        path += std::to_string(level);
        path += ".txt";
        return path;
    }

    static void processLine(Map& map, const std::string& line, int row) {
        for(int i = 0; i < Constants::Map::MAP_SIZE; i++) {
            map.setTile(row, i, charToTile(Coordinate(row, i), line[i]));
        }
    }

    static Tile* charToTile(Coordinate cord, char c) {
        switch (c) {
            case 'X':
                return new Tile(cord, new Entities::Wall(coordinateToPosition(cord)));
            case '0':
            default:
                return new Tile(cord);
        }
    }

}