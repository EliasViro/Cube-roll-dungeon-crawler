#include "dungeontile.hpp"


//A floor tile, represented by '*' in room files.
//Unpassable when there is a character standing on it.

class FloorTile : public DungeonTile {
    public:
    FloorTile(unsigned int xcoord, unsigned int ycoord);
}
