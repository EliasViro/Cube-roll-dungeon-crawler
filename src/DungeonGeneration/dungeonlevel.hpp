#include "dungeonroom.hpp"
#include <cstdlib>
#include <vector>
#include <random>
#include <utility>
#include <algorithm>

//Represents a level of the dungeon.
//A level consists of nine rooms connected by doors on a 3 x 3 grid.

enum Direction { Up , Down , Left , Right };

class DungeonLevel {
    public:
    DungeonLevel(int level, unsigned int depth); 

    void generateRooms();
    std::vector<Direction> dirsAvailable(std::pair<int, int> room);
    std::pair<int, int> RoomInDirection(std::pair<int, int> room, Direction direction);
    Direction opposite(Direction direction);
    std::pair<RoomType, DoorOrientation> roomOrient(std::vector<Direction> exits);
    int getLevel() const { return level_; }
    
    private:
    int level_; // side length of the map
    unsigned int depth_; // difficulty of the map
    std::vector<std::vector<DungeonRoom>> rooms_; // Two dimensional vector that stores the rooms.
};