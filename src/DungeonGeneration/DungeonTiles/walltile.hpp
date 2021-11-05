#include "dungeontile.hpp"


//A wall tile, represented by '#' in room files.
//Unpassable and prevents ranged attacks through it. 

class WallTile : public DungeonTile {
    public:
    WallTile(unsigned int xcoord, unsigned int ycoord);
}