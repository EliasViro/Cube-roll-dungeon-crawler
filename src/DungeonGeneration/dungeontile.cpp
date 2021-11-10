#include "dungeontile.hpp"


//A class that is inherited by all tile types.


DungeonTile::DungeonTile(bool ispassable, TileType tiletype, unsigned int xcoord, unsigned int ycoord) 
    : ispassable_(ispassable), item_(nullptr), tiletype_(tiletype), hascharacter_(false), xcoord_(xcoord), ycoord_(ycoord) {}


bool DungeonTile::IsPassable() const {
    return ispassable_;
}

Item* DungeonTile::GetItem() const {
    return item_;
}

bool DungeonTile::HasCharacter() const {
    return hascharacter_;
}

unsigned int DungeonTile::GetXCoord() const {
    return xcoord_;
}

unsigned int DungeonTile::GetYCoord() const {
    return ycoord_;
}

bool DungeonTile::SetCharacter() {
    if (hascharacter_ == true) {
        return false;
    }
    else {
        hascharacter_ = true;
        ispassable_ = false;
        return true;
    }
}

void DungeonTile::RemoveCharacter() {
    hascharacter_ = false;
}

TileType DungeonTile::GetTileType() const {
    return tiletype_;
}