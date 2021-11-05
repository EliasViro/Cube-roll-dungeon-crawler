#include "floortile.hpp"


//A floor tile, represented by '*' in room files.
//Unpassable when there is a character standing on it.

FloorTile::FloorTile(unsigned int xcoord, unsigned int ycoord)
    : DungeonTile(true, Floor, xcoord, ycoord), item_(nullptr), hascharacter_(false) {}

void FloorTile::PlaceItem(Item* item) {
    item_ = item;
}