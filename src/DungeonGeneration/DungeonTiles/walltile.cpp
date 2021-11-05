#include "walltile.hpp"


//A wall tile, represented by '#' in room files.
//Unpassable and prevents ranged attacks through it.

WallTile::WallTile(unsigned int xcoord, unsigned int ycoord)
    : DungeonTile(false, Wall, xcoord, ycoord), item_(nullptr), hascharacter_(false) {}