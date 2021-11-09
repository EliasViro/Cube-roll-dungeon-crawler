#include "loottile.hpp"


//Functions as a regular floor tile with the addition of being able to spawn loot on it when requested.


LootTile::LootTile(unsigned int xcoord, unsigned int ycoord)
    : DungeonTile(true, Loot, xcoord, ycoord), item_(nullptr), hascharacter_(false) {}

void FloorTile::PlaceItem(Item* item) {
    item_ = item;
}