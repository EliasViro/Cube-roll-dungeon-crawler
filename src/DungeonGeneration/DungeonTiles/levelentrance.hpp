#include "dungeontile.hpp"

//A level entrance tile. Functions as a floor tile with the addition of being the specific tile
//the player character spawns on when arriving to a new level.


class LevelEntrance : public DungeonTile {
    public:
    LevelEntrance(unsigned int xcoord, unsigned int ycoord);
}