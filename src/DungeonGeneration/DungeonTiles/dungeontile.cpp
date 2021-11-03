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


//WIP
DungeonTile* DungeonTile::GetTileInDirection(const char direction) {
    if (direction == 'N') {
        //Ask the Room class about the tile to the north.
        return this;
    }
    else if (direction == 'E') {
        //Ask the Room class about the tile to the east.
        return this;
    }
    else if (direction == 'S') {
        //Ask the Room class about the tile to the south.
        return this;
    }
    else {
        //Ask the Room class about the tile to the west.
        return this;
    }
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