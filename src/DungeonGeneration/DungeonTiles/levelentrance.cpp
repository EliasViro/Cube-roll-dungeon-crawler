#include "levelentrance.hpp"

//A level entrance tile. Functions as a floor tile with the addition of being the specific tile
//the player character spawns on when arriving to a new level.

LevelEntrance::LevelEntrance(unsigned int xcoord, unsigned int ycoord)
    : DungeonTile(true, Entrance, xcoord, ycoord), item_(nullptr), hascharacter_(false) {}

void FloorTile::PlaceItem(Item* item) {
    item_ = item;
}